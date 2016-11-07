/**
 * @brief Class for shields.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

// Include guard
#ifndef Shield_H
#define Shield_H


#include <string>
#include "Item.h"

class Shield: public Item {
	protected:
		// Shield Attributes
		int damage;
		int defense;
		int range;
		// Constructors
	public:
		Shield();
		Shield(string name, int weight, int value, string image, 
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
