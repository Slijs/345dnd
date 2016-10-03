/******************************************************************************
 * Class for weapons. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

#include <string>
#include <stdexcept>
#include "Weapon.h"

// Default constructor, useless item as is
Weapon::Weapon() : 	
	Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,1,1}) 
{

}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Weapon::Weapon(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int damage, int defense, int range) 
	: Item(name, weight, value, image, enchantmentValues, {0,0,0,0,0,0,0,1,1}),
	damage(damage), defense(defense), range(range)
{

}
