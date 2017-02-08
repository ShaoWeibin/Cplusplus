#ifndef _ADAPTER_H_
#define _ADAPTER_H_

class Target
{
public:
	Target();
	virtual ~Target();

	virtual void Request();
};

class Adaptee
{
public:
	Adaptee();
	~Adaptee();

	void SpecificRequest();
};

/************************************************************************/
/* 类模式，适配器类                                                        */
/* 通过public继承获得接口继承的效果, 通过private继承获得实现继承的效果           */
/************************************************************************/
class Adapter : public Target, private Adaptee
{
public:
	Adapter();
	~Adapter();

	void Request();
};

/************************************************************************/
/* 对象模式，适配器类                                                      */
/* 继承Target类, 采用组合的方式实现Adaptee的复用                             */
/************************************************************************/
class Adapter_ : public Target
{
public:
	Adapter_(Adaptee* ade);
	~Adapter_();

	void Request();

private:
	Adaptee* _ade;
};

#endif  // _ADAPTER_H_
