#include "Handle.h"
#include <iostream>
using namespace  std;

Handle::Handle() : _succ(NULL)
{
}

Handle::Handle(Handle* succ) : _succ(succ)
{
}

Handle::~Handle()
{
}

void Handle::HandleRequest()
{

}

void Handle::SetSuccessor(Handle* succ)
{
	_succ = succ;
}

Handle* Handle::GetSuccessor() const
{
	return _succ;
}

ConcreteHandleA::ConcreteHandleA()
{

}

ConcreteHandleA::ConcreteHandleA(Handle* succ) : Handle(succ)
{

}
ConcreteHandleA::~ConcreteHandleA()
{

}

void ConcreteHandleA::HandleRequest()
{
	if (GetSuccessor())
	{
		cout << "ConcreteHandleA 我把处理权给后继节点..." << endl;
		GetSuccessor()->HandleRequest();
	}
	else
		cout << "ConcreteHandleA 没有后继了，我必须自己处理..." << endl;
}

ConcreteHandleB::ConcreteHandleB()
{

}

ConcreteHandleB::ConcreteHandleB(Handle* succ) : Handle(succ)
{

}
ConcreteHandleB::~ConcreteHandleB()
{

}

void ConcreteHandleB::HandleRequest()
{
	if (GetSuccessor())
	{
		cout << "ConcreteHandleB 我把处理权给后继节点..." << endl;
		GetSuccessor()->HandleRequest();
	}
	else
		cout << "ConcreteHandleB 没有后继了，我必须自己处理..." << endl;
}