#pragma once
#ifndef CHARSAVEMANAGER_H
#define CHARSAVEMANAGER_H
#include "CharacterSaveMap.h"
#include "Characters.h"
#include "Fighter.h"

class CharacterSaveManager {
public:
	static bool saveCharacter(Fighter *theChar);
	static Fighter* loadCharacter();
	static void removeCharacter();
	static void removeCharacter(string name);
	static string cstrTostr(CString &cstr);
};
#endif