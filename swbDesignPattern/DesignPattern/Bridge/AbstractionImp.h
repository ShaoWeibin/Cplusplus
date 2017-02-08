#ifndef _ABSTRACTION_IMP_H_
#define _ABSTRACTION_IMP_H_

class AbstractionImp
{
public:
	~AbstractionImp();
	virtual void Operation() = 0;

protected:
	AbstractionImp();
};

class ConcreteAbstractionImpA : public AbstractionImp
{
public:
	ConcreteAbstractionImpA();
	~ConcreteAbstractionImpA();
	virtual void Operation();	
}; 

class ConcreteAbstractionImpB : public AbstractionImp
{
public:
	ConcreteAbstractionImpB();
	~ConcreteAbstractionImpB();
	virtual void Operation();
};

#endif  // _ABSTRACTION_IMP_H_

