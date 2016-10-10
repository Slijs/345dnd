/******************************************************************************
 * Class for the Helmets. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

// Include guard
#ifndef Helmet_H
#define Helmet_H


#include <string>
#include "Item.h"

class Helmet: public Item {
	protected:
		// Helmet Attributes
		int defense;
		// Constructors
	public:
		Helmet();
		Helmet(string name, int weight, int value, string image, 
				array<int, 9> enchantmentValues, int defense);
		int getDefense();
		void incrementDefense();
		void decrementDefense();
		std::string toString();
};

#endif // Include guard
