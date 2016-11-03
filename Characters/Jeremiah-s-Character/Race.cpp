/**
*@file Race.cpp
*@brief Outlines the definition of the Race class and its subclasses
*<p>Race is used to provide a Character with a speed, size and a special ability modifier.
*/

#include "stdafx.h"
#include "Race.h"	// Used in order to implement Race and its subclasses
#include <string>	// Used to make use of the string type
#include "Character.h"	// Used to access Abilities enumerated type
using namespace std;

/**
* Default constructor - will not initialize values.
*/
Race::Race() {}

/**
* Paramaterized constructor - will initialize all values of the race.
*@param speed integer value representing the Race's speed
*@param raceSize enumerated type Size, representing the Race's size
*@param attMod integer, representing how many points are added to the special ability
*@param modified enumerated type Abilities, representing which ability the Race modifies
*/
Race::Race(int speed, Size raceSize, int attMod, Abilities modified) {
	this->raceSpeed = speed;
	this->raceSize = raceSize;
	this->ablmod = attMod;
	this->modified = modified;
}

/** 
* Returns the speed of the race
*@return integer, representing the Race's speed
*/
int Race::getRaceSpeed() {
	return raceSpeed;
}

/**
* Returns the size  of the race
*@return integer, representing the Race's size
*/
Size Race::getRaceSize() {
	return this->raceSize;
}

/**
* Returns the ability modifier of the race
*@return integer, representing the Race's ability modifier
*/int Race::getAblMod() {
	return this->ablmod;
}

/**
* Returns the type of Ability that gets modified by the Race
*@return Abilities, representing the ability that gets modified
*/
Abilities Race::getAbilityModified() {
	return modified;
}

/**
* Returns a string representing the full name of the race.
*@return string, representing the race name
*/
string Race::getWhichRace() {
	string typeNames[4] = { "Dwarf", "Elf", "Halfling", "Human" };
	return typeNames[whichRace];
}

/* DWARF CLASS : EXTENDS RACE */
/**
* Dwarf constructor. Initializes the Dwarf race with the appropriate values.
*/
Dwarf::Dwarf() : Race::Race(25, Medium, 2, Strength) {
	whichRace = Dwar;
}

/* ELF CLASS : EXTENDS RACE */
/**
* Elf constructor. Initializes the Elf race with the appropriate values.
*/
Elf::Elf() : Race::Race(30, Medium, 2, Dexterity) {
	whichRace = El;
}

/* HALFLING CLASS : EXTENDS RACE */
/**
* Halfling constructor. Initializes the Halfling race with the appropriate values.
*/
Halfling::Halfling() : Race::Race(25, Small, 2, Dexterity) {
	whichRace = Half;
}

/* HUMAN CLASS : EXTENDS RACE */
/**
* Human constructor. Initializes the Human race with the appropriate values.
*/
Human::Human() : Race::Race(30, Medium, 2, Strength) {
	whichRace = Hum;
}
