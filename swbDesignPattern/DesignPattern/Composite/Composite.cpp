#include "Composite.h"
#include <iostream>

Composite::Composite()
{
}

Composite::~Composite()
{
}

void Composite::Operation()
{
	cout<<"Composite::Operation..."<<endl;
	vector<SwbComponent*>::const_iterator itr;
	for (itr = _comVector.begin(); itr != _comVector.end(); ++itr)
		(*itr)->Operation();
}

void Composite::Add(SwbComponent* com)
{
	_comVector.push_back(com);
}

void Composite::Remove(SwbComponent* com)
{
	vector<SwbComponent*>::const_iterator itr = _comVector.begin();
	while (itr != _comVector.end())
	{
		if (com == *itr)
		{
			_comVector.erase(itr);
			return;
		}

		++itr;
	}
}

SwbComponent* Composite::GetChild(int index)
{
	return _comVector[index];
}
