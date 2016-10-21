/**
 * @brief Class for all armor.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

// Include guard
#ifndef Armor_H
#define Armor_H


#include <string>
#include "Item.h"

class Armor: public Item {
	protected:
		// Armor Attributes
		int defense;
		/**
		 * @brief These are the enchantments possible. Order:
		 * Strength, Dexterity, Constitution, Intelligence, Wisdom,
		 * Charisma, Armor Class, Attack Bonus, Damage Bonus.
		 */
		const array<int, 9> enchantmentsPossible = {0,0,0,0,0,0,1,0,0};
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
