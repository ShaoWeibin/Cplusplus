#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include "Component.h"
#include <vector>
using namespace std;

class Composite : public SwbComponent
{
public:
	Composite();
	~Composite();

public:
	void Operation();
	void Add(SwbComponent* com);
	void Remove(SwbComponent* com);
	SwbComponent* GetChild(int index);

private:
	vector<SwbComponent*> _comVector;
};

#endif  // _COMPOSITE_H_