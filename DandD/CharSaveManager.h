#pragma once
#ifndef CHARSAVEMANAGER_H
#define CHARSAVEMANAGER_H
#include "CharacterSaveMap.h"
#include "Characters.h"

class CharacterSaveManager {
public:
	static void saveCharacter(Characters *theChar);
	static Characters* loadCharacter();
	static void removeCharacter();
	static string cstrTostr(CString &cstr);
};
#endif