#pragma once

#include "Observer.h"
#include <list>
using namespace std;

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