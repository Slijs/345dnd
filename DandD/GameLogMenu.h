
#ifndef GAMELOGMENU_H
#define GAMELOGMENU_H
#include "menus.h"

class GameLogMenu : public Menus
{
public:
	GameLogMenu(std::string title);
	void setupMenu();
	int destinationMap(int index);
}