#include "Element.h"
#include "Visitor.h"
#include <iostream>
using namespace std;

Element::Element()
{
}

Element::~Element()
{
}

ConcreteElementA::ConcreteElementA()
{

}

ConcreteElementA::~ConcreteElementA()
{

}

void ConcreteElementA::Accept(Visitor* vst)
{
	vst->VisitConcreteElementA(this);
	cout << "visiting ConcreteElementA..." << endl;
}

ConcreteElementB::ConcreteElementB()
{

}

ConcreteElementB::~ConcreteElementB()
{

}

void ConcreteElementB::Accept(Visitor* vst)
{
	vst->VisitConcreteElementB(this);
	cout << "visiting ConcreteElementB..." << endl;
}