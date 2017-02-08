#ifndef _STATE_H_
#define _STATE_H_

class StateContext;

class State
{
public:
	State();
	virtual ~State();

public:
	virtual void OperationInterface(StateContext*) = 0;
	virtual void OperationChangeState(StateContext*) = 0;

protected:
	virtual bool ChangeState(StateContext* con, State* st);
};

class ConcreteStateA : public State
{
public:
	ConcreteStateA();
	virtual ~ConcreteStateA();

public:
	virtual void OperationInterface(StateContext*);
	virtual void OperationChangeState(StateContext*);
};

class ConcreteStateB : public State
{
public:
	ConcreteStateB();
	virtual ~ConcreteStateB();

public:
	virtual void OperationInterface(StateContext*);
	virtual void OperationChangeState(StateContext*);
};

#endif  // _STATE_H_