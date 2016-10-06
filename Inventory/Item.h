/******************************************************************************
 * Base class for all items. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

// Include guard
#ifndef Item_H
#define Item_H

#include <string>
#include <array>

using std::string;
using std::array;

class Item {
	protected:
		// Attributes common to all items
		string name;
		int weight;
		int value;
		string image;
		array<int, 9> enchantmentValues;
		array<bool, 9> enchantmentsPossible;
	public:
		// Constructors
		Item();
		Item(string name, int weight, int value, string image, 
				array<int, 9> enchantmentValues);
		Item(string name, int weight, int value, string image, 
				array<int, 9> enchantmentValues, 
				array<bool, 9> enchantmentsPossible);
		// Accessors and Mutators
		string getName();
		int getWeight();
		int getValue();
		string getImage();
		array<int, 9> getEnchantmentValues();
		array<bool, 9> getEnchantmentsPossible();
		// Misc methods
		string toString();
};

#endif // Include guard
