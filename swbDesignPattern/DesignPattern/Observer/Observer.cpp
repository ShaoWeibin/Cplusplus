#include "Observer.h"
#include "ObserverSubject.h"
#include <iostream>

Observer::Observer()
{
	_state = "";
}


Observer::~Observer()
{
}

ConcreteObserverA::ConcreteObserverA(ObserverSubject* sub)
{
	_sub = sub;
	_sub->Attach(this);
}

ConcreteObserverA::~ConcreteObserverA()
{
	_sub->Detach(this);
	if (!_sub) delete _sub;
}

void ConcreteObserverA::Update(ObserverSubject* sub)
{
	_state = sub->GetState();
	PrintInfo();
}

void ConcreteObserverA::PrintInfo() const
{
	cout << "ConcreteObserverA observer..." << _sub->GetState() << endl;
}

ObserverSubject* ConcreteObserverA::GetSubject() const
{
	return _sub;
}

ConcreteObserverB::ConcreteObserverB(ObserverSubject* sub)
{
	_sub = sub;
	_sub->Attach(this);
}

ConcreteObserverB::~ConcreteObserverB()
{
	_sub->Detach(this);
	if (!_sub) delete _sub;
}

void ConcreteObserverB::Update(ObserverSubject* sub)
{
	_state = sub->GetState();
	PrintInfo();
}

void ConcreteObserverB::PrintInfo() const
{
	cout << "ConcreteObserverB observer..." << _sub->GetState() << endl;
}

ObserverSubject* ConcreteObserverB::GetSubject() const
{
	return _sub;
}
