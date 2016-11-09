#include "Fighter.h"

IMPLEMENT_SERIAL(Fighter, Characters, 1);

/* CONSTRUCTOR */

//!Parameterized constructor to set all att of Fighter
Fighter::Fighter(int level, Race race, string name, int STR, int DEX, int CON, int INT, int WIS, int CHA) : Characters(level, STR, DEX, CON, INT, WIS, CHA){
	Fighter::name = name;
	detRaceTraits(race);
	initHitPoints();
	this->race = race;

	//gamecomponent attributes
	this->_image_path = SingletonFilePathAndFolderManager::getInstance()->_player_image_path;
	this->_componentName = "Player";
	this->_componentImage = nullptr;
	this->_componentType = gameplayGridComponentTypes::character;
	this->_componentChar = SimplifiedMapSymbols::_Player_;
	this->_obstructionToPlayer = false;

	backpack = new Container();
}

//!Parameterized Constructor to set level, race and name. 
Fighter::Fighter(int level, Race race, string name) : Characters(level)
{
	Fighter::name = name;
	detRaceTraits(race);
	initHitPoints();
	this->race = race;
	//gamecomponent attributes
	this->_image_path = SingletonFilePathAndFolderManager::getInstance()->_player_image_path;
	this->_componentName = "Player";
	this->_componentImage = nullptr;
	this->_componentType = gameplayGridComponentTypes::character;
	this->_componentChar = SimplifiedMapSymbols::_Player_;
	this->_obstructionToPlayer = false;
}

Fighter::Fighter() : Characters(){
	Fighter::name = "Dummy";
	size = Dwarfs::size;
	speed = Dwarfs::speed;
	scoreIncrease(Dwarfs::typeScore, Dwarfs::ScoreIncrease);
	initHitPoints();
	this->race = Dwarf;

	//gamecomponent attributes
	this->_image_path = SingletonFilePathAndFolderManager::getInstance()->_player_image_path;
	this->_componentName = "Player";
	this->_componentImage = nullptr;
	this->_componentType = gameplayGridComponentTypes::character;
	this->_componentChar = SimplifiedMapSymbols::_Player_;
	this->_obstructionToPlayer = false;
}

/*
DESTRUCTOR
*/
Fighter::~Fighter()
{

}

/**
*Will allow a Fighter's race to change. Will undo current Race stats and update them with the stats of the new race
*/
void Fighter::setRace(Race nRace){
	// First, will change Fighter's stats to remove ScoreIncrease from current race
	switch (race)
	{
	case Dwarf:
		scoreIncrease(Dwarfs::typeScore, -(Dwarfs::ScoreIncrease));
		break;
	case Elf:
		scoreIncrease(Elves::typeScore, -(Elves::ScoreIncrease));
		break;
	case Halfling:
		scoreIncrease(Halflings::typeScore, -(Halflings::ScoreIncrease));
		break;
	case Human:
		scoreIncrease(Humans::typeScore, -(Humans::ScoreIncrease));
		break;
	}
	// Will change the current race
	race = nRace;
	// Then will determine race traits based on the Character's new race
	detRaceTraits(nRace);
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
		//string toRoll = "1d" + HIT_DIE;
		hitPoints += _die.roll(_HIT_DIE_STRING) + this->getScores(1, 2);
	}
	maxHitPoints = hitPoints;
}

