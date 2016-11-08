/**
* @brief Base class for all items.
* @author Philip Brink
* @version 0.0.1
* @date 2016-10-20
*/

#include <string>
#include <array>
#include <stdexcept>
#include "Item.h"

using std::string;
using std::array;

/**
* @brief Default constructor, useless as is. All data is set to 0 or placeholder.
*/
Item::Item() : name("Name Unset"),
weight(0),
value(0),
image("Image Unset"), //dont forget to add comma here
//KHATIBS TEST
enchantmentValues({ 0, 0, 0, 0, 0, 0, 0, 0, 0 }),
enchantmentsPossible({ 0, 0, 0, 0, 0, 0, 0, 0, 0 }) 
//END TEST
{}

/**
* @brief This will be the standard constructor to be used for the
* 			derived classes.
*
* @param name
* @param weight
* @param value
* @param image Path to image from project root directory
* @param enchantmentValues These values MUST match the values allowed
* 			by enchantmentsPossible. If not, std::invalid_argument will
* 			be thrown. They must also be >= 0 AND <= 5. If the object
* 			does not have an array of possible enchantments, this array
* 			will be used to generate the possible enchantments, where
* 			an enchantment will be allowed if it is > 0 in this list.
*/
Item::Item(string name, int weight, int value, string image,
	std::array<int, 9> enchantmentValues) :
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
		}
		else if (enchantmentValues[i] > 0) {
			enchantmentsPossible[i] = true;
		}
	}
	this->enchantmentValues = enchantmentValues;
}

/**
* @brief This constructor is present in order to add extra flexibility
* 			for later, and allow the set of possible enchantments for
* 			the item to be specified.
*
* @param name
* @param weight
* @param value
* @param image Path to image from project root directory
* @param enchantmentValues These values must be >= 0 AND <= 5, and
* 			no value can be > 0 if the corresponding value in
* 			enchantmentsPossible is false.
* @param enchantmentsPossible
*/
Item::Item(string name, int weight, int value, string image,
	std::array<int, 9> enchantmentValues,
	std::array<bool, 9> enchantmentsPossible) :
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
		}
		else if (enchantmentValues[i] < 0 || enchantmentValues[i] > 5) {
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
	//KHATIBS TEST
	tempString += "------------------ " + getName() + " ---------------\n";
	tempString += "Weight: " + std::to_string(getWeight()) + "\tValue: "
		+ std::to_string(getValue()) +
		"\tImage: " + getImage() + "\n";
	tempString += "Enchantments:\n";
	tempString += "STR\tDEX\tCON\tINT\tWIS\tCHA\tARM\tATT\tDAM\n";
	array<int, 9> tempEnchantmentValues = getEnchantmentValues();
	for (int i = 0; i < 9; i++) {
		tempString += std::to_string(tempEnchantmentValues[i]) + "\t";
	}
	tempString += "\n";
	//END TEST
	return tempString;
}
