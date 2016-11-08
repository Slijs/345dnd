/**
*@file CharacterManager.h
*@brief File allowing for creating, loading, editing and deleting saved characters
*/
#pragma once
#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H
#include "Fighter.h"

/**
*@class CharacterManager
*@brief Provides static methods to allow for management of saved characters.
*<p> Provides the user with the ability to either getCharacter() from file, or to createOrEditCharacter(), which will then
*	 be saved to file
*/
class CharacterManager {
public:
	static Fighter* getCharacter(); // Allows user to load Fighter from file to play game
	static void createOrEditCharacter(); // Allows user to create a new Character, or edit a pre-existing one

};

#endif