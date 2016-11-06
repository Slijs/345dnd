#pragma once
#include "Entity.h"
#include "Equipment.h"
#include "Subject.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

/*!
Some changes were made from previous implementation of Characters Class

Fighters have a specific constructor that takes a level. Once this is given, 
the amount of experience and proficiency bonus are determine by the level.

Monsters on the other hand, have a constructor that takes their level 6 integers 
for Scores and the armor class. The rest of their attributes are determined in Monster Class.
In addition, no equipment is equipped upon creation.

For fighters, in their constructor ability scores are randomly generated 
using a 4D6 dice roll and taking the 3 largest values and adding them together. 
Then the highest is set to STR and the second highest to CON, while all others remain arbitrary.

The armor class is dependent on the equipment of the character. 
By default, fighters with Level 1 will only have a "Longsword" equipped 
while all others will be in posession of a "Light Crossbow" and "Padded Armor" for armor. 
If no armor is worn, AC = 10 + CON_Mod + AC_Bonuses where AC_Bonuses can be 
from shield, helmet, boots, and ring. (if the three last ones have a bonus type of AC) 
If armor is worn, AC = Armor_Bonus + CON_Mod + AC_Bonuses

In addition all characters may equip an Armor, Weapon, Boots, Ring, Helmet and Shield. 
When equipping new equipment, the character stats are adjusted to remove whatever effect 
they had if applicable or recalculate AC. MORE INFORMATION ABOUT THIS IN EQUIPMENT CLASS 
While this was implemented in the previous Characters Class, each equip function will
notify a change so that Character Observer will display appropriate character stats

In addition to all this, boolean values were implemented for use in Character Observer
these are inBattle, isDead, and isLevelUp.

New functions were also implemented for leveling up and battle purposes. 
Namely a function to increase experience when gaining experience and trigger level up
if reached the next level lower bound. When leveling up, the character will be allowed
to increment an ability score of their choice and their hp increases as well as the proficiency
bonus if necessary. 
The functions for battle are namely for the calculation of the attack and damage roll as follows:
attackRoll = d20 + attackBonus ,and damageRoll = weaponDice + damageBonus.
*/

class Characters: public Subject
{
private:
	int const MAX_NUM_SCORES = 6;
	//int* diceThrows; only a temporary thing to be used during randomizing with dice
	int scores[2][6]; //will include Ability Scores and Modifiers in 6 by 2 array
	//0=str, 1=dex, 2=con, 3=int, 4=WIS, 5=cha
	
	int exp;
	int level;
	int proficiencyBonus;
	int armorClass; //can update when equip armor, shield, helmet, boots &/or ring
	//or when dex goes up

	Size size;

	bool inBattle;
	bool isDead;
	bool isLevelUp;

	bool equiped; //start as false changes to true when equip something with bonus for AC

	int attackBonus;
	int damageBonus;

	vector<int> position;

	/*
	EQUIPMENT
	*/
	Armor* armor;
	Weapon* weapon;
	Helmet* helmet;
	Shield* shield;
	Boots* boots;
	Ring* ring;

	/*
		HELPER FUNCTIONS ONLY USED IN CHARACTERS CPP
	*/
	//for the random Ability Scores
	int roll4D6();
	void reOrder();

	void generateAbility();
	void orderArray(int a[]);

	//for corresponding Ability Scores Modifiers and experience based on level
	void abilityScoreMod();		//from Ability Scores
	void detExperience();		//from Level
	void detExp();
	void detProficiencyBonus();	//from Level

	void calcArmorClass();      //from equipement

	int processWeaponDice();

	void gainLevel();

	//for equip and dequip stat update
	void updateStatsDQ(int scoreIndex, int removeBonus);	    //should be used when equiping and unequiping 
	void updateStatsEQ(int scoreIndex, int addBonus);

	

public:
	Characters();
	Characters(int, int, int, int, int, int, int, int);
	Characters(int);

	void destroyObject();
	~Characters();


	int getLevel();
	int getExp() { return exp; }
	int getArmorClass() { return armorClass; }
	int getAttackBonus() { return attackBonus; }
	int getDamageBonus() { return damageBonus; }
	int getScores(int, int);
	bool getInBattle();
	bool getIsDead() { return isDead; }
	void setIsDead(bool isDead) { this->isDead = isDead; }
	bool getIsLevelUp() { return isLevelUp; }
	void setIsLevelUp(bool isLevelUp) { this->isLevelUp = isLevelUp; }
	vector<int> getPosition() { return position; }

	void calcAttackBonus();		//from STR/DEX mod & proficiency level and base attack bonus
	void calcDamageBonus();		//from STR mod 

	virtual void displayStats();   // displays all info on character

	void displayEquip();

	virtual void displayBattle();
	virtual void displayLevelUp();

	virtual void displayDeath();

	int rollDice(int);

	//for the equipment
	void equip(Armor*);			//allows for equiping
	void equip(Weapon*);			
	void equip(Helmet*);
	void equip(Boots*);
	void equip(Ring*);
	void equip(Shield*);
	
	

	string currentArmor();
	string currentWeapon();
	string currentShield();
	string currentHelmet();
	string currentBoots();
	string currentRing();

	//For battle
	void startBattle(Characters* c);
	void endBattle();
	int attackRoll();
	int damageRoll();


	
	void gainExperience(int);
	void updateAbilityScore(int);

	//For fighter race
	void scoreIncrease(int, int);

	//For map
	void setPosition(int, int);

	//For Subject
	void currentState();



	///FOR UNIT TEST
	bool validateNewCharacter();
	bool validateProficiency();


};


