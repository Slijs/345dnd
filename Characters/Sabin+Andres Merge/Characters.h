#pragma once
#include "Entity.h"
#include "Equipment.h"
#include <cstdlib>
#include <ctime>
#include <string>

class Characters
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

	bool equiped; //start as false changes to true when equip something with bonus for AC

	int attackBonus;
	int damageBonus;

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
	void raceProcess();
	int roll4D6();
	void reOrder();

	void generateAbility();
	void orderArray(int a[]);

	//for corresponding Ability Scores Modifiers and experience based on level
	void abilityScoreMod();		//from Ability Scores
	void detExperience();		//from Level
	void detProficiencyBonus();	//from Level

	void calcArmorClass();      //from equipement

	void calcAttackBonus();		//from STR/DEX mod & proficiency level and base attack bonus
	void calcDamageBonus();		//from STR mod 

	//for equip and dequip stat update
	void updateStatsDQ(int scoreIndex, int removeBonus);	    //should be used when equiping and unequiping 
	void updateStatsEQ(int scoreIndex, int addBonus);

	

public:
	Characters(int, int, int, int, int, int, int, int);
	Characters(int);

	void destroyObject();
	~Characters();


	int getLevel();
	int getScores(int, int);

	void displayStats();   // displays all info on character

	void displayEquip();

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

	///FOR UNIT TEST
	bool validateNewCharacter();
	bool validateProficiency();


};


