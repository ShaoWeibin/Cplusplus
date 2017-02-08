#include "Strategy.h"
#include <iostream>
using namespace std;

Strategy::Strategy()
{
}

Strategy::~Strategy()
{
}

ConcreteStrategyA::ConcreteStrategyA()
{

}

ConcreteStrategyA::~ConcreteStrategyA()
{

}

void ConcreteStrategyA::AlgorithmInterface()
{
	cout<<"ConcreteStrategyA AlgorithmInterface..."<<endl;
}

ConcreteStrategyB::ConcreteStrategyB()
{

}

ConcreteStrategyB::~ConcreteStrategyB()
{

}

void ConcreteStrategyB::AlgorithmInterface()
{
	cout<<"ConcreteStrategyB AlgorithmInterface..."<<endl;
}
