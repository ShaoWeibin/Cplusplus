#include "Prototype.h"
#include <iostream>
using namespace std;

Prototype::Prototype()
{
}

Prototype::~Prototype()
{
}

ConcretePrototype::ConcretePrototype()
{

}

ConcretePrototype::ConcretePrototype(const ConcretePrototype& rhs)
{
	cout << "ConcretePrototype copy ..."<<endl; 
}

ConcretePrototype::~ConcretePrototype()
{

}

Prototype* ConcretePrototype::Clone() const
{
	return new ConcretePrototype(*this);
}