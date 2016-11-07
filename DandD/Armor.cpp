/**
 * @brief Class for all armor.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

#include <string>
#include <stdexcept>
#include "Armor.h"

// Windows
#include "stdafx.h"

// Default constructor, useless item as is
Armor::Armor() //dont forget the colon here
//KHATIBS TEST
	//Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0}) 
//END TEST
{

}

/**
 * @brief This will be the generally used constructor, all data except for the
 * 			types of enchantments possible should be set.
 *
 * @param name
 * @param weight
 * @param value
 * @param image
 * @param enchantmentValues All elements must be >= 0 and <= 5, and align with
 * 			the allowed enchantments in enchantmentsPossible. If not,
 * 			std::invalid_argument will be thrown.
 * @param defense
 */
Armor::Armor(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int defense) 
	//KHATIBS TEST
	//: Item(name, weight, value, image, enchantmentValues, {0,0,0,0,0,0,1,0,0}),
	//defense(defense)
	//END TEST
{

}

// Getters/Setters

int Armor::getDefense() {
	return defense;
}

void Armor::incrementDefense() {
	defense++;
}

/**
 * @brief This will only decrement if the defense will remain >= 0
 */
void Armor::decrementDefense() {
	if (defense >=1 ) {
		defense--;
	}
}

// Misc methods

std::string Armor::toString() {
	std::string tempString;

	tempString = Item::toString();
	//KHATIBS TEST
	//tempString += "Defense: " + std::to_string(getDefense()) + "\n";
	//END TEST
	return tempString;
}
