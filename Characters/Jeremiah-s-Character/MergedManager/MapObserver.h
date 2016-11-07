#pragma once

#include "Observer.h"
#include "Maps.h"

/*!
	Class that inherits from Observer class
	Triggers redisplay when notification is sent from the subject
*/

class MapObserver : public Observer
{
private:
	Maps* _sub;
public:
	
	MapObserver(Maps* m);
	~MapObserver();
	void Update();
	void display();

};