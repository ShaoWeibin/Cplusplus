#ifndef _COMPONENT_H_
#define _COMPONENT_H_

class SwbComponent
{
public:
	SwbComponent();
	virtual ~SwbComponent();

public:
	virtual void Operation() = 0;
	virtual void Add(SwbComponent*);
	virtual void Remove(SwbComponent*);
	virtual SwbComponent* GetChild(int);
};

#endif  // _COMPONENT_H_