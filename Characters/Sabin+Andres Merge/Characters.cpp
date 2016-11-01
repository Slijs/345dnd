#include "Characters.h"
#include "Equipment.h"
#include <iomanip>
using namespace std;

int experience[2][20] = {
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 },
	{ 0, 300, 900, 2700, 6500, 14000, 23000, 34000, 48000, 64000, 85000, 100000, 120000, 140000, 165000, 195000, 225000, 265000, 305000, 355000 }
};

//CONSTRUCTOR
//Monster
Characters::Characters(int level, int STR, int DEX, int CON, int INT, int WIS, int CHA, int armorClass)
{
	this->level = level;
	this->armorClass = armorClass;
	scores[0][0] = STR;
	scores[0][1] = DEX;
	scores[0][2] = CON;
	scores[0][3] = INT;
	scores[0][4] = WIS;
	scores[0][5] = CHA;

	detProficiencyBonus();
	abilityScoreMod();
	calcAttackBonus();
	calcDamageBonus();
}

//Hero
Characters::Characters(int level) 
{
	this->level = level;
	armorClass = 0;
	//call to set proficiencyBonus and exp
	detExperience();  
	detProficiencyBonus(); 

	srand(time(NULL));

	//call to set abilityScore and modifiers
	generateAbility();
	if (level == 1)
	{
		armor = new Armor();
		weapon = new Weapon("Longsword", "1d8","melee");
	}
	else
	{
		armor = new Armor("Padded Armor", 11);
		weapon = new Weapon("Light Crossbow", "1d8", "ranged");
	}
	shield = new Shield();
	boots = new Boots();
	ring = new Ring();
	helmet = new Helmet();

	calcArmorClass();

	//calculate attackBonus and DamageBonus
	calcAttackBonus();
	calcDamageBonus();


}
//DESTRUCTORS
void Characters::destroyObject()
{
}

Characters::~Characters()
{
	destroyObject();
	armor->~Armor();
	weapon->~Weapon();
	shield->~Shield();
	boots->~Boots();
	ring->~Ring();
	helmet->~Helmet();
}

//Accessor to level
int Characters::getLevel()
{
	return level;
}

//Accessor to specific score value
int Characters::getScores(int i, int j)
{
	return scores[i][j];
}



//DICE MECHANISM FOR CHARACTER
int Characters::rollDice(int i)
{
	return rand() % i + 1;
}

//Rolls 4 dice and returns sum of 3 largest values
int Characters::roll4D6()
{
	int temp;
	int rolls[4];
	for (int i = 0; i <= 3; i++)
	{
		rolls[i] = rollDice(6);

	}

	for (int i = 1; i <= 3; i++)
	{
		if (rolls[i] > rolls[i - 1])
		{
			temp = rolls[i];
			rolls[i] = rolls[i - 1];
			rolls[i - 1] = temp;
		}
	}

	return rolls[0] + rolls[1] + rolls[2];
}

//rolls 4D6 for each ability score 
void Characters::generateAbility()
{
	int temp;
	int abscor[6];
	for (int i = 0; i < MAX_NUM_SCORES; i++)
	{
		abscor[i] = roll4D6();
	}
	
	orderArray(abscor);
	
	scores[0][0] = abscor[0];
	scores[0][2] = abscor[1];
	scores[0][1] = abscor[2];

	for (int i = 3; i < MAX_NUM_SCORES; i++)
	{
		scores[0][i] = abscor[i];
	}

	abilityScoreMod();
}

