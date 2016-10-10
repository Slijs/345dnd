/******************************************************************************
 * Class for Helmets. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

#include <string>
#include <stdexcept>
#include "Helmet.h"

// Default constructor, useless item as is
Helmet::Helmet() : 	
	Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {0,0,0,1,1,0,1,0,0}) 
{

}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Helmet::Helmet(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int defense) 
	: Item(name, weight, value, image, enchantmentValues, {0,0,0,1,1,0,1,0,0}),
	defense(defense)
{

}

// Getters/Setters

int Helmet::getDefense() {
	return defense;
}

void Helmet::incrementDefense() {
	defense++;
}

void Helmet::decrementDefense() {
	defense--;
}

// Misc methods

std::string Helmet::toString() {
	std::string tempString;

	tempString = Item::toString();
	
	tempString += "------------------ Helmet Properties  ---------------\n";
	tempString += "\tDefense: " + std::to_string(getDefense());

	return tempString;
}
