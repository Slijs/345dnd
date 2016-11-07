/**
 * @brief Class for weapons.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

#include <string>
#include <stdexcept>
#include "Weapon.h"

IMPLEMENT_SERIAL(Weapon, Item, 1);

// Default constructor, useless item as is
Weapon::Weapon() : 	
	Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,1,1}) 
{

}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Weapon::Weapon(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int damage, int defense, int range) 
	: Item(name, weight, value, image, enchantmentValues, {0,0,0,0,0,0,0,1,1}),
	damage(damage), defense(defense), range(range)
{

}

// Getters/Setters

int Weapon::getDamage() {
	return damage;
}

int Weapon::getDefense() {
	return defense;
}

int Weapon::getRange() {
	return range;
}

void Weapon::incrementDamage() {
	damage++;
}

void Weapon::decrementDamage() {
	if (damage >= 1) {
		damage--;
	}
}

void Weapon::incrementDefense() {
	defense++;
}

void Weapon::decrementDefense() {
	if (defense >= 1) {
		defense--;
	}
}

void Weapon::incrementRange() {
	range++;
}

void Weapon::decrementRange() {
	if (range >= 1) {
		range--;		
	}
}

// Misc methods

std::string Weapon::toString() {
	std::string tempString;

	tempString = Item::toString();
	
	tempString += "Damage: " + std::to_string(getDamage()) +
		"\tDefense: " + std::to_string(getDamage()) +
		"\tRange: " + std::to_string(getRange()) + "\n";

	return tempString;
}

void Weapon::Serialize(CArchive &ar) {
	Item::Serialize(ar);
	if (ar.IsStoring()) {
		ar << damage;
		ar << defense;
		ar << range;
	}
	else {
		ar >> damage;
		ar >> defense;
		ar >> range;
	}
}