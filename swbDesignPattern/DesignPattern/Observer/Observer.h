#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>
using namespace std;

typedef string SubjectState;
class ObserverSubject;

class Observer
{
public:
	virtual ~Observer();

public:
	virtual void Update(ObserverSubject*) = 0;
	virtual void PrintInfo() const = 0;

protected:
	Observer();

	SubjectState _state;
	
};

class ConcreteObserverA : public Observer
{
public:
	ConcreteObserverA(ObserverSubject*);
	virtual ~ConcreteObserverA();

public:
	void Update(ObserverSubject*);
	void PrintInfo() const;

	virtual ObserverSubject* GetSubject() const;

private:
	ObserverSubject* _sub;
};

class ConcreteObserverB : public Observer
{
public:
	ConcreteObserverB(ObserverSubject*);
	virtual ~ConcreteObserverB();

public:
	void Update(ObserverSubject*);
	void PrintInfo() const;

	virtual ObserverSubject* GetSubject() const;

private:
	ObserverSubject* _sub;
};

#endif  // _OBSERVER_H_
