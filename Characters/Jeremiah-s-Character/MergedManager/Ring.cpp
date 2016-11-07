/**
 * @brief Class for rings.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

#include <string>
#include <stdexcept>
#include "Ring.h"

IMPLEMENT_SERIAL(Ring, Item, 1);

// Default constructor, useless item as is
Ring::Ring() : 	
	Item("No name set", 0, 0, "No Image Set", {0,0,0,0,0,0,0,0,0}, {1,0,1,0,1,1,1,0,0}) 
{

}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Ring::Ring(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues) 
	: Item(name, weight, value, image, enchantmentValues, {1,0,1,0,1,1,1,0,0})
{

}

void Ring::Serialize(CArchive &ar) {
	Item::Serialize();
}