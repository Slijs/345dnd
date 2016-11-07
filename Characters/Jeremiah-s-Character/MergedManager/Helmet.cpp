/**
 * @brief Class for helmets.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

#include <string>
#include <stdexcept>
#include "Helmet.h"

IMPLEMENT_SERIAL(Helmet, Item, 1);

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
	
	tempString += "\tDefense: " + std::to_string(getDefense()) + "\n";

	return tempString;
}

void Helmet::Serialize(CArchive &ar) {
	Item::Serialize(ar);
	if (ar.IsStoring()) {
		ar << defense;
	}
	else {
		ar >> defense;
	}
}