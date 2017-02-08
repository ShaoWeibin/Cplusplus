#ifndef _ELEMENT_H_
#define _ELEMENT_H_

class Visitor;

class Element
{
public:
	virtual ~Element();

	virtual void Accept(Visitor* vst) = 0;

protected:
	Element();
};

class ConcreteElementA : public Element 
{
public:
	ConcreteElementA();
	~ConcreteElementA();

	void Accept(Visitor* vst);
};

class ConcreteElementB : public Element
{
public:
	ConcreteElementB();
	~ConcreteElementB();

	void Accept(Visitor* vst);
};

#endif  // _ELEMENT_H_

