#pragma once
#ifndef CHARSAVEMANAGER_H
#define CHARSAVEMANAGER_H
#include "stdafx.h"
#include "CharacterSaveMap.h"
#include "Character.h"

class CharacterSaveManager {
public:
	static void saveCharacter(Character *theChar);
	static Character* loadCharacter();
	static void removeCharacter();
	static string cstrTostr(CString &cstr);
};
#endif
