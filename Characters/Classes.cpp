/**
*@file Classes.cpp
*@brief Definition of Classes methods
*<p> This document outlines the implementation of the Classes class, and the methods that allow a Character to make use of 
* a Class. As explained in Classes.h, a Classes allows a Character to have a base HP and a hitDie, which is used upon leveling
* up to increase their maxHP
*/
#include "stdafx.h"
#include "Classes.h"
#include <string>

/**
* This Constructor takes the desired ClassType, and initializes the baseHP and hitDie according to that type.
*<p>Cleric: BaseHP 8, Hit Die d8
*<p>Fighter: BaseHP 10, Hit Die d10
*<p>Rogue: BaseHP 8, Hit Die d8
*<p>Wizard: BaseHP 6, Hit Die d6
*/
Classes::Classes(ClassType theirType) {
	switch (theirType) {
	case(Cleric): baseHP = 8;
		hitDie = "d8";
		break;
	case(Fighter):
		baseHP = 10;
		hitDie = "d10";
		break;
	case(Rogue):
		baseHP = 8;
		hitDie = "d8";
		break;
	case(Wizard):
		baseHP = 6;
		hitDie = "d6";
		break;
	}

	whichClass = theirType;
}


/**
* This method will return the baseHP associated with the specific Classes instance.
* @return integer, representing the base Hit Points of the specific Classes subclass
*/
int Classes::getBaseHP() {
	return baseHP;
}


/**
* This method will return the string representing the base hit die that is rolled for the specific
* Classes instance. It will be in the form "xDy",  where x and y are positive integers.
* @return string, representing the hit die to roll for this Classes instance.
*/
string Classes::getHitDie() {
	return hitDie;
}

/**
* This method returns a String representing the type of Class this is.
*@return string, representing Class type
*/
string Classes::getWhichClass() {
	string typeNames[4] = { "Cleric", "Fighter", "Rogue", "Wizard" };
	return typeNames[whichClass];
}