//!Function to displays the fighter stats, calls parent displayStats()
void Fighter::displayStats()
{
	string raceName;
	cout << "Name: " << name << endl;
	cout << "Class: Fighter" << " Race: " << raceString[race] << endl;
	cout << "Hit Points: " << hitPoints << "/" << maxHitPoints << endl;
	this->Characters::displayStats();

	for (int i = 0; i < backpack->getNumContents(); i++)
		cout << backpack->getContents()[i]->getName() << " ";
	cout << endl;

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
	hitPoints += _die.roll(_HIT_DIE_STRING) + this->getScores(1, 2);
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


void Fighter::equipOptions()
{

}

/*EQUIP FUNCTIONS:
Allows to equip a new Armor, Weapon, Helmet, Boots, Ring and Shield
//If wish to de-equip use default constructor of these Classes
*/

//!Function to equip armor. Previous AC bonus is removed and recalculate the AC based on new armor. Triggers redisplay of stats



void Fighter::equip(Armor* a)
{
	//Remove bonus
	if (armor->getEnchantmentValues()[7] == 0)
		armorClass -= 10;
	else
		armorClass -= armor->getEnchantmentValues()[7];
	armor = a;
	//Add Bonus
	armorClass += armor->getEnchantmentValues()[7];

	currentState();
}

//!Function to equip weapon. Recalculates damage bonus and attack bonus based on weapon equipped. Triggers redisplay of stats
void Fighter::equip(Weapon* w)
{
	weapon = w;
	calcDamageBonus();
	calcAttackBonus();
	currentState();
}

//!Function to equip helmet. Previous bonus is removed and recalculate the bonus based on new helmet. Triggers redisplay of stats.
void Fighter::equip(Helmet* h)
{
	updateStatsDQ(helmet);

	helmet = h;

	updateStatsEQ(helmet);

	currentState();
}
//!Function to equip boots. Previous bonus is removed and recalculate the bonus based on new boots. Triggers redisplay of stats.
void Fighter::equip(Boots* b)
{
	updateStatsDQ(boots);

	boots = b;

	updateStatsEQ(boots);

	currentState();
}

//!Function to equip ring. Previous bonus is removed and recalculate the bonus based on new ring. Triggers redisplay of stats.
void Fighter::equip(Ring* r)
{
	updateStatsDQ(ring);

	ring = r;

	updateStatsEQ(ring);

	currentState();
}

//!Function to equip shield. Previous AC bonus is removed and recalculate the AC based on new shield. Triggers redisplay of stats
void Fighter::equip(Shield* s)
{
	updateStatsDQ(shield);

	shield = s;

	updateStatsEQ(shield);

	currentState();
}

void Fighter::equip(Belt* b)
{
	updateStatsDQ(belt);

	belt = b;

	updateStatsEQ(shield);
	currentState();
}

void Fighter::deequipArmor()
{
	updateStatsDQ(armor);
	armor = new Armor();//using phil's default constructor for armor etc
}
void Fighter::dequipWeapon()
{
	updateStatsDQ(weapon);
	weapon = new Weapon();
}
void Fighter::deequipHelmet()
{
	updateStatsDQ(helmet);
	helmet = new Helmet();
}
void Fighter::deequipBoots()
{
	updateStatsDQ(boots);
	boots = new Boots();

}
void Fighter::deequipRing()
{
	updateStatsDQ(ring);
	ring = new Ring();
}
void Fighter::deequipShield()
{
	updateStatsDQ(shield);
	shield = new Shield();
}
void Fighter::deequipBelt()
{
	updateStatsDQ(belt);
	belt = new Belt();
}


/**
* Implementation of Serialization to allow Fighter to be Serialized to file
*/
void Fighter::Serialize(CArchive &ar){
	Characters::Serialize(ar);
	if(ar.IsStoring()) {
		ar << hitPoints;
		ar << maxHitPoints;
		ar << race;
		ar << size;
		CString c_name(name.c_str());
		ar << c_name;
		ar << speed;
	}
	else {
		ar >> hitPoints;
		ar >> maxHitPoints;
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

bool Fighter::validateChestWithinRange(int x, int y){
	// Will calculate the x and y distance
	int xDiff = abs(x - this->position[0]);
	int yDiff = abs(y - this->position[1]);
	// If either the xDiff or yDiff is greater than speed, then chest is out of range - returns false
	if (xDiff > speed || yDiff > speed)
		return false;
	return true;
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

/**
* Allows the name of the Fighter to be changed
*/
void Fighter::setName(string name) {
	this->name = name;
}