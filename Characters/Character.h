/**
*@file Character.h
*@brief Definition of the Character class.
*
* This file outlines the implementation of the Character class, and all methods and members a Character should have.
*/

#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>	// Will allow Character class to use string members
#include "Classes.h"
#include "Race.h"
#include "Item.h"
#include "Subject.h"
#include "Dice.h"
using namespace std;

/**
* The enumerated type 'Abilities' will be used as a key whenever accessing the Character's abilities
*/
enum Abilities { Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma };

/**
*@class Character 
*@brief Implementation of the Character for the game
*/
class Character : public Subject {
private:

	Dice _theDie;

	/* CHARACTER BACKGROUND INFO */
	string _name;	// Character's Name
	Classes* _charClass;	// Character's class
	Race *_charRace;		// Character's race
	Item *_inventory;

					/* CHARACTER STATS */
	int _level;			// Character's current level
	int _exp;		// Character's experience points
	int _maxHP;			// Character's maximum HP
	int _currentHP;		// Character's current HP
	int _initiative;		// Character's initiative
	bool _isDead;	// Returns true if the Character is dead

						/* ABILITIES */
	int _abilitiesAndMods[2][6];

public:

	Character();	// Default constructor
	Character(string name, int lvl, int str, int dex, int con, int intel, int wis, int cha, ClassType theirClass, RaceType theirRace);

	~Character();

	/* ACCESSORS */
	string getName();
	int getLevel(); 
	int getExp();
	int getMaxHP();
	int getCurrentHP(); 
	int getSpeed();
	int getInitiative();

	int getStrength();
	int getDexterity();
	int getConstitution();
	int getIntelligence();
	int getWisdom();
	int getCharisma();
	int getSize();

	string getClass();
	string getRace();

	int getArmourClass();
	int getAttackBonus();
	int getDamageBonus();
	int getProficiencyBonus();

	/* MUTATORS */

	void equipShield(int bonus);
	void equipArmour(int bonus);
	void equipWeapon(int damage);
	void equipBoots();
	void equipRing();
	void equipHelmet();

	void removeShield();
	void removeArmour();
	void removeWeapon();
	void removeBoots();
	void removeRing();
	void removeHelmet();

	bool isShieldEquipped();
	bool isArmourEquipped();
	bool isWeaponEquipped();
	bool areBootsEquipped();
	bool isRingEquipped();
	bool isHelmetEquipped();
	bool isDead();

	void hit(int damage);
	void addXP(int amount);

	/* TESTING METHODS */
	bool Character::validateNewCharacter(); // Ensures that character's ability scores are between 3 and 18
};

#endif