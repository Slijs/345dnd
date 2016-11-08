#include "Equipment.h"

/*EQUIPMENT
*/
//!Default Constructor, sets name to "NONE"
Equipment::Equipment()
{
	equipName = "NONE";
}
//!Parameterized Constructor to set name of equipment
Equipment::Equipment(string equipName)
{
	this->equipName = equipName;
}
//!Destructor
Equipment::~Equipment()
{
}
//!Accessor for name of equipment
string Equipment::getName()
{
	return equipName;
}
//!Function used to compare name of equipment and parameter string
bool Equipment::compareName(string name)
{
	bool ans = equipName.compare(name) == 0;
	return ans;
}

void Equipment::Serialize(CArchive & ar)
{
	CObject::Serialize(ar);
	if (ar.isStoring()) {
		CString c_name(equipName.c_str());
		ar << c_name;
	}
	else {
		CString c_name = "";
		ar >> c_name;
		equipName = "";
		int strlen = c_name.GetLength();
		for (int i = 0; i < strlen; ++i) {
			equipName += c_name.GetAt(i);
		}
	}
}

/*ARMOR
*/
//!Default Constructor that sets Armor Class bonus to zero
Armor::Armor() : Equipment()
{
	ACBonus = 0;
}
//!Parameterized Constructor to set name and AC bonus
Armor::Armor(string name, int ACBonus) : Equipment(name)
{
	this->ACBonus = ACBonus;
}
//!Destructor
Armor::~Armor()
{}

int Armor::getACBonus()
{
	return ACBonus;
}


/*SHIELD*/
//!Default Constructor
Shield::Shield() : Armor()
{
}
//!Parameterized Constructor to set name and AC bonus
Shield::Shield(string name, int ACBonus) : Armor(name, ACBonus)
{
}
//!Destructor
Shield::~Shield()
{
}

/*WEAPON*/
//!Default Constructor that sets dice and weapon type to empty strings
Weapon::Weapon() : Equipment()
{
	dice = "";
	weaponType = "";
}
//!Parameterized Constructor to set name, weapon dice and weapon type
Weapon::Weapon(string name, string dice, string weaponType) : Equipment(name)
{
	this->dice = dice;
	this->weaponType = weaponType;
}
//!Destructor
Weapon::~Weapon()
{}
//!Accessor for weapon type
string Weapon::getWeaponType()
{
	return weaponType;
}
//!Accessor for weapon dice
string Weapon::getDice()
{
	return dice;
}
//!Function used to compare name of weapon and parameter string
bool Weapon::compareType(string name)
{
	return weaponType.compare(name) == 0;
}

//BOOTS
//!Default Constructor that sets bonusType and bonus to zero
Boots::Boots() : Equipment()
{
	bonusType = 0;
	bonus = 0;
}
//!Parameterized Constructor to set name, bonus type and bonus value
Boots::Boots(string name, int bonusType, int bonus) : Equipment(name)
{
	this->bonusType = bonusType;
	this->bonus = bonus;
}
//!Destructor
Boots::~Boots()
{}

//!Accessor to bonus type
int Boots::getBonusType()
{
	return bonusType;
}

//!Accessor to bonus value
int Boots::getBonus()
{
	return bonus;
}

// HELMET
//!Default Constructor 
Helmet::Helmet() : Boots()
{

}
//!Parameterized Constructor to set name, bonus type and bonus value
Helmet::Helmet(string name, int bonusType, int bonus) : Boots(name, bonusType, bonus)
{
}
//!Destructor
Helmet::~Helmet()
{
}

//RING
//!Default Constructor 
Ring::Ring() : Boots()
{
}
//!Parameterized Constructor to set name, bonus type and bonus value
Ring::Ring(string name, int bonusType, int bonus) : Boots(name, bonusType, bonus)
{
}
//!Destructor
Ring::~Ring()
{
}
