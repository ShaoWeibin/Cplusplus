#ifndef _MEDIATOR_H_
#define _MEDIATOR_H_

class Colleague;

class Mediator
{
public:
	~Mediator();

	virtual void DoActionFromAtoB() = 0;
	virtual void DoActionFromBtoA() = 0;

protected:
	Mediator();
};

class ConcreteMediator : public Mediator
{
public:
	ConcreteMediator();
	ConcreteMediator(Colleague* clgA, Colleague* clgB);
	~ConcreteMediator();

	void SetConcreteColleagueA(Colleague* clg);
	Colleague* GetConcreteColleagueA() const;
	void SetConcreteColleagueB(Colleague* clg);
	Colleague* GetConcreteColleagueB() const;

	void IntroColleague(Colleague* clgA, Colleague* clgB);

	void DoActionFromAtoB();
	void DoActionFromBtoA();

private:
	Colleague* _clgA;
	Colleague* _clgB;
};

#endif  // _MEDIATOR_H_

