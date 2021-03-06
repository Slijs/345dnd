/**
 * @brief Class for weapons.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

// Include guard
#ifndef Weapon_H
#define Weapon_H


#include <string>
#include "Item.h"

class Weapon: public Item {
	protected:
		// Weapon Attributes
		int damage;
		int defense;
		int range;
		// Constructors
	public:
		Weapon();
		Weapon(string name, int weight, int value, string image, 
				array<int, 9> enchantmentValues, int damage, int defense, 
				int range);
		int getDamage();
		int getDefense();
		int getRange();
		void incrementDamage();
		void decrementDamage();
		void incrementDefense();
		void decrementDefense();
		void incrementRange();
		void decrementRange();
		std::string toString();
};

#endif // Include guard
