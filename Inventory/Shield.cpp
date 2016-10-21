/******************************************************************************
 * Class for Shields. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

#include <string>
#include <stdexcept>
#include "Shield.h"

// Default constructor, useless item as is
Shield::Shield() : 	
	Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0}) 
{

}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Shield::Shield(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int damage, int defense, int range) 
	: Item(name, weight, value, image, enchantmentValues, {0,0,0,0,0,0,1,0,0}),
	damage(damage), defense(defense), range(range)
{

}

// Getters/Setters

int Shield::getDamage() {
	return damage;
}

int Shield::getDefense() {
	return defense;
}

int Shield::getRange() {
	return range;
}

void Shield::incrementDamage() {
	damage++;
}

void Shield::decrementDamage() {
	damage--;
}

void Shield::incrementDefense() {
	defense++;
}

void Shield::decrementDefense() {
	defense--;
}

void Shield::incrementRange() {
	range++;
}

void Shield::decrementRange() {
	range--;
}

// Misc methods

std::string Shield::toString() {
	std::string tempString;

	tempString = Item::toString();
	
	tempString += "Damage: " + std::to_string(getDamage()) +
		"\tDefense: " + std::to_string(getDamage()) +
		"\tRange: " + std::to_string(getRange()) + "\n";

	return tempString;
}
