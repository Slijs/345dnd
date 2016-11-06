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
	static const int typeScore = 2; //CON score increase
    static const int ScoreIncrease = 2; 
	static const Size size = Medium; // declaring that the dwarf size is Medium
	static const int speed = 5; //each grid block is worth 5 ft. Dwarf speed is 25 ft (i.e. 5 blocks)
};

static class Elf
{
public:
	static const int typeScore = 1; //DEX score increase
	static const int ScoreIncrease = 2;
	static const Size size = Medium; //Elf is Medium size
	static const int speed = 6;  //Elf Speed is 30 ft, 6 block
};

static class Halfling
{
public:
	static const int typeScore = 1; //DEX score increase
	static const int ScoreIncrease = 2;
	static const Size size = Small; //Halflings are set to small size
	static const int speed = 5; //Speed is 25 ft, 5 block
};

static class Human
{
public:
	static const int typeScore = 6; //Increase all six scores
	static const int ScoreIncrease = 1;
	static const Size size = Medium; //Human size set to medium
	static const int speed = 6;  //Elf Speed is 30 ft, 6 block
};