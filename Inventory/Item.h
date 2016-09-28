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
#include <stdexcept>
using std::string;
using std::array;

class Item {
	// Attributes common to all items
	string name;
	int weight;
	int value;
	string image;
	array<int, 9> enchantments;

	public:
		// Accessors and Mutators
		string getName();
		void setName(string name);
		int getWeight();
		void setWeight(int weight);
		int getValue();
		void setValue(int value);
		string getImage();
		void setImage(string image);
		array<int, 9> getEnchantments();
		void setEnchantments(array<int, 9> enchantments);
};

#endif // Include guard
