#ifndef _FLYWEIGHT_FACTORY_H_
#define _FLYWEIGHT_FACTORY_H_

#include <string>
#include <vector>
using namespace std;

class Flyweight;

class FlyweightFactory
{
public:
	FlyweightFactory();
	~FlyweightFactory();

public:
	Flyweight* GetFlyweight(const string& key);

private:
	vector<Flyweight*> _fly;
};

#endif  // _FLYWEIGHT_FACTORY_H_

