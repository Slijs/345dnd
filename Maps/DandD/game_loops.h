#pragma once
#include "sdl_initialize.h"
#include "level_built.h"


//THE GAME IS 34 by 20 GRIDS
//THE WINDOW IS 38 by 20 GRIDS

enum destination {mainmenu, gamelevel, leveleditor};

class GameLoops
{
private:
	SDL_Event _event;
	SDLWindow* _window;
	int mouse_X_cor;
	int mouse_Y_cor;
	std::string _userCreatedLevelPath;
	std::string _userCreatedLevelFileName;

public:
	GameLoops();
	void loopManager();
	int mainMenuLoop(SDLWindow* window);
	int gameLevelLoop(SDLWindow* window);
	int levelEditorLoop(SDLWindow* window);
	SDL_Rect checkMousePosition(std::vector<SDL_Rect> components, int* targetIndex);
	bool checkIfMouseOnARectangle(SDL_Rect* target);
	SDL_Rect getRectGridOfMouse(SDLWindow* window);
	void destroyLevel(Level* level);
	void destroyLoops();
	~GameLoops();
};