#include "Decorator.h"
#include <iostream>
using namespace std;

Component::Component()
{

}

Component::~Component()
{

}

void Component::Operation()
{

}

ConcreteComponent::ConcreteComponent()
{

}

ConcreteComponent::~ConcreteComponent()
{

}

void ConcreteComponent::Operation()
{
	cout << "ConcreteComponent::Operation..." << endl;
}

Decorator::Decorator(Component* com)
{
	this->_com = com;
}

Decorator::~Decorator()
{
	delete _com;
}

void Decorator::Operation()
{

}

ConcreteDecorator::ConcreteDecorator(Component* com) 
: Decorator(com)
{
	
}

ConcreteDecorator::~ConcreteDecorator()
{

}

void ConcreteDecorator::Operation()
{
	_com->Operation();
	AddBehavior();
}

void ConcreteDecorator::AddBehavior()
{
	cout << "ConcreteDecorator::AddBehavior..." << endl;
}

