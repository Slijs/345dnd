
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
#include "assignment2.h"
#include "campaignmanager.h"
#include "campaignMAPmanagers.h"
#include "defaultmaps.h"
#include <conio.h>
#include <vector>

enum destination {mainmenu, gamelevel, leveleditor};
/*!
* Main driver class for the engine.
* can be subdivided into three components,
* the main menu, the map editor and the main
* game loop.
* There is one loop manager that handles the
* direction of what part of the program needs to
* be run.
* for this assignment, we have three cases, 1 is
* for main menu, 2 is for loading a valid map
* 3 the main one which is the map creation loop
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
	int assignmentTWOLoop(char* path, char* campaign);
	int gameLevelLoop();
	int createNewMap(char* path, char* campaign);
	int levelEditorLoop(LevelEditor* level, char* path, char* campaign);
	int editExistingMap(char* path, char* campaign);
	int editExistingCampaignLoop(char* path, char* campaign);
	int campaignManagerLoop(char* path, char* campaign);
};

#endif