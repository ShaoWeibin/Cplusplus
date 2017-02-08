#ifndef _MEMENTO_H_
#define _MEMENTO_H_

#include <string>
using namespace std;

typedef string SwbState;
class Originator;

class Memento
{
private:
	friend class Originator;

	Memento();
	Memento(const SwbState& state);
	~Memento();

	SwbState GetState() const;
	void SetState(const SwbState& state);

private: 
	SwbState _state;
};

#endif  // _MEMENTO_H_