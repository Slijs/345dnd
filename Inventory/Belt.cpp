/******************************************************************************
 * Class for Belts. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

#include <string>
#include <stdexcept>
#include "Belt.h"

// Default constructor, useless item as is
Belt::Belt() : 	
	Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {1,0,1,0,0,0,0,0,0}) 
{

}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Belt::Belt(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int defense) 
	: Item(name, weight, value, image, enchantmentValues, {1,0,1,0,0,0,0,0,0}),
	defense(defense)
{

}

// Getters/Setters

int Belt::getDefense() {
	return defense;
}

void Belt::incrementDefense() {
	defense++;
}

/**
 * @brief Decremented only when result will be >= 0
 */
void Belt::decrementDefense() {
	if (defense >= 1) {
		defense--;
	}
}

// Misc methods

std::string Belt::toString() {
	std::string tempString;

	tempString = Item::toString();
	
	tempString += "\tDefense: " + std::to_string(getDefense()) + "\n";

	return tempString;
}
