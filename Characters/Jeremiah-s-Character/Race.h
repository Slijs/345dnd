/**
*@file Race.h
*@brief Provides declaration of the Race class and its subclasses
*<p> This file outlines the declaration of the Race class and its subclasses. Race is used
*    to define the size and speed of a Character, in addition to the special abilities modifiers
*	 that each race provides.
*/

#ifndef RACE_H
#define RACE_H
#include <string>
using namespace std;

/*! Size enumerated type is used to differentiate between Character sizes */
enum Size { Small, Medium, Large };	// Used to differentiate between sizes

/*! Race enumerated type is used to differentiate between Character races */
enum RaceType {Dwar, El, Half, Hum}; // Used to determine Race Type

/*! Abilities enumerated type is used as an index in the Character's abilities matrix */
enum Abilities;	// Forward declaration of the Abilities enumerated type

/**
*@class Race
*@brief Implementation of Races for Characters
*<p> This is the Race class. A Character's Race governs their size, speed, and the special
*	 ability modifier that they receive. Accessors are available to retrieve these values.
*	 Mutators are not allowed as Races are not mutable
*/
class Race {
private:
	int raceSpeed;	// Speed of the race
	Size raceSize;	// Size of the race
	int ablmod;		// Ability modifier of the race
	Abilities modified;	// Ability that gets modified by ablMod
	

protected:
	/* CONSTRUCTOR */
	Race();	// This is protected so that only those classes that extend Race can access it
	RaceType whichRace;	// Will be used to return string representing the race

public:
	/* ACCESSORS  */
	Race(int raceSpeed, Size raceSize, int attMod, Abilities modified);
	int getRaceSpeed();
	Size getRaceSize();
	int getAblMod();
	Abilities getAbilityModified();
	string getWhichRace();

	/* DESTRUCTOR */
	~Race() {};
};

/**
*@class Dwarf
*@brief Implementation of Dwarf race
*<p> This is the Dwarf race. Dwarves have the following important characteristics:
*<p><b>Speed:</b> 25
*<p><b>Size:</b> Medium
*<p><b>Ability Modifier:</b> +2 to Strength
*<p> Dwarves do not introduce any new members not included in Race.
*/
class Dwarf : public Race {
public:
	/* CONSTRUCTOR  */
	Dwarf();
	~Dwarf() {}
};

/**
*@class Elf
*@brief Implementation of Elf race
*<p> This is the Elf race. Elves have the following important characteristics:
*<p><b>Speed:</b> 30
*<p><b>Size:</b> Medium
*<p><b>Ability Modifier:</b> +2 to Dexterity
*<p> Elves do not introduce any new members not included in Race.
*/
class Elf : public Race {
public:
	/* CONSTRUCTOR */
	Elf();
	~Elf() {}
};

/**
*@class Halfling
*@brief Implementation of Halfling race
*<p> This is the Halfling race. Halflings have the following important characteristics:
*<p><b>Speed:</b> 25
*<p><b>Size:</b> Small
*<p><b>Ability Modifier:</b> +2 to Dexterity
*<p> Halflings do not introduce any new members not included in Race.
*/
class Halfling : public Race {
public:
	Halfling();
	~Halfling() {}
};

/**
*@class Human
*@brief Implementation of Human race
*<p> This is the Human race. Humans have the following important characteristics:
*<p><b>Speed:</b> 30
*<p><b>Size:</b> Medium
*<p><b>Ability Modifier:</b> +2 to Strength
*<p> Halflings do not introduce any new members not included in Race.
*/
class Human : public Race {
public:
	Human();
	~Human() {}
};

#endif
