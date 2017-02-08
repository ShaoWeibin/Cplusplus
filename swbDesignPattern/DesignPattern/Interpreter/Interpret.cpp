#include "Interpret.h"
#include <iostream>

AbstractExpression::AbstractExpression()
{
}


AbstractExpression::~AbstractExpression()
{
}

void AbstractExpression::Interpret(const SwbContext& c)
{

}

TerminalExpression::TerminalExpression(const string& statement)
: _statement(statement)
{

}

TerminalExpression::~TerminalExpression()
{

}

void TerminalExpression::Interpret(const SwbContext& c)
{
	cout << "TerminalExpression: " << _statement << endl;
}

NonterminalExpression::NonterminalExpression(AbstractExpression*	exp, int times)
: _expression(exp), _times(times)
{

}

NonterminalExpression::~NonterminalExpression()
{

}

void NonterminalExpression::Interpret(const SwbContext& c)
{
	for (int i = 0; i < _times; ++i)
		_expression->Interpret(c);
}