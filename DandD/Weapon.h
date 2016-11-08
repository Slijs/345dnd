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
		DECLARE_SERIAL(Weapon);
		// Constructors
	public:
		Weapon();
		Weapon(const Weapon* otherWeapon);
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
		virtual void Serialize(CArchive &ar); // Allows Serialization of Weapon
};

#endif // Include guard
