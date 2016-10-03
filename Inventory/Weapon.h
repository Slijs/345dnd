/******************************************************************************
 * Class for the weapons. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

// Include guard
#ifndef Weapon_H
#define Weapon_H


#include <string>
#include "Item.h"

class Weapon: public Item {
	public:
		// Weapon Attributes
		int damage;
		int defense;
		int range;
		// Constructors
		Weapon();
		Weapon(string name, int weight, int value, string image, 
				array<int, 9> enchantmentValues, int damage, int defense, 
				int range);
};

#endif // Include guard
