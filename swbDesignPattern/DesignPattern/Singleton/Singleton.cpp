#include "Singleton.h"
#include <iostream>
using namespace std;

Singleton* Singleton::_instance = NULL;

Singleton::Singleton()
{
	cout << "Singleton..." << endl;
}

Singleton* Singleton::Instance()
{
	if (NULL == _instance)
		_instance = new Singleton();

	return _instance;
}