/******************************************************************************
 * Class for the Rings. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

// Include guard
#ifndef Ring_H
#define Ring_H


#include <string>
#include "Item.h"

class Ring: public Item {
	public:
		Ring();
		Ring(string name, int weight, int value, string image, 
				array<int, 9> enchantmentValues);
};

#endif // Include guard
