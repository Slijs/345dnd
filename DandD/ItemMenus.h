#pragma once
#include "menus.h"

using namespace BaseMenuColorIndex;
using namespace DestinationFromMenus;

class ItemMenus :
	public Menus
{
public:
	ItemMenus(std::string title);
	void setupMenu();
	int destinationMap(int index);
	~ItemMenus();
};