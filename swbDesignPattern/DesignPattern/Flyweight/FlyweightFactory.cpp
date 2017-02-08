#include "FlyweightFactory.h"
#include "Flyweight.h"
#include <iostream>

FlyweightFactory::FlyweightFactory()
{
}

FlyweightFactory::~FlyweightFactory()
{
	for (int i = 0; i < (int) _fly.size(); ++i)
		delete _fly[i];
}

Flyweight* FlyweightFactory::GetFlyweight(const string& key)
{
	vector<Flyweight*>::const_iterator itr;
	for (itr = _fly.begin(); itr != _fly.end(); ++itr)
	{
		if ((*itr)->GetIntrinsicState() == key)
		{
			cout << "Already create by user..." << endl;
			return *itr;
		}
	}

	Flyweight* fw = new ConcreteFlyweight(key);
	_fly.push_back(fw);
	return fw;
}
