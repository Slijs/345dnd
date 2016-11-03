/**
*@file Character.cpp
*@brief Implementation file for the Character class  
* <p>The following is the best implementation I could come up with for a Character, having not completed it for the first assignment.
* Characters are able to have any level between 1 and 20, a Race out of Human, Elf, Halfling and Dwarf, and a Class out of Fighter,
* Cleric, Rogue and Wizard. Races only affect a Character's ability modifiers, whereas Class only affects a Character's base HP.
* Any other effects due to Race or Class have been removed for simplicity.
*/
#include "stdafx.h"
#include "Character.h"
#include <iostream>

/**
*Default constructor - does nothing
*/
Character::Character() {
}

//! Constructor: passes values to each ability score and set hit points to 10
/**
*Parameterized Constructor. Provides all the initial values that are required to setup a character.
* All values provided will be set for the character. HP and EXP will be scaled based on starting level.
* Inventory will initially  be empty
*@param name string representing the Character's name
*@param lvl integer representing the desired starting level - HP and EXP will be scaled based on this
*@param str integer representing strength score
*@param dex integer representing dexterity score
*@param con integer representing constitution score
*@param intel integer representing intelligence score
*@param wis integer representing wisdom score
*@param cha integer representing charisma score
*@param theirClass ClassType representing the desired class of Character
*@param theirRace RaceType representing the desired race of Character
*/
Character::Character(string name, int lvl, int str, int dex, int con, int intel, int wis, int cha, ClassType theirClass, RaceType theirRace) {

	_theDie;	// Will be used to scale HP based on level
	this->_name = name;	// Sets name to the char string provided
	_inventory = new Item();	// Sets inventory to empty inventory
	
	// Sets Character Race
	switch (theirRace) {
	case(Dwar): _charRace = new Dwarf();
		break;
	case(El): _charRace = new Elf();
		break;
	case(Hum): _charRace = new Human();
		break;
	case(Half): _charRace = new Halfling();
		break;
	}

	// Sets Character class
	_charClass = new Classes(theirClass);

	// Will set all abilities based on values, with maximum of 18
	_abilitiesAndMods[0][Strength] = (str <= 18 ? str : 18);
	_abilitiesAndMods[0][Dexterity] = (dex <= 18 ? dex : 18);
	_abilitiesAndMods[0][Constitution] = (con <= 18 ? con : 18);
	_abilitiesAndMods[0][Intelligence] = (intel <= 18 ? intel : 18);
	_abilitiesAndMods[0][Wisdom] = (wis <= 18 ? wis : 18);
	_abilitiesAndMods[0][Charisma] = (cha <= 18 ? cha : 18);

	// Will set all modifiers based on formula (SCORE - 10) / 2
	_abilitiesAndMods[1][Strength] = (str - 10) / 2;
	_abilitiesAndMods[1][Dexterity] = (dex - 10) / 2;
	_abilitiesAndMods[1][Constitution] = (con - 10) / 2;
	_abilitiesAndMods[1][Intelligence] = (intel - 10) / 2;
	_abilitiesAndMods[1][Wisdom] = (wis - 10) / 2;
	_abilitiesAndMods[1][Charisma] = (cha - 10) / 2;

	// Will set max HP based on Class base HP and Constitution modifier, as per d20 rules
	_maxHP = _charClass->getBaseHP() + _abilitiesAndMods[1][Constitution];	
	
	// Will increase ability modifier based on race
	_abilitiesAndMods[1][(int)_charRace->getAbilityModified()] = _abilitiesAndMods[1][_charRace->getAbilityModified()] + _charRace->getAblMod();

	// Will set experience points and hit points based on desired level. Hit points will reflect the number of times a hit die should have been rolled when
	// the Character leveled up to reach the desired level.
	switch (lvl) {
	case 1:
		this->_exp = 0;
		_level = 1;
		break;
	case 2:
		_exp = 300;
		_level = 2;
		_maxHP = _maxHP + _theDie.roll("1" + _charClass->getHitDie());
		break;
	case 3:
		_exp = 900;
		_level = 3;
		_maxHP += _theDie.roll("2" + _charClass->getHitDie());
		break;
	case 4:
		_exp = 2700;
		_level = 4;
		_maxHP += _theDie.roll("3" + _charClass->getHitDie());
		break;
	case 5:
		_exp = 6500;
		_level = 5;
		_maxHP += _theDie.roll("4" + _charClass->getHitDie());
		break;
	case 6:
		_exp = 14000;
		_level = 6;
		_maxHP += _theDie.roll("5" + _charClass->getHitDie());
		break;
	case 7:
		_exp = 23000;
		_level = 7;
		_maxHP += _theDie.roll("6" + _charClass->getHitDie());
		break;
	case 8:
		_exp = 34000;
		_level = 8;
		_maxHP += _theDie.roll("7" + _charClass->getHitDie());
		break;
	case 9:
		_exp = 48000;
		_level = 9;
		_maxHP += _theDie.roll("8" + _charClass->getHitDie());
		break;
	case 10:
		_exp = 64000;
		_level = 10;
		_maxHP += _theDie.roll("9" + _charClass->getHitDie());
		break;
	case 11:
		_exp = 85000;
		_level = 11;
		_maxHP += _theDie.roll("10" + _charClass->getHitDie());
		break;
	case 12:
		_exp = 100000;
		_level = 12;
		_maxHP += _theDie.roll("11" + _charClass->getHitDie());
		break;
	case 13:
		_exp = 120000;
		_level = 13;
		_maxHP += _theDie.roll("12" + _charClass->getHitDie());
		break;
	case 14:
		_exp = 140000;
		_level = 14;
		_maxHP += _theDie.roll("13" + _charClass->getHitDie());
		break;
	case 15:
		_exp = 165000;
		_level = 15;
		_maxHP += _theDie.roll("14" + _charClass->getHitDie());
		break;
	case 16:
		_exp = 195000;
		_level = 16;
		_maxHP += _theDie.roll("15" + _charClass->getHitDie());
		break;
	case 17:
		_exp = 225000;
		_level = 17;
		_maxHP += _theDie.roll("16" + _charClass->getHitDie());
		break;
	case 18:
		_exp = 265000;
		_level = 18;
		_maxHP += _theDie.roll("17" + _charClass->getHitDie());
		break;
	case 19:
		_exp = 305000;
		_level = 19;
		_maxHP += _theDie.roll("18" + _charClass->getHitDie());
		break;
	case 20:
		_exp = 355000;
		_level = 20;
		_maxHP += _theDie.roll("19" + _charClass->getHitDie());
	}

	_currentHP = _maxHP;	 // Makes sure that the Character starts with full health!
	_isDead = false;	// Makes sure that the Character isn't dead at start!
}


