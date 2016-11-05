#include "Subject.h"

//!Default Constructor
Subject::Subject()
{
	_obs = new list<Observer*>;
}
//!Destructor
Subject::~Subject()
{
	delete _obs;
}
//!Function to add an observer to the list of observers
void Subject::Attach(Observer* o)
{
	_obs->push_back(o);
}
//!Function to remove an observer from the list of observers
void Subject::Dettach(Observer* o)
{
	_obs->remove(o);
}

//!Function that calls update() when a change has been made
void Subject::Notify()
{
	list<Observer*>::iterator i = _obs->begin();
	for (; i != _obs->end(); ++i)
		(*i)->Update();
}

