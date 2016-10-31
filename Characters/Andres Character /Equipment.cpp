#include "Equipment.h"
#include <iostream>

using namespace std;


Equipment::Equipment()
{
}

Equipment::Equipment(string nameVal, int weaponTypeVal) {
	this->weaponType = weaponTypeVal;
	this->name = nameVal;
}




Equipment::~Equipment()
{
}


