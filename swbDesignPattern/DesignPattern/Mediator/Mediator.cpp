#include "Mediator.h"
#include "Colleague.h"

Mediator::Mediator()
{
}

Mediator::~Mediator()
{
}

ConcreteMediator::ConcreteMediator()
{

}

ConcreteMediator::ConcreteMediator(Colleague* clgA, Colleague* clgB)
: _clgA(clgA), _clgB(clgB)
{

}

ConcreteMediator::~ConcreteMediator()
{

}

void ConcreteMediator::SetConcreteColleagueA(Colleague* clg)
{
	_clgA = clg;
}

Colleague* ConcreteMediator::GetConcreteColleagueA() const
{
	return _clgA;
}

void ConcreteMediator::SetConcreteColleagueB(Colleague* clg)
{
	_clgB = clg;
}

Colleague* ConcreteMediator::GetConcreteColleagueB() const
{
	return _clgB;
}

void ConcreteMediator::IntroColleague(Colleague* clgA, Colleague* clgB)
{
	_clgA = clgA;
	_clgB = clgB;
}

void ConcreteMediator::DoActionFromAtoB()
{
	_clgB->SetState(_clgA->GetState());
}

void ConcreteMediator::DoActionFromBtoA()
{
	_clgA->SetState(_clgB->GetState());
}