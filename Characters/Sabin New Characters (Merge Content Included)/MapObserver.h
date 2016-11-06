#pragma once

#include "Observer.h"
#include "Maps.h"

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