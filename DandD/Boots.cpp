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
Boots::Boots() 
	//KHATIBS TEST
	//: 	
	//Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {0,1,0,0,0,0,1,0,0}) 
	//END TEST
{

}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Boots::Boots(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int defense) 
	//KHATIBS TEST
	//: Item(name, weight, value, image, enchantmentValues, {0,1,0,0,0,0,1,0,0}),
	//defense(defense)
	//END TEST
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
	//KHATIBS TEST
	//tempString += "\tDefense: " + std::to_string(getDefense()) + "\n";
	//END TEST
	return tempString;
}
