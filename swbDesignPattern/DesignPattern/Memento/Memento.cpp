#include "Memento.h"

Memento::Memento()
{
}

Memento::Memento(const SwbState& state)
{
	_state = state;
}

Memento::~Memento()
{
}

SwbState Memento::GetState() const
{
	return _state;
}

void Memento::SetState(const SwbState& state)
{
	_state = state;
}