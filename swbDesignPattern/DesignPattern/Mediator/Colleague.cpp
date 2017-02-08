#include "Colleague.h"
#include "Mediator.h"
#include <iostream>

Colleague::Colleague() : _mdt(NULL)
{
}

Colleague::Colleague(Mediator* mdt) : _mdt(mdt)
{

}

Colleague::~Colleague()
{
}

ConcreteColleagueA::ConcreteColleagueA()
{

}

ConcreteColleagueA::ConcreteColleagueA(Mediator* mdt) : Colleague(mdt)
{

}

ConcreteColleagueA::~ConcreteColleagueA()
{

}

void ConcreteColleagueA::Action()
{
	_mdt->DoActionFromAtoB();
	cout << "state of ConcreteColleagueB: " << GetState() << endl;
}

string ConcreteColleagueA::GetState() const
{
	return _state;
}

void ConcreteColleagueA::SetState(const string& state)
{
	_state = state;
}

ConcreteColleagueB::ConcreteColleagueB()
{

}

ConcreteColleagueB::ConcreteColleagueB(Mediator* mdt) : Colleague(mdt)
{

}

ConcreteColleagueB::~ConcreteColleagueB()
{

}

void ConcreteColleagueB::Action()
{
	_mdt->DoActionFromBtoA();
	cout << "state of ConcreteColleagueA: " << GetState() << endl;
}

string ConcreteColleagueB::GetState() const
{
	return _state;
}

void ConcreteColleagueB::SetState(const string& state)
{
	_state = state;
}


