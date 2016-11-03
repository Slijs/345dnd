/**
*@file Item.h
*@brief Implementation of the Item Class.
*
*<p> Items have been incredibly simplified for my assignment. An 'Item' object is essentially used as an inventory,
*	 providing only the ability to equip one shield, armour, weapon, helmet, ring or boots at a time. Shields, Armour
*	 and Weapons all have a special bonus associated with them, which is also kept track of within the Item.
*/
#pragma once
#ifndef ITEM_H
#define ITEM_H

/**
*@class Item
*@brief Implementation of the Character inventory.
*<p> Allows storage of one Shield, Armour, Weapon, Helmet, Ring or Boot.
*/
class Item {
private:
	int _shieldBonus;
	int _armourBonus;
	int _attackBase;

	bool _shieldEquiped;
	bool _armourEquiped;
	bool _weaponEquiped;
	bool _bootEquiped;
	bool _ringEquiped;
	bool _helmetEquiped;

public:
	Item(); //Default Constructor
	int getShieldBonus();
	int getArmourBonus();
	int getWeaponAttack();

	void equipShield(int bonus);
	void equipArmour(int bonus);
	void equipWeapon(int attackBase);
	void equipBoots();
	void equipRing();
	void equipHelmet();

	void removeShield();
	void removeArmour();
	void removeWeapon();
	void removeBoots();
	void removeRing();
	void removeHelmet();

	bool isShieldEquipped();
	bool isArmourEquipped();
	bool isWeaponEquipped();
	bool areBootsEquipped();
	bool isRingEquipped();
	bool isHelmetEquipped();

};
#endif