/**
* Will return the name of the Character.
*@return string, representing the Character's name
*/
string Character::getName(){ 
	return _name; 
};

/**
* Will return the Character's current level.
*@return integer, representing the Character's level
*/
int Character::getLevel() {
	return _level;
};


/**
* Will return the Character's total experience points.
*@return integer, representing the total number of experience points the Character has.
*/
int Character::getExp() {
	return _exp;
}

/**
* Will return the Character's maximum HP 
*@return integer, representing Character's max HP
*/
int Character::getMaxHP() {
	return _maxHP;
}

/** 
* Will return the Character's current HP
*@return int: value of currentHitPoints
*/
int Character::getCurrentHP()
{
	return _currentHP;
}

/**
* Will return the Character's speed, based on their race.
* @return integer, representing the Character's speed
*/
int Character::getSpeed() {
	return _charRace->getRaceSpeed();
}

/*
* Will return the Character's initiative score. Will be implemented further for final game.
* @return integer, representing the Character's initiative
*/
int Character::getInitiative() {
	return _initiative;
}

/**
* Will return the Character's Strength, taking into consideration their Strength modifier
*@return integer, representing Character's Strength
*/
int Character::getStrength() {
	return (_abilitiesAndMods[0][Strength] + _abilitiesAndMods[1][Strength]);
}

/**
* Will return the Character's Dexterity, taking into consideration their Dexterity modifier
*@return integer, representing Character's Dexterity
*/
int Character::getDexterity() {
	return (_abilitiesAndMods[0][Dexterity] + _abilitiesAndMods[1][Dexterity]);
}

/**
* Will return the Character's Constitution, taking into consideration their Constitution modifier
*@return integer, representing Character's Constitution
*/
int Character::getConstitution() {
	return (_abilitiesAndMods[0][Constitution] + _abilitiesAndMods[1][Constitution]);
}

/**
* Will return the Character's Intelligence, taking into consideration their Intelligence modifier
*@return integer, representing Character's Intelligence
*/
int Character::getIntelligence() {
	return (_abilitiesAndMods[0][Intelligence] + _abilitiesAndMods[1][Intelligence]);
}

/**
* Will return the Character's Wisdom, taking into consideration their Wisdom modifier
*@return integer, representing Character's Wisdom
*/
int Character::getWisdom() {
	return (_abilitiesAndMods[0][Wisdom] + _abilitiesAndMods[1][Wisdom]);
}

