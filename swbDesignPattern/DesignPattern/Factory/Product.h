#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class Product
{
public:
	virtual ~Product();

protected:
	Product();
};

class ConcreteProduct : public Product
{
public:
	ConcreteProduct();
	~ConcreteProduct();
};

#endif  // _PRODUCT_H_