#include "Iterator.h"
#include "Aggregate.h"
#include <iostream>
using namespace std;

Iterator::Iterator()
{
}

Iterator::~Iterator()
{
}

ConcreteIterator::ConcreteIterator(Aggregate* ag, int index)
: _ag(ag), _index(index)
{

}

ConcreteIterator::~ConcreteIterator()
{

}

void ConcreteIterator::First()
{
	_index = 0;
}

void ConcreteIterator::Next()
{
	if (_index < _ag->GetSize())
		++_index;
}

bool ConcreteIterator::IsDone()
{
	return _index == _ag->GetSize();
}

Object ConcreteIterator::CurrentItem()
{
	return _ag->GetItem(_index);
}