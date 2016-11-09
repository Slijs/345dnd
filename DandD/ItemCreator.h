#ifndef ITEM_CREATOR_H
#define ITEM_CREATOR_H

#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <afx.h>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Belt.h"
#include "Boots.h"
#include "Helmet.h"
#include "Ring.h"
#include "Shield.h"
#include "Container.h"

// don't use the windows.h max
#undef max

class ItemCreator {
public:
	static void createItems();
};

#endif