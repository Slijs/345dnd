/**
 * @brief Class for belts.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

#include <string>
#include <stdexcept>
#include "Belt.h"

 // Windows
//#include "stdafx.h"

IMPLEMENT_SERIAL(Belt, Item, 1);
// Default constructor, useless item as is
Belt::Belt()
	//KHATIBS TEST
	//: 	
	//Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {1,0,1,0,0,0,0,0,0}) 
	//END TEST
{

}

/**
* Copy Constructor - initializes a new belt with the same values as another belt
*/
Belt::Belt(const Belt* otherBelt) : Item(otherBelt), defense(otherBelt->defense) {}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Belt::Belt(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int defense) 
	//KHATIBS TEST
	//: Item(name, weight, value, image, enchantmentValues, {1,0,1,0,0,0,0,0,0}),
	//defense(defense)
	//END TEST
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
	
	//KHATIBS TEST
	//tempString += "\tDefense: " + std::to_string(getDefense()) + "\n";
	//END TEST

	return tempString;
}

void Belt::Serialize(CArchive &ar) {
	Item::Serialize(ar);
	if (ar.IsStoring()) {
		ar << defense;
	}
	else {
		ar >> defense;
	}
}