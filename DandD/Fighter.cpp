#include "Fighter.h"

IMPLEMENT_SERIAL(Fighter, Characters, 1);

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
		hitPoints += _die.roll("1d" + HIT_DIE) + this->getScores(1, 2);
	}
	maxHitPoints = hitPoints;
}

//!Function to displays the fighter stats, calls parent displayStats()
void Fighter::displayStats()
{
	string raceName;
	cout << "Name: " << name << endl;
	if (race == 0)
		cout << "Class: Fighter" << " Race: Dwarf" << endl;
	cout << "Hit Points: " << hitPoints << "/" << maxHitPoints << endl;
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
	hitPoints += _die.roll("1d" + HIT_DIE) + this->getScores(1, 2);
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

/**
* Implementation of Serialization to allow Fighter to be Serialized to file
*/
void Fighter::Serialize(CArchive &ar){
	Characters::Serialize(ar);
	if(ar.IsStoring()) {
		ar << hitPoints;
		ar << race;
		ar << size;
		CString c_name(name.c_str());
		ar << c_name;
		ar << speed;
	}
	else {
		ar >> hitPoints;
		int temp = 0;
		ar >> temp;
		race = Race(temp);
		ar >> temp;
		size = Size(temp);
		CString c_name = "";
		ar >> c_name;
		name = "";
		int strlen = c_name.GetLength();
		for (int i = 0; i < strlen; ++i) {
			name += c_name.GetAt(i);
		}
		ar >> speed;
	}
}

bool Fighter::validatePlayerMove(int x, int y) {
	char posInQuestion = 'c';
	// Will user super validatePlayerMove to determine if movement on map is valid.
	if (!this->Characters::validatePlayerMove(x, y))
		return false;
	
	// Moving less than or equal to range up
	if (position[0] - x <= speed && position[1] - y == 0) {
		for (int i = position[0] - 1; i > x; --i) {
			// Will determine if each square the character is trying to move to can be landed on.
			// Destination does not have to be verified, as this is done by Characters
			posInQuestion = _map->at(i).at(y);
			if (!_validPosition(posInQuestion)) {
				return false;
			}
		}
		return true;

	// Moving less than or equal to range down
	}
	else if (x - position[0] <= speed && position[1] - y == 0) {
		for (int i = position[0] + 1; i < x; ++i) {
			// Will determine if each square the character is trying to move to can be landed on
			// Destination does not have to be verified, as this is done by Characters
			posInQuestion = _map->at(i).at(y);
			if (!_validPosition(posInQuestion)) {
				return false;
			}
		}
		return true;
	}

	// Moving less than or equal to range left
	else if (x - position[0] == 0 && position[1] - y <= speed) {
		for (int i = position[1] - 1; i > x; --i) {
			// Will determine if each square the character is trying to move to can be landed on
			// Destination does not have to be verified, as this is done by Characters
			posInQuestion = _map->at(x).at(i);
			if (!_validPosition(posInQuestion)) {
				return false;
			}
		}
		return true;
	}

	// Moving less than or equal to range right
	else if (x - position[0] == 0 && y - position[1] <= speed) {
		for (int i = position[1] + 1; i < x; ++i) {
			// Will determine if each square the character is trying to move to can be landed on
			// Destination does not have to be verified, as this is done by Characters
			posInQuestion = _map->at(x).at(i);
			if (!_validPosition(posInQuestion)) {
				return false;
			}
		}
		return true;
	}
	// Moving up and left less than or equal to range squares (2squares NorthWest)
	else if (position[0] - x <= speed && position[1] - y <= speed && position[0] - x == position[1] - y) {
		for (vector<int> pos = {position[0] - 1, position[1] - 1}; pos[0] > x; pos[0] -= 1) {
			// Will determine if each square the character is trying to move to can be landed on
			// Destination does not have to be verified, as this is done by Characters
			
			posInQuestion = _map->at(pos[0]).at(pos[1]);
			if (!_validPosition(posInQuestion)) {
				return false;
			}
			// Decrements the y value of the position being tested
			pos[1] -= 1;
		}
		return true;
	}

	// Moving up and right less than or equal to range squares (2squares NorthWest)
	else if (position[0] - x <= speed && y - position[1] <= speed && position[0] - x == position[1] - y) {
		for (vector<int> pos = { position[0] - 1, position[1] + 1 }; pos[0] > x; pos[0] -= 1) {
			// Will determine if each square the character is trying to move to can be landed on
			// Destination does not have to be verified, as this is done by Characters

			posInQuestion = _map->at(pos[0]).at(pos[1]);
			if (!_validPosition(posInQuestion)) {
				return false;
			}
			// Increments the y value of the position being tested
			pos[1] += 1;
		}
		return true;
	}
	// Moving down and left less than or equal to range squares (2squares NorthWest)
	else if (x - position[0] <= speed && position[1] - y <= speed && position[0] - x == position[1] - y) {
		for (vector<int> pos = { position[0] + 1, position[1] - 1 }; pos[0] < x; pos[0] += 1) {
			// Will determine if each square the character is trying to move to can be landed on
			// Destination does not have to be verified, as this is done by Characters

			posInQuestion = _map->at(pos[0]).at(pos[1]);
			if (!_validPosition(posInQuestion)) {
				return false;
			}
			// Decrements the y value of the position being tested
			pos[1] -= 1;
		}
		return true;
	}
	// Moving down and right less than or equal to range squares (2squares NorthWest)
	else if (x - position[0] <= speed && y - position[1] <= speed && position[0] - x == position[1] - y) {
		for (vector<int> pos = { position[0] + 1, position[1] + 1 }; pos[0] < x; pos[0] += 1) {
			// Will determine if each square the character is trying to move to can be landed on
			// Destination does not have to be verified, as this is done by Characters

			posInQuestion = _map->at(pos[0]).at(pos[1]);
			if (!_validPosition(posInQuestion)) {
				return false;
			}
			// Increments the y value of the position being tested
			pos[1] += 1;
		}
		return true;
	}

	// If this point has been reached, then the Character is not moving in a vector that is allowed, so false will be returned
	return false;
}