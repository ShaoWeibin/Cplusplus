#ifndef _OBSERVER_SUBJECT_H_
#define _OBSERVER_SUBJECT_H_

#include <string>
#include <list>
using namespace std;

typedef string SubjectState;
class Observer;

class ObserverSubject
{
public:
	virtual ~ObserverSubject();

public:
	virtual void Attach(Observer*);
	virtual void Detach(Observer*);
	virtual void Notify();
	virtual void SetState(const SubjectState&) = 0;
	virtual SubjectState GetState() const = 0;

protected:
	ObserverSubject();

private:
	list<Observer*>* _obvs;
};

class ConcreteObserverSubject : public ObserverSubject
{
public:
	ConcreteObserverSubject();
	~ConcreteObserverSubject();

public:
	void SetState(const SubjectState&);
	SubjectState GetState() const;

private:
	SubjectState _state;
};

#endif  // _OBSERVER_SUBJECT_H_

