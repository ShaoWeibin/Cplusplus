#ifndef _STATE_CONTEXT_H_
#define _STATE_CONTEXT_H_

class State;

class StateContext
{
public:
	StateContext();
	StateContext(State* state);
	~StateContext();

public:
	void OperationInterface();
	void OperationChangeState();

private:
	friend class State;

	bool ChangeState(State* state);

private:
	State* _state;
};

#endif  // _STATE_CONTEXT_H_