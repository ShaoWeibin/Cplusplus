#include "stdafx.h"
#include "Adapter.h"
#include <iostream>
using namespace std;

Target::Target()
{

}

Target::~Target()
{

}

void Target::Request()
{
	cout << "Target::Request..." << endl;
}

Adaptee::Adaptee()
{

}

Adaptee::~Adaptee()
{

}

void Adaptee::SpecificRequest()
{
	cout << "Adaptee::SpecificRequest..." << endl;
}

Adapter::Adapter()
{
}

Adapter::~Adapter()
{
}

void Adapter::Request()
{
	this->SpecificRequest();
}

Adapter_::Adapter_(Adaptee* ade)
{
	_ade = ade;
}

Adapter_::~Adapter_()
{

}

void Adapter_::Request()
{
	_ade->SpecificRequest();
}
