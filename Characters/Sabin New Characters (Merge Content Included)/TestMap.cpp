#include <iostream>
#include "Fighter.h"
#include "Maps.h"
#include "MapObserver.h"

 
int main()
{
	
	Fighter* f1 = new Fighter(1, Dwarf, "Gordon");
	Maps* m = new Maps(f1);
	MapObserver* mo = new MapObserver(m);
	m->displayMap();

	int c = 0;
	while (1)
	{
		m->detectKey(c = _getch());
	}


	m->~Maps();
	f1->~Fighter();

	system("PAUSE");
	return 0;
}