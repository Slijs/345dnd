#include "Subject.h"

Subject::Subject()
{
	_obs = new list<Observer*>;
}

Subject::~Subject()
{
	delete _obs;
}

void Subject::Attach(Observer* o)
{
	_obs->push_back(o);
}

void Subject::Dettach(Observer* o)
{
	_obs->remove(o);
}

void Subject::Notify()
{
	list<Observer*>::iterator i = _obs->begin();
	for (; i != _obs->end(); ++i)
		(*i)->Update();
}

