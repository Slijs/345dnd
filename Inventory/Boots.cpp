/******************************************************************************
 * Class for Boots. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

#include <string>
#include <stdexcept>
#include "Boots.h"

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
	
	tempString += "------------------ Boots Properties  ---------------\n";
	tempString += "\tDefense: " + std::to_string(getDefense());

	return tempString;
}
