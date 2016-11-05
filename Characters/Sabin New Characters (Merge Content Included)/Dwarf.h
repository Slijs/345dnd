#pragma once
#include "Entity.h"
/*!
	Static class that contains all relevant constants that
	are relevant to Dwarf Race
	NOTE: not all these values are used in creation of fighter yet.
*/
static class Dwarf
{
public:
    static const int constScoreIncrease = 2; //constitution score increase +2
	static const Size size = Medium; // declaring that the dwarf size is Medium
	static const int speed = 5; //each grid block is worth 5 ft. Dwarf speed is 25 ft (i.e. 5 blocks)
};