/**
* Will return the Character's Charisma, taking into consideration their Charisma modifier
*@return integer, representing Character's Charisma
*/
int Character::getCharisma() {
	return (_abilitiesAndMods[0][Charisma] + _abilitiesAndMods[1][Charisma]);
}

/**
* Will return the integer representing the Size of the character, based on Race.
*@return integer, representing Character size
*/
int Character::getSize() {
	return _charRace->getRaceSize(); 
}

/**
* Will return a string with the name of the Character's class
*@return string
*/
string Character::getClass() {
	return _charClass->getWhichClass();
}

/**
* Will return a string with the name of the Character's race
*@return string
*/
string Character::getRace()
{
	return _charRace->getWhichRace();
}

//! Implementation of the verification of a newly created Character
//! @return bool value, true of the character is valid (stats should be in the 3-18 range for a new character), false if invalid. 
bool Character::validateNewCharacter()
{
	for (int i = 0; i <= 5; i++)
		if (_abilitiesAndMods[0][i]<3 || _abilitiesAndMods[0][i]>18)
			return false;
	return true;
}

/**
* Will calculate and return the Character's Armour Class.
*<p>Armour Class = 10 + Armour Bonus + Shield Bonus + Dexterity Modifier
*@return integer, representing Armour Class
*/
int Character::getArmourClass()
{
	return 10 + _inventory->getArmourBonus() + _inventory->getShieldBonus() + _abilitiesAndMods[1][Dexterity];
}

/**
* Will return the Attack Bonus of a Character.
*<p> Attack Bonus = level + Weapon attack Bonus + Strength Modifier
*<p> For simplicity, there is no difference between Ranged and Melee weapons.
*	 Additionally, the level # is added irregardless of Character class
*@return integer, representing the Attack Bonus of a character
*/
int Character::getAttackBonus()
{
	return _level + _inventory->getWeaponAttack() + _abilitiesAndMods[1][Strength];
}

/**
* Returns the bonus that gets added to damage rolls. Since there is no difference between
* ranged and melee weapons, only the Strength modifier is being used along with the
* proficiency bonus
*@return integer, representing the Character's damage bonus
*/
int Character::getDamageBonus()
{
	return _abilitiesAndMods[1][Strength] + getProficiencyBonus();
}

/**
* Returns the Character's proficiency bonus, based on their level.
*@return integer, representing the proficiency bonus
*/
int Character::getProficiencyBonus()
{
	if (_level < 5)
		return 2;
	else if (_level < 9)
		return 3;
	else if (_level < 13)
		return 4;
	else if (_level < 17)
		return 5;
	else return 6;
}

/**
* Equips a new shield to the Character, with the bonus provided.
*@param integer shield bonus of the new shield
*/
void Character::equipShield(int bonus)
{
	_inventory->equipShield(bonus);
	notify();
}

/**
* Equips a new set of Armour to a character. Uses the bonus provided to set its Armour bonus
*@param integer Armour bonus of the new armour
*/
void Character::equipArmour(int bonus)
{
	_inventory->equipArmour(bonus);
	notify();
}

/**
* Equips a new weapon to the Character, with the value in 'damage' as the amount of damage the weapon does.
*@param damage integer rpresenting the amount of damage
*/
void Character::equipWeapon(int damage)
{
	_inventory->equipWeapon(damage);
	notify();
}

/**
* Equips a pair of boots to the inventory.
*/
void Character::equipBoots()
{
	_inventory->equipBoots();
	notify();
}

/**
* Equips a ring to the inventory.
*/
void Character::equipRing()
{
	_inventory->equipRing();
	notify();
}

/**
* Equips a helmet to the inventory
*/
void Character::equipHelmet()
{
	_inventory->equipHelmet();
	notify();
}

/**
* Removes the shield
*/
void Character::removeShield()
{
	_inventory->removeShield();
	notify();
}

/**
* Removes the armour
*/
void Character::removeArmour()
{
	_inventory->removeArmour();
	notify();
}

/**
* Removes the attached weapon
*/
void Character::removeWeapon()
{
	_inventory->removeWeapon();
	notify();
}

/**
* Removes the equiped boots.
*/
void Character::removeBoots()
{
	_inventory->removeBoots();
	notify();
}
/**
* Removes the Ring that has been equiped to the Inventory.
*/
void Character::removeRing()
{
	_inventory->removeRing();
	notify();
}

/**
* Removes the helmet that has been equipped
*/
void Character::removeHelmet()
{
	_inventory->removeHelmet();
	notify();
}

/**
*@return bool, whether or not a shield is equipped
*/
bool Character::isShieldEquipped()
{
	return _inventory->isShieldEquipped();
}

