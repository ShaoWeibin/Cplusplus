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
/* ��ģʽ����������                                                        */
/* ͨ��public�̳л�ýӿڼ̳е�Ч��, ͨ��private�̳л��ʵ�ּ̳е�Ч��           */
/************************************************************************/
class Adapter : public Target, private Adaptee
{
public:
	Adapter();
	~Adapter();

	void Request();
};

/************************************************************************/
/* ����ģʽ����������                                                      */
/* �̳�Target��, ������ϵķ�ʽʵ��Adaptee�ĸ���                             */
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
