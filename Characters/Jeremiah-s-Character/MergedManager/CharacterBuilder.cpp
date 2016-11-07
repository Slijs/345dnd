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
* Creates a new Character of Fighter class with randomized ability scores and the requested parameters
*@param level The desired starting level of the character
*@param race The desired Race of the Character
*@param name The desired name of the Character
*@return Character* pointing to the new Character
*/
Character* CharacterBuilder::create(int level, Race race, string name)
{
	Dice _theDie;
	Character *theChar = new Fighter(level, race, name, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"));
	return theChar;
}