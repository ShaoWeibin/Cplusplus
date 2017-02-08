#ifndef _COMMAND_H
#define _COMMAND_H

class Receiver;

class Command
{
public:
	~Command();

	virtual void Excute() = 0;

protected:
	Command();
};

class ConcreteCommand : public Command
{
public:
	ConcreteCommand(Receiver* rcv);
	~ConcreteCommand();

	void Excute();

private:
	Receiver* _rcv;
};

#endif  // _COMMAND_H
