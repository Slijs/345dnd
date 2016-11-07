#pragma once

#include "Observer.h"
#include <list>
using namespace std;

//!Abstract Class for Subject in Observer Pattern. Creates a list of observers and calls update of observer class when notify is called.

class Subject
{
private:
	list<Observer*> *_obs;
public:
	Subject();
	~Subject();

	virtual void Attach(Observer* o);
	virtual void Dettach(Observer* o);
	virtual void Notify();
	virtual void currentState() = 0;
};