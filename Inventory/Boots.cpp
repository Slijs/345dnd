/**
 * @brief Class for boots.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */
 
#include <string>
#include <stdexcept>
#include "Boots.h"
 
// Windows
#include "stdafx.h"

// Default constructor, useless item as is
Boots::Boots() : 	
	Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {0,1,0,0,0,0,1,0,0}) 
{

}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Boots::Boots(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int defense) 
	: Item(name, weight, value, image, enchantmentValues, {0,1,0,0,0,0,1,0,0}),
	defense(defense)
{

}

// Getters/Setters

int Boots::getDefense() {
	return defense;
}

void Boots::incrementDefense() {
	defense++;
}

void Boots::decrementDefense() {
	defense--;
}

// Misc methods

std::string Boots::toString() {
	std::string tempString;

	tempString = Item::toString();
	
	tempString += "\tDefense: " + std::to_string(getDefense()) + "\n";

	return tempString;
}
