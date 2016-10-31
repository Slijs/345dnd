#include "Fighter.h"

/*
	CONSTRUCTOR
*/
Fighter::Fighter(int level, string name) :Characters(level, name)
{
	Fighter::level = level;
	Fighter::name = name;
	initHitPoints();
}

/*
	DESTRUCTOR
*/
Fighter::~Fighter()
{

}

//Calculates the Hitpoints of the character
void Fighter::initHitPoints()
{ 
	//At Level 1: HP = max_HitDie + CON_mod
	hitPoints = HIT_DIE + this->getScores(1, 2);
	//For every level: HP = HP + roll_HitDie + CON_mod
	for(int i = 2; i <= level; i++)
	{
		hitPoints += this->rollDice(HIT_DIE) + this->getScores(1, 2);
	}
}

//Displays the stats of the character
void Fighter::displayStats()
{
	cout << "Name: " << name << endl;
	cout << "Class: Fighter" << endl;
	cout << "Hit Points: " << hitPoints << endl;
	this->Characters::displayStats();

}


//TEST

bool Fighter::validateHitPoints()
{
	int validHit = 10 + this->getScores(1, 2);
	if (level == 1 && hitPoints != validHit)
		return false;
	else if (level > 1 && ((hitPoints < (validHit + (this->getScores(1, 2) + 1) * level) || hitPoints >(validHit + (this->getScores(1, 2)+10) * level))))
		return false;
	return true;
}
