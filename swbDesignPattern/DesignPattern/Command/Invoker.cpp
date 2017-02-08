#include "Invoker.h"
#include "Command.h"

Invoker::Invoker(Command* cmd) : _cmd(cmd)
{
}

Invoker::~Invoker()
{
}

void Invoker::Invoke()
{
	_cmd->Excute();
}