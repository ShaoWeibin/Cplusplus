#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <string>
using namespace std;

class BuilderProduct;

class Builder
{
public:
	virtual ~Builder();

	virtual void BuildPartA(const string& buildParam) = 0;
	virtual void BuildPartB(const string& buildParam) = 0;
	virtual void BuildPartC(const string& buildParam) = 0;

	virtual BuilderProduct* GetProduct() = 0;

protected:
	Builder();
};

class ConcreteBuider : public Builder
{
public:
	ConcreteBuider();
	~ConcreteBuider();

	void BuildPartA(const string& buildParam);
	void BuildPartB(const string& buildParam);
	void BuildPartC(const string& buildParam);

	BuilderProduct* GetProduct();
};

#endif  // _BUILDER_H_