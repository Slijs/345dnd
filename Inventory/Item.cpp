/******************************************************************************
 * Base class for all items. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

#include <string>
#include <array>
#include <stdexcept>
#include "Item.h"

using std::string;
using std::array;

// Default constructor, useless item as is
Item::Item() : 	name("Name Unset"),
				weight(0),
				value(0),
				image("Image Unset"),
				enchantmentValues({0, 0, 0, 0, 0, 0, 0, 0, 0}),
				enchantmentsPossible({0, 0, 0, 0, 0, 0, 0, 0, 0}) {}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set. This is for the benefit of the subclasses, where each has their
// own list of permissions that are possible. For the case of the superclass,
// the list of possible enchantments will be initialized based off of the list
// of current enchantments passed.
Item::Item(string name, int weight, int value, string image, 
		std::array<int,9> enchantmentValues) :
				name(name),
				weight(weight),
				value(value),
				image(image)
{
	// Initialize the enchantmentsPossible based off of the array of
	// enchantmentValues.
	for (int i = 0; i < 9; i++) {
		// make sure that the enchantmentValues are in the correct range
		if (enchantmentValues[i] < 0 || enchantmentValues[i] > 5) {
			throw std::invalid_argument
				("enchantmentValues elements must be >= 0 and <= 5.");
		} else if (enchantmentValues[i] > 0) {
			enchantmentsPossible[i] = true;
		} 
	}
	this->enchantmentValues = enchantmentValues;
}

// Constructor where ALL of the parameters will be set
Item::Item(string name, int weight, int value, string image, 
		std::array<int,9> enchantmentValues, 
		std::array<bool,9> enchantmentsPossible) :
				name(name),
				weight(weight),
				value(value),
				image(image),
				enchantmentsPossible(enchantmentsPossible)
{
	// Check to make sure that all of the values present in enchantmentValues
	// are allowed according to enchantmentsPossible.
	for (int i = 0; i < 9; i++) {
		if (enchantmentsPossible[i] == false && enchantmentValues[i] != 0) {
			throw std::invalid_argument
				("Tried to have an enchantment value that is not permitted"
				" for this type of item.");
		} else if (enchantmentValues[i] < 0 || enchantmentValues[i] > 5) {
			throw std::invalid_argument
				("Enchantment values must be >= 0 and <= 5.");
		}
	}
	this->enchantmentValues = enchantmentValues;
}


// Accessor and Mutator implementation

string Item::getName() {
	return name;
}

int Item::getWeight() {
	return weight;
}

int Item::getValue() {
	return value;
}

string Item::getImage() {
	return image;
}

array<int, 9> Item::getEnchantmentValues() {
	return enchantmentValues;
}

array<bool, 9> Item::getEnchantmentsPossible() {
	return enchantmentsPossible;
}

// Misc methods

string Item::toString() {
	string tempString;
	tempString += "------------------ " + getName() + " ---------------\n";
	tempString += "Weight: " + std::to_string(getWeight()) + "\tValue: " 
		+ std::to_string(getValue()) + 
		"\tImage: " + getImage() + "\n";
	tempString += "Enchantments:\n";
	tempString += "STR\tDEX\tCON\tINT\tWIS\tCHA\tARM\tATT\tDEF\n";
	array<int, 9> tempEnchantmentValues = getEnchantmentValues();
	for (int i = 0; i < 9; i++) {
		tempString += std::to_string(tempEnchantmentValues[i]) + "\t";
	}
	tempString += "\n";
	return tempString;
}
