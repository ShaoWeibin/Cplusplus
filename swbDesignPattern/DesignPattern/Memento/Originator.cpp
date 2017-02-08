#include "Originator.h"
#include "Memento.h"
#include <iostream>

Originator::Originator()
{
	_state = "";
	_mt = NULL;
}

Originator::Originator(const SwbState& state)
{
	_state = state;
	_mt = NULL;
}

Originator::~Originator()
{
}

Memento* Originator::CreateMemento()
{
	return new Memento(_state);
}

void Originator::SetMemento(Memento* mt)
{
	_mt = mt;
}

void Originator::RestoreMemento(const Memento* mt)
{
	_state = mt->GetState();
}

SwbState Originator::GetState() const
{
	return _state;
}

void Originator::SetState(const SwbState& state)
{
	_state = state;
}

void Originator::PrintState() const
{
	cout<<_state<<"..."<<endl;
}
