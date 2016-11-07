/**
 * @brief Class for shields.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

#include <string>
#include <stdexcept>
#include "Shield.h"
 
// Windows
#include "stdafx.h"

// Default constructor, useless item as is
Shield::Shield() 
	//KHATIBS TEST
	//: 	
	//Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0}) 
	//END TEST
{

}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Shield::Shield(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int damage, int defense, int range) 
	//KHATIBS TEST
	//: Item(name, weight, value, image, enchantmentValues, {0,0,0,0,0,0,1,0,0}),
	//damage(damage), defense(defense), range(range)
	//END TEST
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
	
	//KHATIBS TEST
	//tempString += "Damage: " + std::to_string(getDamage()) +
	//	"\tDefense: " + std::to_string(getDamage()) +
	//	"\tRange: " + std::to_string(getRange()) + "\n";
	//END TEST

	return tempString;
}
