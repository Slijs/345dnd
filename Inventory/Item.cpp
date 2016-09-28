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

// Accessor and Mutator implementation

string Item::getName() {
	return name;
}

void Item::setName(string name) {
	Item::name = name;
}

int Item::getWeight() {
	return weight;
}

void Item::setWeight(int weight) {
	Item::weight = weight;
}

int Item::getValue() {
	return value;
}

void Item::setValue(int value) {
	Item::value = value;
}

string Item::getImage() {
	return image;
}

void Item::setImage(string image) {
	Item::image = image;
}

array<int, 9> Item::getEnchantments() {
	return enchantments;
}

void Item::setEnchantments(array<int, 9> setEnchantments) {
	// make sure the array has a length of 9, and that all elements i in the
	// array are 0 <= i <= 5
	if (enchantments.size() != 9) {
		throw std::invalid_argument("Enchantment array invalid: not of length 9");
	} else {
		for (int i = 0; i < enchantments.size(); i++) {
			if (enchantments[i] < 0 || enchantments[i] > 5) {
				throw std::invalid_argument("Enchantment array invalid: An enchantment is <0 or >5");
				return;
			}

			// If there are no problems, set the enchantments
			Item::enchantments = enchantments;
		}
	}
	
}
