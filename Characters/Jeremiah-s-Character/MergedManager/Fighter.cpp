#include "Fighter.h"

IMPLEMENT_SERIAL(Fighter, Character, 1);

/*
CONSTRUCTOR
*/
//!Parameterized Constructor to set level, race and name. 
Fighter::Fighter(int level, Race race, string name) : Characters(level)
{
	Fighter::name = name;
	detRaceTraits(race);
	initHitPoints();
}

Fighter::Fighter() : Characters(){
	Fighter::name = "Dummy";
	size = Dwarfs::size;
	speed = Dwarfs::speed;
	scoreIncrease(Dwarfs::typeScore, Dwarfs::ScoreIncrease);
	initHitPoints();
}

/*
DESTRUCTOR
*/
Fighter::~Fighter()
{

}

void Fighter::detRaceTraits(Race race)
{
	switch (race)
	{
	case Dwarf:
		size = Dwarfs::size;
		speed = Dwarfs::speed;
		scoreIncrease(Dwarfs::typeScore, Dwarfs::ScoreIncrease);
		break;
	case Elf:
		size = Elves::size;
		speed = Elves::speed;
		scoreIncrease(Elves::typeScore, Elves::ScoreIncrease);
		break;
	case Halfling:
		size = Halflings::size;
		speed = Halflings::speed;
		scoreIncrease(Halflings::typeScore, Halflings::ScoreIncrease);
		break;
	case Human:
		size = Humans::size;
		speed = Humans::speed;
		scoreIncrease(Humans::typeScore, Humans::ScoreIncrease);
		break;
	}


}


//!Function that calculates the initial hitpoints of the character based on the level
void Fighter::initHitPoints()
{
	int level = this->getLevel();
	//At Level 1: HP = max_HitDie + CON_mod
	hitPoints = HIT_DIE + this->getScores(1, 2);
	//For every level: HP = HP + roll_HitDie + CON_mod
	for (int i = 2; i <= level; i++)
	{
		hitPoints += this->rollDice(HIT_DIE) + this->getScores(1, 2);
	}
}

//!Function to displays the fighter stats, calls parent displayStats()
void Fighter::displayStats()
{
	string raceName;
	cout << "Name: " << name << endl;
	if (race == 0)
		cout << "Class: Fighter" << " Race: Dwarf" << endl;
	cout << "Hit Points: " << hitPoints << endl;
	this->Characters::displayStats();

}

//!Function to display fighter battle stats, calls parent displayBattle()
void Fighter::displayBattle()
{
	string raceName;
	cout << "Name: " << name << endl;
	cout << "Class: Fighter";
	cout << " Race: " << raceString[race] << endl;
	cout << "Hit Points: " << hitPoints << endl;
	this->Characters::displayBattle();
}

//!Function to display fighter stats when leveling up, calls parent displayLevelUp()
void Fighter::displayLevelUp()
{
	string raceName;
	cout << "Name: " << name << endl;
	cout << "Class: Fighter";
	cout << " Race: " << raceString[race] << endl;
	cout << "Hit Points: " << hitPoints << endl;
	this->Characters::displayLevelUp();
}

//!Function to display fighter's death, calls parent displayLevelUp() and terminates the program
void Fighter::displayDeath()
{
	cout << "\n" << name;
	Characters::displayDeath();
	cout << "Game Over!" << endl;
	system("PAUSE");
	exit(0);
}

/*!Function for attacking a Monster, generates attack roll and checks it agains Monster's AC
If larger than AC, damage roll is calculated and inflicted on Monster, otherwise attack fails*/
void Fighter::attack(Monster* c)
{

	int aRoll = attackRoll(), dRoll;
	string name;

	cout << this->getName() << " rolled " << aRoll << " for attack!" << endl;

	if (aRoll < c->getArmorClass())
	{
		cout << "Attack missed!" << "\n" << endl;
	}
	else
	{
		cout << "Attack was successful!" << endl;
		dRoll = damageRoll();
		c->receiveDamage(dRoll);

	}
}

/*!Function that reduces hitpoints based on damage taken,
if hitpoints reduce to 0 or less, fighter is dead. Notifies change in character stats*/
void Fighter::receiveDamage(int damage)
{
	hitPoints -= damage;
	cout << damage << " damage was inflicted on " << name << "!" << endl;
	cout << endl;
	if (hitPoints <= 0)
	{
		setIsDead(true);
	}
	currentState();


}

//!Function to recalculate hitpoints when leveling up but adding a roll of hitDice and dexterity modifier
void Fighter::recalcHitPoints()
{
	hitPoints += this->rollDice(HIT_DIE) + this->getScores(1, 2);
}

/*!Function to increase experience when monster is defeated.
Calls parent gainExperience(int) function. Notifies change in character state*/
void Fighter::gainExperience(int gain)
{
	Characters::gainExperience(gain);
	currentState();
}

//!Function for level up processing to increment chosen ability score and recalculates hitpoints

void Fighter::levelUp(int choice)
{
	recalcHitPoints();
	updateAbilityScore(choice);
}

void Fighter::dead()
{
	currentState();
}

void Fighter::currentState()
{
	Notify();
}

//TEST

bool Fighter::validateHitPoints()
{
	int level = this->getLevel();
	int validHit = 10 + this->getScores(1, 2);
	if (level == 1 && hitPoints != validHit)
		return false;
	else if (level > 1 && ((hitPoints < (validHit + (this->getScores(1, 2) + 1) * level) || hitPoints >(validHit + (this->getScores(1, 2) + 10) * level))))
		return false;
	return true;
}
//!test function to validate character death
bool Fighter::validateDeath()
{
	return getIsDead();
}

bool Fighter::validateGainExperience(int exp)
{
	int currentExp = getExp();
	if (currentExp += exp)
		return true;
	return false;
}

// Method for serialization - to be implemented
void Fighter::Serialize(CArchive &ar){
}

bool Fighter::validatePlayerMove(int x, int y){
	// Will user super validatePlayerMove to determine if movement on map is valid.
	if(!this->Characters::validatePlayerMove(x, y))
		return false;

	// Will now determine if player is moving within their range
}