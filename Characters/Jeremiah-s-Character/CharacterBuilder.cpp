/**
*@file CharacterBuilder.cpp
*@brief Definition of the CharacterBuilder class.
*
*<p>CharacterBuilder is used to initialize a Character with random ability scores.
*/

#include "stdafx.h"
#include "CharacterBuilder.h"
#include "Dice.h"
#include <iostream>
using namespace std;

/**
* Creates a new Character with randomized ability scores and the requested parameters
*@param name The desired name of the Character
*@param theClass The desired Class of the Character
*@param theRace The desired Race of the Character
*@param level The desired starting level of the character
*
*@return Character* pointing to the new Character
*/
Character * CharacterBuilder::create(string name, ClassType theClass, RaceType theRace, int level)
{
	Dice _theDie;
	// This for loop rolls the die several times, to make sure that the value it has been seeded with does not lead to the same result each time
	for(int i = 0; i < 10; i++)
		_theDie.roll("2d12");
	Character *theChar = new Character(name, level, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), theClass, theRace);
	return theChar;
}
