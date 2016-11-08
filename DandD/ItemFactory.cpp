#include "ItemFactory.h"

Item* ItemFactory::create(int flag) {
	switch (flag) {
	case(ItemTypes::Armor):
		return new Armor();
	case(ItemTypes::Belt):
		return new Belt();
	case(ItemTypes::Boots):
		return new Boots();
	case(ItemTypes::Helmet):
		return new Helmet();
	case(ItemTypes::Ring):
		return new Ring();
	case(ItemTypes::Shield):
		return new Shield();
	case(ItemTypes::Weapon):
		return new Weapon();
	default:
		return new Item();
	}
}