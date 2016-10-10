/******************************************************************************
 * Class for the Armors. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

// Include guard
#ifndef Armor_H
#define Armor_H


#include <string>
#include "Item.h"

class Armor: public Item {
	protected:
		// Armor Attributes
		int defense;
		// Constructors
	public:
		Armor();
		Armor(string name, int weight, int value, string image, 
				array<int, 9> enchantmentValues, int defense);
		int getDefense();
		void incrementDefense();
		void decrementDefense();
		std::string toString();
};

#endif // Include guard
