#include "Visitor.h"
#include "Element.h"
#include <iostream>
using namespace std;

Visitor::Visitor()
{
}

Visitor::~Visitor()
{
}

ConcreteVisitorA::ConcreteVisitorA()
{

}

ConcreteVisitorA::~ConcreteVisitorA()
{

}

void ConcreteVisitorA::VisitConcreteElementA(Element* elm)
{
	cout << "I will visit ConcreteElementA..." << endl;
}

void ConcreteVisitorA::VisitConcreteElementB(Element* elm)
{
	cout << "I will visit ConcreteElementB..." << endl;
}

ConcreteVisitorB::ConcreteVisitorB()
{

}

ConcreteVisitorB::~ConcreteVisitorB()
{

}

void ConcreteVisitorB::VisitConcreteElementA(Element* elm)
{
	cout << "I will visit ConcreteElementA..." << endl;
}

void ConcreteVisitorB::VisitConcreteElementB(Element* elm)
{
	cout << "I will visit ConcreteElementB..." << endl;
}
