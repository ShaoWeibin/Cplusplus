#include "Command.h"
#include "Receiver.h"

Command::Command()
{
}

Command::~Command()
{
}

ConcreteCommand::ConcreteCommand(Receiver* rcv) : _rcv(rcv)
{

}

ConcreteCommand::~ConcreteCommand()
{

}

void ConcreteCommand::Excute()
{
	_rcv->Action();
}