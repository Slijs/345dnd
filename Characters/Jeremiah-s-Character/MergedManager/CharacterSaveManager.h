/**
*@file CharacterSaveManager.h
*@brief Declaration of CharacterSaveManager, which allows Characters to be Serialized
*	and saved to file.
*/
#pragma once
#ifndef CHARSAVEMANAGER_H
#define CHARSAVEMANAGER_H
#include "stdafx.h"
#include "CharacterSaveMap.h"
#include "Characters.h"

/**
*@class CharacterSaveManager
*@brief This class allows for saving, loading and deleting Characters that have been saved to disk.
*/
class CharacterSaveManager {
public:
	static void saveCharacter(Characters *theChar); // Will Save Character to file
	static Characters* loadCharacter();	// Will Load Character from File
	static void removeCharacter(); // Will remove Character from saved Characters
	static string cstrTostr(CString &cstr); // Converts CString to string
};
#endif
