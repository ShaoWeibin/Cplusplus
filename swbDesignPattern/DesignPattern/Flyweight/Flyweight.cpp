#include "Flyweight.h"
#include <iostream>

Flyweight::Flyweight(string intrinsicState)
{
	this->_intrinsicState = intrinsicState;
}

Flyweight::~Flyweight()
{
}

void Flyweight::Operation(const string& extrinsicState)
{

}

string Flyweight::GetIntrinsicState() const
{
	return this->_intrinsicState;
}

ConcreteFlyweight::ConcreteFlyweight(string intrinsicState) : Flyweight(intrinsicState)
{
	cout << "ConcreteFlyweight Build..." << intrinsicState << endl;
}

ConcreteFlyweight::~ConcreteFlyweight()
{

}

void ConcreteFlyweight::Operation(const string& extrinsicState)
{
	cout << "ConcreteFlyweight:[" << this->GetIntrinsicState() << "][" << extrinsicState << "]" << endl;
}