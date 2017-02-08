#include "Builder.h"
#include "BuilderProduct.h"
#include <iostream>

Builder::Builder()
{

}

Builder::~Builder()
{

}

ConcreteBuider::ConcreteBuider()
{

}

ConcreteBuider::~ConcreteBuider()
{

}

void ConcreteBuider::BuildPartA(const string& buildParam)
{
	cout << "Step1:Build PartA..." << buildParam << endl;
}

void ConcreteBuider::BuildPartB(const string& buildParam)
{
	cout << "Step1:Build PartB..." << buildParam << endl;
}

void ConcreteBuider::BuildPartC(const string& buildParam)
{
	cout << "Step1:Build PartC..." << buildParam << endl;
}

BuilderProduct* ConcreteBuider::GetProduct()
{
	BuildPartA("pre-defined");
	BuildPartB("pre-defined");
	BuildPartC("pre-defined");

	return new BuilderProduct();
}
