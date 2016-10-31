#include "Equipment.h"


//EQUIPMENT
Equipment::Equipment()
{
	equipName = "NONE";
}
Equipment::Equipment(string equipName)
{
	this->equipName = equipName;
}

Equipment::~Equipment()
{
}

string Equipment::getName()
{
	return equipName;
}

bool Equipment::compareName(string name)
{
	bool ans = equipName.compare(name) == 0;
	return ans;
}

//ARMOR
Armor::Armor() : Equipment()
{
	ACBonus = 0;
}
Armor::Armor(string name, int ACBonus) : Equipment(name)
{
	this->ACBonus = ACBonus;
}
Armor::~Armor()
{}

int Armor::getACBonus()
{
	return ACBonus;
}


//SHIELD
Shield::Shield() : Armor()
{
}
Shield::Shield(string name, int ACBonus) : Armor(name, ACBonus)
{
}

Shield::~Shield()
{
}


//WEAPON
Weapon::Weapon() : Equipment()
{
	dice = "";
	weaponType = "";
}
Weapon::Weapon(string name, string dice, string weaponType) : Equipment(name)
{
	this->dice = dice;
	this->weaponType = weaponType;
}
Weapon::~Weapon()
{}

string Weapon::getWeaponType()
{
	return weaponType;
}

string Weapon::getDice()
{
	return dice;
}

bool Weapon::compareType(string name)
{
	return weaponType.compare(name) == 0;
}

//BOOTS
Boots::Boots() : Equipment()
{
	bonusType = 0;
	bonus = 0;
}
Boots::Boots(string name, int bonusType, int bonus) : Equipment(name)
{
	this->bonusType = bonusType;
	this->bonus = bonus;
}
Boots::~Boots()
{}
int Boots::getBonusType()
{
	return bonusType;
}

int Boots::getBonus()
{
	return bonus;
}

// HELMET
Helmet::Helmet() : Boots()
{

}
Helmet::Helmet(string name, int bonusType, int bonus) : Boots(name,bonusType, bonus)
{
}

Helmet::~Helmet()
{
}

//RING
Ring::Ring() : Boots()
{
}
Ring::Ring(string name, int bonusType, int bonus) : Boots(name, bonusType, bonus)
{
}

Ring::~Ring()
{
}