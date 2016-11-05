#pragma once
#include "Characters.h"
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
private:
	const int HIT_DIE = 10; //d10
	int hitPoints;
	Race race;
	string name;
	int speed;

	

public:
	Fighter(int,Race, string);
	~Fighter();


	void initHitPoints();
	void recalcHitPoints();
	void displayStats();
	void displayBattle();
	void displayLevelUp();
	void displayDeath();
	string getName() { return name; }

	//For battle
	void attack(Monster* c);
	void receiveDamage(int);

	void levelUp(int);
	void gainExperience(int);
	void dead();


	void currentState();

	//TEST
	bool validateHitPoints();
	bool validateDeath();
	bool validateGainExperience(int);
};