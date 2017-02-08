#ifndef _INTERPRET_H_
#define _INTERPRET_H_

#include "SwbContext.h"
#include <string>
using namespace std;

class AbstractExpression
{
public:
	
	virtual ~AbstractExpression();

	virtual void Interpret(const SwbContext& c);

protected:
	AbstractExpression();
};

class TerminalExpression : public AbstractExpression
{
public:
	TerminalExpression(const string& statement);
	~TerminalExpression();

	void Interpret(const SwbContext& c);

private:
	string _statement;
};

class NonterminalExpression : public AbstractExpression
{
public:
	NonterminalExpression(AbstractExpression*	exp, int times);
	~NonterminalExpression();

	void Interpret(const SwbContext& c);

private:
	AbstractExpression* _expression;
	int _times;
};

#endif  // _INTERPRET_H_
