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
		cout << "ConcreteHandleA �ҰѴ���Ȩ����̽ڵ�..." << endl;
		GetSuccessor()->HandleRequest();
	}
	else
		cout << "ConcreteHandleA û�к���ˣ��ұ����Լ�����..." << endl;
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
		cout << "ConcreteHandleB �ҰѴ���Ȩ����̽ڵ�..." << endl;
		GetSuccessor()->HandleRequest();
	}
	else
		cout << "ConcreteHandleB û�к���ˣ��ұ����Լ�����..." << endl;
}