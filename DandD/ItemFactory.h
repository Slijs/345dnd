#pragma once
#include "Item.h"
#include "Armor.h"
#include "Belt.h"
#include "Boots.h"
#include "Helmet.h"
#include "Ring.h"
#include "Shield.h"
#include "Weapon.h"
#include "namespaces.h"

/**
*@class ItemFactory.h
*@brief Used to create blank prototype items that will be filled in during serialization
*/
class ItemFactory {
public:
	static Item* create(int flag);
};