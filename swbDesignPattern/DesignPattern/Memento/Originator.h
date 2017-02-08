#ifndef _ORIGINATOR_H_
#define _ORIGINATOR_H_

#include <string>
using namespace std;

typedef string SwbState;
class Memento;

class Originator
{
public:
	Originator();
	Originator(const SwbState& state);
	~Originator();

public:
	Memento* CreateMemento();
	void SetMemento(Memento* mt);
	void RestoreMemento(const Memento* mt);

	SwbState GetState() const;
	void SetState(const SwbState& state);
	void PrintState() const;

private: 
	SwbState _state;
	Memento* _mt;
};

#endif  // _ORIGINATOR_H_
