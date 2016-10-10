/******************************************************************************
 * Class for the Belts. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

// Include guard
#ifndef Belt_H
#define Belt_H


#include <string>
#include "Item.h"

class Belt: public Item {
	protected:
		// Belt Attributes
		int defense;
		// Constructors
	public:
		Belt();
		Belt(string name, int weight, int value, string image, 
				array<int, 9> enchantmentValues, int defense);
		int getDefense();
		void incrementDefense();
		void decrementDefense();
		std::string toString();
};

#endif // Include guard
