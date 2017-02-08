#ifndef _COLLEAGUE_H_
#define _COLLEAGUE_H_

#include <string>
using namespace std;

class Mediator;

class Colleague
{
public:
	~Colleague();

	virtual void Action() = 0;
	virtual string GetState() const = 0;
	virtual void SetState(const string& state) = 0;

protected:
	Colleague();
	Colleague(Mediator* mdt);

protected:
	Mediator* _mdt;
	string _state;
};

class ConcreteColleagueA : public Colleague
{
public:
	ConcreteColleagueA();
	ConcreteColleagueA(Mediator* mdt);
	~ConcreteColleagueA();

	void Action();
	string GetState() const;
	void SetState(const string& state);
};

class ConcreteColleagueB : public Colleague
{
public:
	ConcreteColleagueB();
	ConcreteColleagueB(Mediator* mdt);
	~ConcreteColleagueB();

	void Action();
	string GetState() const;
	void SetState(const string& state);
};

#endif  // _COLLEAGUE_H_
