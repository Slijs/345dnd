
#if !defined( GAMELOOPS_H )
#define GAMELOOPS_H

#include "sdl_initialize.h"
#include "prebuiltlevel.h"
#include "leveleditor.h"
#include "windows.h"
#include "textbasedwindow.h"
#include "mapeditorengine.h"
#include "menuengine.h"
#include "userinputandstringmanager.h"
#include "mainmenu.h"
#include "campaignmanager.h"
#include "campaignMAPmanagers.h"
#include "defaultmaps.h"
#include "campaignselect.h"
#include <conio.h>
#include <vector>

//enum destination {mainmenu, gamelevel, leveleditor};
/*!
* Main driver class for the game.
* There is one loop manager that handles the
* direction of what part of the program needs to
* be run.
* Please refer to the namespace DestinationFromMenus in the
* namespaces.h header file for the exact numerical values used
* for destination mapping
*/
class GameLoops
{
private:
	SDL_Event _event;
	int mouse_X_cor;
	int mouse_Y_cor;
	std::string _currentCampaignTracker;

public:
	void loopManager();
	int mainMenuLoop(char* path, char* campaign);
	int gameLevelLoop(std::string mappath);
	int playCampaignLoop(char* path, char* campaign);
	int createNewMap(char* path, char* campaign);
	int levelEditorLoop(LevelEditor* level, char* path, char* campaign);
	int editExistingMap(char* path, char* campaign);
	int editExistingCampaignLoop(char* path, char* campaign);
	int campaignManagerLoop(char* path, char* campaign);
};

#endif