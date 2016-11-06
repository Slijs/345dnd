#include "MapObserver.h"

MapObserver::MapObserver(Maps* m)
{
	_sub = m;
	_sub->Attach(this);
}
MapObserver::~MapObserver()
{
	_sub->Dettach(this);
}

void MapObserver::Update()
{
	display;
}

void MapObserver::display()
{
	
}