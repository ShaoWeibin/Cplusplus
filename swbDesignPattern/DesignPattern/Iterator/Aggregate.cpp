#include "Aggregate.h"
#include "Iterator.h"

Aggregate::Aggregate()
{
}

Aggregate::~Aggregate()
{
}

ConcreteAggregate::ConcreteAggregate()
{
	for (int i = 0; i < SIZE; ++i)
		_objs[i] = i;
}

ConcreteAggregate::~ConcreteAggregate()
{

}

Iterator* ConcreteAggregate::CreateIterator()
{
	return new ConcreteIterator(this);
}

Object ConcreteAggregate::GetItem(int index)
{
	if (index < GetSize())
		return _objs[index];
	else
		return -1;
}

int ConcreteAggregate::GetSize()
{
	return SIZE;
}
