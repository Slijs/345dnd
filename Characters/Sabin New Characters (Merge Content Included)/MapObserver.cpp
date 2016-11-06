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
	display();
}

/*!Function that clears screen and re-displays map.
Note that if exit is reached will terminate program*/
void MapObserver::display()
{
	system("CLS");
	_sub->displayMap();
	if (_sub->getCleared())
	{
		cout << "\nLevel Cleared!\n";
		system("PAUSE");
		exit(0);
	}
	
}