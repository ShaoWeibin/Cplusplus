#include "State.h"
#include "StateContext.h"
#include <iostream>
using namespace std;

State::State()
{
}

State::~State()
{
}

void State::OperationInterface(StateContext* con)
{
	cout<<"State OperationInterface..."<<endl;
}

void State::OperationChangeState(StateContext* con)
{
	
}

bool State::ChangeState(StateContext* con, State* st)
{
	con->ChangeState(st);
	return true;
}

ConcreteStateA::ConcreteStateA()
{
}

ConcreteStateA::~ConcreteStateA()
{
}

void ConcreteStateA::OperationInterface(StateContext* con)
{
	cout<<"ConcreteStateA OperationInterface..."<<endl;
}

void ConcreteStateA::OperationChangeState(StateContext* con)
{
	OperationInterface(con);
	this->ChangeState(con, new ConcreteStateB());
}

ConcreteStateB::ConcreteStateB()
{
}

ConcreteStateB::~ConcreteStateB()
{
}

void ConcreteStateB::OperationInterface(StateContext* con)
{
	cout<<"ConcreteStateB OperationInterface..."<<endl;
}

void ConcreteStateB::OperationChangeState(StateContext* con)
{
	OperationInterface(con);
	this->ChangeState(con, new ConcreteStateA());
}