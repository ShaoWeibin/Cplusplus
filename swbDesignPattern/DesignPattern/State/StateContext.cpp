#include "StateContext.h"
#include "State.h"

StateContext::StateContext()
{
}
StateContext::StateContext(State* state)
{
	this->_state = state;
}


StateContext::~StateContext()
{
	delete _state;
}

void StateContext::OperationInterface()
{
	this->_state->OperationInterface(this);
}

void StateContext::OperationChangeState()
{
	this->_state->OperationChangeState(this);
}

bool StateContext::ChangeState(State* state)
{
	this->_state = state;
	return true;
}