//Reorganize the array such that the two largest values are at index 0 and 1
void Characters::orderArray(int a[])
{
	int temp;
	for (int i = 0; i < 2; i++)
	{
		for (int j = i + 1; j<MAX_NUM_SCORES; j++)
		{
			if (a[j]>a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

//Calculates the ability score modifiers with formula floor((score-10)/2)
void Characters::abilityScoreMod()
{
	//TO BE DEFINED
	//MODIFIER = (ABILITY SCORE - 10)/2
	
	double modifier;
	for (int i = 0; i < MAX_NUM_SCORES; i++)
	{
		modifier = ((double)scores[0][i] - 10) / 2;
		modifier = floor(modifier);
		scores[1][i] = (int)modifier;
	}
}

//BASED ON LEVEL: MIGHT BE MERGED (SINCE BOTH BASED ON LEVEL)
//CREATE A ARRAY THAT HOLDS BOTH (TO FIND LEVEL-1 FOR COLUMN INDEX, ROW: 0 FOR EXP AND 1 FOR PROF. BONUS)
void Characters::detExperience()
{
	exp = experience[1][level - 1];
}

//Proficiency bonus is set based on the level
void Characters::detProficiencyBonus()
{
	if (level <= 4)
		proficiencyBonus = 2;
	else if (level <= 8)
		proficiencyBonus = 3;
	else if (level <= 12)
		proficiencyBonus = 4;
	else if (level <= 16)
		proficiencyBonus = 5;
	else
		proficiencyBonus = 6;
}

//calculates the armorclass based on the equipment 
void Characters::calcArmorClass()
{
	//If no equipment with ACBonus is equipped 
	if (armor->compareName("NONE") && shield->compareName("NONE") && boots->compareName("NONE") && helmet->compareName("NONE") && ring->compareName("NONE"))
		armorClass = 10 + scores[1][1];
	else
	{
		//if there is armor equipped
		if (!(armor->compareName("NONE")))
			armorClass += armor->getACBonus();
		else
			//If no armor is equiped
			armorClass = 10 + scores[1][1];
		//if shield is equipped add ACbonus to AC
		if (!(shield->compareName("NONE")))
			armorClass += shield->getACBonus();
		//if boots are equipped and bonus type is AC add bonus to Armor Class
		if (!boots->compareName("NONE") && boots->getBonusType() == 3)
			armorClass += boots->getBonus();
		//if helmet are equipped and bonus type is AC add bonus to Armor Class
		if (!helmet->compareName("NONE") && helmet->getBonusType() == 3)
			armorClass += helmet->getBonus();
		//if ring are equipped and bonus type is AC add bonus to Armor Class
		if (!ring->compareName("NONE") && ring->getBonusType() == 5)
			armorClass += ring->getBonus();
	}
}

//RELATED TO ATTACK AND DAMAGE
//If using ranged weapon add DEX mod to Proficiency Bonus
//Otherwise add STR mod instead
void Characters::calcAttackBonus()
{
	attackBonus = proficiencyBonus;
	if (weapon->compareType("ranged"))
		attackBonus += scores[1][1];  //add dex mod if ranged weapon
	else 
		attackBonus += scores[1][0]; //add str mod if melee or no weapon
}

//Damage bonus is DEX mod if ranged weapon
//otherwise it is STR mod
void Characters::calcDamageBonus()
{
	if (weapon->compareType("ranged"))
		damageBonus = scores[1][1];
	else
		damageBonus = scores[1][0];
}

//Displays the character's stats
void Characters::displayStats()
{
	cout << "Level: " << level << "	EXP: " << exp << endl;
	cout << "STR: " << scores[0][0] << "(" << scores[1][0] << ")";
	cout << "\nDEX: " << scores[0][1] << "(" << scores[1][1] << ")";
	cout << "\nCON: " << scores[0][2] << "(" << scores[1][2] << ")";
	cout << "\nINT: " << scores[0][3] << "(" << scores[1][3] << ")";
	cout << "\nWIS: " << scores[0][4] << "(" << scores[1][4] << ")";
	cout << "\nCHA: " << scores[0][5] << "(" << scores[1][5] << ")"<< endl;
	cout << "Proficiency Bonus: +" << proficiencyBonus;
	cout << "\nArmor Class: " << armorClass;
	cout << "\nEquipment:" << endl;
	
	displayEquip();

	cout << "Attack Bonus: " << attackBonus << endl;
	cout << "Damage Bonus: " << damageBonus << endl;
}

//Displays the equipment the character has equiped
void Characters::displayEquip()
{
	printf("%-10s%-15s  %-10s%-15s\n", "Armor: ", armor->getName().c_str(), "Weapon: ", weapon->getName().c_str());

	printf("%-10s%-15s  %-10s%-15s\n", "Shield: ", shield->getName().c_str(), "Helmet: ", helmet->getName().c_str());
	
	printf("%-10s%-15s  %-10s%-15s \n", "Ring: ", ring->getName().c_str(), "Boots: ", boots->getName().c_str());
}



//EQUIP FUNCTIONS
//Allows to equip a new Armor, Weapon, Helmet, Boots, Ring and Shield
//If wish to de-equip use default constructor of these Classes
void Characters::equip(Armor* a)
{
	armor = a;
	calcArmorClass();
}

void Characters::equip(Weapon* w)
{
	weapon = w;
	calcDamageBonus();
	calcAttackBonus();
}

void Characters::equip(Helmet* h)
{
	int bonus = helmet->getBonus();
	if (helmet->getBonusType() == 1) //INT
		updateStatsDQ(3, bonus);
	else if (helmet->getBonusType() == 2) //WIS
		updateStatsDQ(4, bonus);
	
	helmet = h;
	bonus = helmet->getBonus();
	if (helmet->getBonusType() == 1) //INT
		updateStatsEQ(3, bonus);
	else if (helmet->getBonusType() == 2) //WIS
		updateStatsEQ(4, bonus);

	calcArmorClass();
}

void Characters::equip(Boots* b)
{
	int bonus = boots->getBonus();
	if (boots->getBonusType() == 1) //DEX
		updateStatsEQ(1, bonus);
	

	boots = b;
	bonus = boots->getBonus();

	if (boots->getBonusType() == 1) //INT
		updateStatsEQ(1, bonus);

	calcArmorClass();
}

void Characters::equip(Ring* r)
{
	int bonus = ring->getBonus();
	if (ring->getBonusType() == 1) //STR
		updateStatsDQ(0, bonus);
	else if (ring->getBonusType() == 2) //CON
		updateStatsDQ(2, bonus);
	else if (ring->getBonusType() == 3) //WIS
		updateStatsDQ(4, bonus);
	else if (ring->getBonusType() == 3) //CHA
		updateStatsDQ(5, bonus);
	
	ring = r;

	bonus = ring->getBonus();
	if (ring->getBonusType() == 1) //STR
	{
		updateStatsEQ(0, bonus);
	}
	else if (ring->getBonusType() == 2) //CON
		updateStatsEQ(2, bonus);
	else if (ring->getBonusType() == 3) //WIS
		updateStatsEQ(4, bonus);
	else if (ring->getBonusType() == 3) //CHA
		updateStatsEQ(5, bonus);

	calcArmorClass();
}

void Characters::equip(Shield* s)
{
	shield = s;
}



//Helper function to update stats when de-equipping an equipment
void Characters::updateStatsDQ(int scoreIndex, int removeBonus)
{
	scores[0][scoreIndex] -= removeBonus;
}

//Helper function to update stats when equipping an equipment
void Characters::updateStatsEQ(int scoreIndex, int addBonus)
{
	scores[0][scoreIndex] += addBonus;
}


string Characters::currentArmor()
{
	return armor->getName();
}

string Characters::currentWeapon()
{
	return weapon->getName();
}
string Characters::currentShield()
{
	return shield->getName();
}
string Characters::currentHelmet()
{
	return helmet->getName();
}
string Characters::currentBoots()
{
	return boots->getName();
}
string Characters::currentRing()
{
	return ring->getName();
}

/*
	FOR UNIT TEST
*/

///Check to see if score values are valid (3 to 18)
bool Characters::validateNewCharacter()
{
	for (int i = 0; i < 6; i++)
	{
		if (scores[0][i]<3 || scores[0][i]>18)
			return false;
		//if (scores[1][i] != (int)floor(((double)scores[0][i] - 10) / 2))
		//	return false;
	}
	
	return true;
}

//Check if proficiency bonus is correct
bool Characters::validateProficiency()
{
	if (level <= 4 && proficiencyBonus != 2)
		return false;
	else if (level> 4 && level <= 8 && proficiencyBonus != 3)
		return false;
	else if (level> 8 && level <= 12 && proficiencyBonus != 4)
		return false;
	else if (level> 12 && level <= 16 && proficiencyBonus != 5)
		return false;
	else if (level > 16 && proficiencyBonus != 6)
		return false;
	else
		return true;
}

