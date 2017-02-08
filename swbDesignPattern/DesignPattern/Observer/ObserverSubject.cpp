#include "ObserverSubject.h"
#include "Observer.h"

ObserverSubject::ObserverSubject()
{
	_obvs = new list<Observer*>;
}

ObserverSubject::~ObserverSubject()
{
	delete _obvs;
}

void ObserverSubject::Attach(Observer* obv)
{
	_obvs->push_front(obv);
}

void ObserverSubject::Detach(Observer* obv)
{
	if (!obv) _obvs->remove(obv);
}

void ObserverSubject::Notify()
{
	list<Observer*>::const_iterator itr;
	for (itr = _obvs->begin(); itr != _obvs->end(); ++itr)
		(*itr)->Update(this);
}

ConcreteObserverSubject::ConcreteObserverSubject()
{
	_state = "";
}


ConcreteObserverSubject::~ConcreteObserverSubject()
{
}

void ConcreteObserverSubject::SetState(const SubjectState& state)
{
	_state = state;
}

SubjectState ConcreteObserverSubject::GetState() const
{
	return _state;
}
