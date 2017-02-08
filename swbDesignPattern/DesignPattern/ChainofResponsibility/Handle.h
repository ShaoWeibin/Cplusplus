#ifndef _HANDLE_H_
#define _HANDLE_H_

class Handle
{
public:
	virtual ~Handle();

	virtual void HandleRequest() = 0;

	void SetSuccessor(Handle* succ);
	Handle* GetSuccessor() const;

protected:
	Handle();
	Handle(Handle* succ);

private:
	Handle* _succ;
};

class ConcreteHandleA : public Handle
{
public:
	ConcreteHandleA();
	ConcreteHandleA(Handle* succ);
	~ConcreteHandleA();

	void HandleRequest();
};

class ConcreteHandleB : public Handle
{
public:
	ConcreteHandleB();
	ConcreteHandleB(Handle* succ);
	~ConcreteHandleB();

	void HandleRequest();
};

#endif  // _HANDLE_H_