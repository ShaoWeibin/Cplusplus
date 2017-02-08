// DesignPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Factory.h"
#include "Product.h"
#include "AbstractFactory.h"
#include "Singleton.h"
#include "Builder.h"
#include "BuilderProduct.h"
#include "Director.h"
#include "Prototype.h"
#include "Abstraction.h"
#include "AbstractionImp.h"
#include "Adapter.h"
#include "Decorator.h"
#include "Composite.h"
#include "Leaf.h"
#include "Flyweight.h"
#include "FlyweightFactory.h"
#include "Facade.h"
#include "Proxy.h"
#include "Template.h"
#include "Strategy.h"
#include "Context.h"
#include "State.h"
#include "StateContext.h"
#include "Observer.h"
#include "ObserverSubject.h"
#include "Mediator.h"
#include "Colleague.h"
#include "Memento.h"
#include "Originator.h"
#include "Command.h"
#include "Receiver.h"
#include "Invoker.h"
#include "Visitor.h"
#include "Element.h"
#include "Handle.h"
#include "Iterator.h"
#include "Aggregate.h"
#include "SwbContext.h"
#include "Interpret.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// Factory
	Factory* f = new ConcreteFactory();
	Product* p = f->CreateProduct();
	cout << "***************************************************" << endl;

	// AbstractFactory
	AbstractFactory* af1 = new ConcreteFactory1();
	af1->CreateProductA();
	af1->CreateProductB();

	AbstractFactory* af2 = new ConcreteFactory2();
	af2->CreateProductA();
	af2->CreateProductB();
	cout << "***************************************************" << endl;

	// Singleton
	Singleton* sgt = Singleton::Instance();
	cout << "***************************************************" << endl;

	// Builder
	Director* d = new Director(new ConcreteBuider());
	d->Construct();
	cout << "***************************************************" << endl;

	// Prototype
	Prototype* pPt = new ConcretePrototype();
	Prototype* pPt1 = pPt->Clone();
	cout << "***************************************************" << endl;

	// Bridge
	AbstractionImp* impA = new ConcreteAbstractionImpA();
	Abstraction* abs1 = new RefinedAbstraction(impA);
	abs1->Operation();

	AbstractionImp* impB = new ConcreteAbstractionImpB();
	Abstraction* abs2 = new RefinedAbstraction(impB);
	abs2->Operation();
	cout << "***************************************************" << endl;

	// Adapter
	Target* adt = new Adapter();
	adt->Request();

	Target* adt_ = new Adapter_(new Adaptee());
	adt_->Request();
	cout << "***************************************************" << endl;

	// Decorator
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator(com);
	dec->Operation();
	delete dec; 
	cout << "***************************************************" << endl;

	// Composite
	Leaf* l1 = new Leaf();
	Leaf* l2 = new Leaf();
	l1->Operation();
	l2->Operation();
	cout << "***************************************************" << endl;

	Composite* root = new Composite();
	root->Add(new Leaf());
	root->Add(l1);
	root->Add(l2);
	root->Operation();
	root->Remove(l2);
	SwbComponent* com2 = root->GetChild(0);
	com2->Operation();
	cout << "***************************************************" << endl;

	// Flyweight
	FlyweightFactory* fc = new FlyweightFactory();
	Flyweight* fw1 = fc->GetFlyweight("hello");
	Flyweight* fw2 = fc->GetFlyweight("world");
	Flyweight* fw3 = fc->GetFlyweight("hello");
	fw3->Operation("world");
	delete fc;
	cout << "***************************************************" << endl;

	// Facade
	Facade*	fcd = new Facade();
	fcd->OperationWrapper();
	delete fcd;
	cout << "***************************************************" << endl;

	// Proxy
	Subject* sub = new ConcreteSubject();
	Proxy* prx = new Proxy(sub);
	prx->Request();
	delete prx;
	cout << "***************************************************" << endl;

	// Template
	AbstractClass* p1 = new ConcreteClass1();
	AbstractClass* p2 = new ConcreteClass2();
	p1->TemplateMethod();
	p2->TemplateMethod();
	delete p1;
	delete p2;
	cout << "***************************************************" << endl;

	// Strategy
	Strategy* stg1 = new ConcreteStrategyA();
	Strategy* stg2 = new ConcreteStrategyB();

	Context* ctx1 = new Context(stg1);
	Context* ctx2 = new Context(stg2);

	ctx1->DoAction();
	ctx2->DoAction();

	delete ctx1;
	delete ctx2;
	cout << "***************************************************" << endl;

	// State
	State* st1 = new ConcreteStateA();
	StateContext* con1 = new StateContext(st1);
	con1->OperationChangeState();
	con1->OperationChangeState();
	con1->OperationChangeState();
	cout << "***************************************************" << endl;

	// Observer
	ObserverSubject* oSub = new ConcreteObserverSubject();
	Observer* o1 = new ConcreteObserverA(oSub);
	Observer* o2 = new ConcreteObserverB(oSub);
	oSub->SetState("old");
	oSub->Notify();
	oSub->SetState("new");
	oSub->Notify();
	cout << "***************************************************" << endl;

	// Mediator
	ConcreteMediator* cm = new ConcreteMediator();
	ConcreteColleagueA* clgA = new ConcreteColleagueA(cm);
	ConcreteColleagueB* clgB = new ConcreteColleagueB(cm);
	cm->IntroColleague(clgA, clgB);

	clgA->SetState("old");
	clgB->SetState("old");

	clgA->Action();
	clgB->Action();

	cout << endl;

	clgA->SetState("new");
	clgA->Action();
	clgB->Action();
	cout << endl;

	clgB->SetState("old");
	clgB->Action();
	clgA->Action();
	cout << "***************************************************" << endl;

	// Memento
	Originator* o = new Originator("old");
	o->PrintState();
	Memento* m = o->CreateMemento();
	o->SetState("new");
	o->PrintState();
	o->RestoreMemento(m);
	o->PrintState();
	cout << "***************************************************" << endl;

	// Command
	Receiver* rcv = new Receiver();
	Command* cmd = new ConcreteCommand(rcv);
	Invoker* inv = new Invoker(cmd);
	inv->Invoke();
	cout << "***************************************************" << endl;

	// Visitor
	Visitor* vstA = new ConcreteVisitorA();
	Visitor* vstB = new ConcreteVisitorB();
	Element* elmA = new ConcreteElementA();
	Element* elmB = new ConcreteElementB();
	elmA->Accept(vstA);
	elmB->Accept(vstB);
	cout << "***************************************************" << endl;

	// Chain of Responsibility
	Handle* h1 = new ConcreteHandleA();
	Handle* h2 = new ConcreteHandleB();
	h1->SetSuccessor(h2);
	h1->HandleRequest();
	cout << "***************************************************" << endl;

	// Iterator
	Aggregate* ag = new ConcreteAggregate();
	Iterator* itr = new ConcreteIterator(ag);
	for (; !itr->IsDone(); itr->Next())
		cout << itr->CurrentItem() << endl;
	cout << "***************************************************" << endl;

	// Interpreter
	SwbContext* ctxt = new SwbContext();
	AbstractExpression* exp = new TerminalExpression("hello");
	AbstractExpression* nexp = new NonterminalExpression(exp, 3);
	nexp->Interpret(*ctxt);
	cout << "***************************************************" << endl;

	system("pause");
	return 0;
}

