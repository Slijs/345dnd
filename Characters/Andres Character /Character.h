#include "Dwarf.h"
#include "Fighter.h"
#include "Entity.h"
#include <random>
#include <ctime>
#include "Equipment.h"
#pragma once





class Character : public Entity
{
private:
	int dexterity, strength, constitution, intelligence, wisdom, charisma; //abilities

	int dexterityModifier, strengthModifier, constitutionModifier, intelligenceModifier, wisdomModifier, charismaModifier;

	int hitPoints, armorClass;

	int attackBonus, damageBonus;

	Equipment* equipval;



	char* size; //using character pointers (it's basically string)
	int speed;

public:

	Character(); //default constructor
	~Character(); //deconstructor

	Character(int dexterityVal, int strengthVal, int constitutionVal, int intelligenceVal, int wisdomVal, int charismaVal);


	Character(Race characterRace, Class characterClass, int characterLevel, int MeleeOrRanged);

	bool Character::validateNewCharacter();

	int Character::AbilityModifierCalculation(int ability);

	int Character::ArmorClassCalculation(int dexterityValue);

	void Character::hit(int value);

	int Character::getHitPoints();

	string Character::toString();

	void characterArtwork();
	static void titleArtwork();


	int d6();
	int d20();
};


