/**
 * @brief Class for helmets.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

#include <string>
#include <stdexcept>
#include "Helmet.h"
 
// Windows
#include "stdafx.h"

// Default constructor, useless item as is
Helmet::Helmet() 
	//KHATIBS TEST
	//: 	
	//Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {0,0,0,1,1,0,1,0,0}) 
	//END TEST
{

}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Helmet::Helmet(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int defense) 
	//KHATIBS TEST
	//: Item(name, weight, value, image, enchantmentValues, {0,0,0,1,1,0,1,0,0}),
	//defense(defense)
	//END TEST
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
	//KHATIBS TEST
	//tempString += "\tDefense: " + std::to_string(getDefense()) + "\n";
	//END TEST
	return tempString;
}
