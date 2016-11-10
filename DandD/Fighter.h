/**
*@file Fighter.h
@brief Implementation of Fighter, which extends Characters
*/
#pragma once
#include "Characters.h"
#include "Item.h"
#include "Container.h"
#include "Entity.h"
#include "Dwarf.h"
#include "Monster.h"

/*!
This class inherits from Characters and creates a Fighter character. All fighters are created with a level and a name. Fighters have a constant Hit_Die = d10. This value is used to calculate the hit points as follows: At level 1: HitPoints = Hit_Die_Max + CON_mod = 10 + CON_mod With each level gained: HitPoints = HitPoints + Hit_Die_Roll + CON_mod
All other information about the fighter is generated in the Characters class See Characters class for more details.

Additional functions were implemented for battle and leveling up.
Namely functions to attack a monster, to receive damage which may result in character death
(leading to Game Over and termination of program), to gain experience which
will trigger level up when applicable
*/


class Monster;

class Fighter : public Characters
{
protected:
	DECLARE_SERIAL(Fighter);
private:
	const int HIT_DIE = 10; //d10
	const string _HIT_DIE_STRING = "1d10";
	int hitPoints;
	int maxHitPoints;
	Race race;
	Size size;
	string name;
	int speed;
	void detRaceTraits(Race race);

	Container* backpack;

public:
	Fighter(int, Race, string);
	Fighter(int level, Race race, string name, int STR, int DEX, int CON, int INT, int WIS, int CHA);
	Fighter(); // Default constructor for Dummy Fighter
	~Fighter();


	void initHitPoints();
	void recalcHitPoints();
	void displayStats();
	void displayBattle();
	void displayLevelUp();
	void displayDeath();
	string getName() { return name; }
	Race getRace() { return race; };
	void setName(string name);
	void setRace(Race nRace);

	//For battle
	void attack(Monster* c);
	void receiveDamage(int);

	void levelUp(int);
	void gainExperience(int);
	void dead();

	void currentState();

	//For equip
	void equipOptions();


	void equip(Armor*);			//allows for equiping
	void equip(Weapon*);
	void equip(Helmet*);
	void equip(Boots*);
	void equip(Ring*);
	void equip(Shield*);
	void equip(Belt*);

	void deequipArmor();
	void dequipWeapon();
	void deequipHelmet();
	void deequipBoots();
	void deequipRing();
	void deequipShield();
	void deequipBelt();

	void displayEquiped();
	void displayBackpack();

	//TEST
	bool validateHitPoints();
	bool validateDeath();
	bool validateGainExperience(int);

	bool validatePlayerMove(int x, int y);
	bool validateChestWithinRange(int x, int y);

	virtual void Serialize(CArchive &ar);
};