/**
*@return bool, whether or not armour is equipped
*/
bool Character::isArmourEquipped()
{
	return _inventory->isArmourEquipped();
}

/**
*@return bool, whether or not a weapon is equipped
*/
bool Character::isWeaponEquipped()
{
	return _inventory->isWeaponEquipped();
}

/**
*@return bool, whether or not a boot is equipped
*/
bool Character::areBootsEquipped()
{
	return _inventory->areBootsEquipped();
}

/**
*@return bool, whether or not a ring is equipped
*/
bool Character::isRingEquipped()
{
	return _inventory->isRingEquipped();
}

/**
*@return bool, whether or not a helmet is equipped
*/
bool Character::isHelmetEquipped()
{
	return _inventory->isHelmetEquipped();
}

/**
* Used to determine if the Character is dead.
*@return bool, representing whether or not the Character is dead
*/
bool Character::isDead()
{
	return _isDead;
}

/**
* Will damage the Character, deducting the damage from their current HP.
*@param integer damage: damage sustained by the character
*/
void Character::hit(int damage)
{
	// Will do nothing if the damage provided is a negative number
	if (damage < 0) {
		return;
	}
	// If the damage will kill the Character, then _currentHP is set to zero and the Character is made dead
	if (damage >= _currentHP) {
		_currentHP = 0;
		_isDead = true;
	} else _currentHP = _currentHP - damage; // Happens if the Character is still living after taking damage
	notify();	// Notifies the observer that damage has been taken
}

/**
* Will increment a Character's XP by amount, and adjust level if necessary. Upon leveling up,
* maxHP will be increased by a random amount, determined by the Character's hit die. Increase of
* ability scores has been removed for simplicity.
*
*@param amount integer, number of XP to add
*/
void Character::addXP(int amount)
{
	string toRoll = "1" + _charClass->getHitDie();
	this->_exp += amount;

	// A switch statement is used because each level has a certain
	// threshold experience point level that does not follow any standard relationship
	switch (_level) {
	case 1:
		if (_exp >= 300) {
			_level = 2;
			_maxHP += _theDie.roll(toRoll);
		}
	case 2:
		if (_exp >= 900) {
			_level = 3;
			_maxHP += _theDie.roll(toRoll);
		}
	case 3:
		if (_exp >= 2700) {
			_level = 4;
			_maxHP += _theDie.roll(toRoll);
		}
	case 4:
		if (_exp >= 6500) {
			_level = 5;
			_maxHP += _theDie.roll(toRoll);
		}
	case 5:
		if (_exp >= 14000){
			_level = 6;
			_maxHP += _theDie.roll(toRoll);
		}
	case 6:
		if (_exp >= 23000){
			_level = 7;
			_maxHP += _theDie.roll(toRoll);
		}
	case 7:
		if (_exp >= 34000){
			_level = 8;
			_maxHP += _theDie.roll(toRoll);
		}
	case 8:
		if (_exp >= 48000){
			_level = 9;
			_maxHP += _theDie.roll(toRoll);
		}
	case 9:
		if (_exp >= 64000){
			_level = 10;
			_maxHP += _theDie.roll(toRoll);
		}
	case 10:
		if (_exp >= 85000){
			_level = 11;
			_maxHP += _theDie.roll(toRoll);
		}
	case 11:
		if (_exp >= 100000){
			_level = 12;
			_maxHP += _theDie.roll(toRoll);
		}
	case 12:
		if (_exp >= 120000){
			_level = 13;
			_maxHP += _theDie.roll(toRoll);
		}
	case 13:
		if (_exp >= 140000){
			_level = 14;
			_maxHP += _theDie.roll(toRoll);
		}
	case 14:
		if (_exp >= 165000){
			_level = 15;
			_maxHP += _theDie.roll(toRoll);
		}
	case 15:
		if (_exp >= 195000){
			_level = 16;
			_maxHP += _theDie.roll(toRoll);
		}
	case 16:
		if (_exp >= 225000){
			_level = 17;
			_maxHP += _theDie.roll(toRoll);
		}
	case 17:
		if (_exp >= 265000){
			_level = 18;
			_maxHP += _theDie.roll(toRoll);
		}
	case 18:
		if (_exp >= 305000){
			_level = 19;
			_maxHP += _theDie.roll(toRoll);
		}
	case 19:
		if (_exp >= 355000){
			_level = 20;
			_maxHP += _theDie.roll(toRoll);
		}
	}
	notify(); // Notifies the Observers that a change has been made
}

/**
* Destructor for the Character object. Deletes all Objects it is composed of
*/
Character::~Character() {
	delete _charClass;
	delete _charRace;
	delete _inventory;
}