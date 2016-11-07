/**
*@file CharSaveManager.h
*@brief Declaration of the CharacterSaveManager map.
*<p> Allows saving, loading and deletion of Characters
*/
#pragma once
#ifndef CHARSAVEMANAGER_H
#define CHARSAVEMANAGER_H
#include "stdafx.h"
#include "CharacterSaveMap.h"
#include "Characters.h"
#include "Fighter.h"

class CharacterSaveManager {
public:
	static void saveCharacter(Fighter *theChar);
	static Character* loadCharacter();
	static void removeCharacter();
	static string cstrTostr(CString &cstr);
};
#endif