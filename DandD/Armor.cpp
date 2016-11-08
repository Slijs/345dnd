/**
 * @brief Class for all armor.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

#include <string>
#include <stdexcept>
#include "Armor.h"
#include "Item.h"

// Windows
//#include "stdafx.h"

IMPLEMENT_SERIAL(Armor, Item, 1);

// Default constructor, useless item as is
Armor::Armor() : Item("No name set", 0, 0, "No Image Set", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, { { 0, 0, 0, 0, 0, 0, 1, 0, 0 } })
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
	std::array<int, 9> enchantmentValues, int defense) : Item(name, weight, value, image, enchantmentValues, { { 0, 0, 0, 0, 0, 0, 1, 0, 0 } }), defense(defense)
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

void Armor::Serialize(CArchive &ar) {
	Item::Serialize(ar);
	if (ar.IsStoring()) {
		ar << defense;
	}
	else {
		ar >> defense;
	}
}

/**
* Copy Constructor - Uses another Armor to initialize this one
*/
Armor::Armor(Armor *otherArmor) : Item(otherArmor) {
	this->defense = otherArmor->defense;
}

/**
*Operator overload - allows for a piece of Armor to be assigned the same
* values as another piece of armor
*/
Armor& Armor::operator= (const Armor* otherArmor) {
	this->defense = otherArmor->defense;
	return *this;
}