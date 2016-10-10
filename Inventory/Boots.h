/******************************************************************************
 * Class for the Boots. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

// Include guard
#ifndef Boots_H
#define Boots_H


#include <string>
#include "Item.h"

class Boots: public Item {
	protected:
		// Boots Attributes
		int defense;
		// Constructors
	public:
		Boots();
		Boots(string name, int weight, int value, string image, 
				array<int, 9> enchantmentValues, int defense);
		int getDefense();
		void incrementDefense();
		void decrementDefense();
		std::string toString();
};

#endif // Include guard
