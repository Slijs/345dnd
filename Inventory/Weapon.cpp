/******************************************************************************
 * Class for weapons. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

#include <string>
#include <stdexcept>
#include "Weapon.h"

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
	damage--;
}

void Weapon::incrementDefense() {
	defense++;
}

void Weapon::decrementDefense() {
	defense--;
}

void Weapon::incrementRange() {
	range++;
}

void Weapon::decrementRange() {
	range--;
}

// Misc methods

std::string Weapon::toString() {
	std::string tempString;

	tempString = Item::toString();
	
	tempString += "------------------ Weapon Properties  ---------------\n";
	tempString += "Damage: " + std::to_string(getDamage()) +
		"\tDefense: " + std::to_string(getDamage()) +
		"\tRange: " + std::to_string(getRange());

	return tempString;
}
