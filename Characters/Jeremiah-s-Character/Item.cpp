/**
*@file Item.cpp
*@brief Definition of all Item methods
* <p>This document outlines how the Item class works. Please note that this is an incredibly rudimentary application of Item; it only works
* to allow a user to equip and remove items from their inventory. A final build implementation of Item would look almost nothing like this;
* this is simply for proof of concept.
*/
#include "stdafx.h"
#include "Item.h"

/**
* Constructor - initializes all values to 0 or false, as nothing is equipped.
*/
Item::Item() : _shieldBonus(0), _armourBonus(0), _attackBase(0)
{
	 _shieldEquiped = false;
	 _armourEquiped = false;
	 _weaponEquiped = false;
	 _bootEquiped = false;
	 _ringEquiped = false;
	 _helmetEquiped = false;
}

/**
* Returns the shield bonus associated with the equiped shield.
*@return integer, representing the shield's bonus
*/
int Item::getShieldBonus()
{
	return _shieldBonus;
}

/**
* Returns the armour bonus associated with the equiped armour.
*@return integer, representing the armour's bonus
*/
int Item::getArmourBonus() {
	return _armourBonus;
}

/**
* Returns the attack score of the equipped weapon.
*@return int, representing how much damage a weapon does
*/
int Item::getWeaponAttack()
{
	return _attackBase;
}

/**
* Equips a shield in the inventory with the specified shield bonus.
*@param int representing the shield bonus
*/
void Item::equipShield(int bonus)
{
	_shieldBonus = bonus;
	_shieldEquiped = true;
}

/**
* Equips a suit of armour in the inventory with the specified armour bonus.
*@param int representing the armour bonus
*/
void Item::equipArmour(int bonus)
{
	_armourBonus = bonus;
	_armourEquiped = true;
}

/**
* Will equip a new weapon in the inventory with the provided attack base.
*@param integer Attack Base of the weapon
*/
void Item::equipWeapon(int attackBase)
{
	this->_attackBase = attackBase;
	_weaponEquiped = true;
}

/**
* Performs the necessary actions to equip a pair of boots. Does nothing at the moment.
*/
void Item::equipBoots()
{
	_bootEquiped = true;
}

/**
* Performs the necessary actions to equip a ring. Does nothing at the moment.
*/
void Item::equipRing(){
	_ringEquiped = true;
}

/**
* Performs the necessary actions to equip a helmet. Does nothing at the moment.
*/
void Item::equipHelmet()
{
	_helmetEquiped = true;
}

/**
* Removes the shield, ensuring that the bonus returns to 0.
*/
void Item::removeShield()
{
	_shieldBonus = 0;
	_shieldEquiped = false;
}

/**
* Removes the armour, ensuring the bonus returns to 0.
*/
void Item::removeArmour()
{
	_armourBonus = 0;
	_armourEquiped = 0;
}

/**
* Removes the attached weapon, ensuring that the bonus returns to 0.
*/
void Item::removeWeapon()
{
	_attackBase = 0;
	_weaponEquiped = 0;
}

/**
* Removes the equiped boots.
*/
void Item::removeBoots()
{
	_bootEquiped = 0;
}
/**
* Removes the Ring that has been equiped to the Inventory.
*/
void Item::removeRing()
{
	_ringEquiped = 0;
}

/**
* Removes the helmet that has been equipped
*/
void Item::removeHelmet()
{
	_helmetEquiped = false;
}

/**
*@return bool, whether or not a shield is equipped
*/
bool Item::isShieldEquipped()
{
	return _shieldEquiped;
}

/**
*@return bool, whether or not armour is equipped
*/
bool Item::isArmourEquipped()
{
	return _armourEquiped;
}

/**
*@return bool, whether or not a weapon is equipped
*/
bool Item::isWeaponEquipped()
{
	return _weaponEquiped;
}

/**
*@return bool, whether or not a boot is equipped
*/
bool Item::areBootsEquipped()
{
	return _bootEquiped;
}

/**
*@return bool, whether or not a ring is equipped
*/
bool Item::isRingEquipped()
{
	return _ringEquiped;
}

/**
*@return bool, whether or not a helmet is equipped
*/
bool Item::isHelmetEquipped()
{
	return _helmetEquiped;
}
;
