#include "game_loops.h"

GameLoops::GameLoops()
{
	_userCreatedLevelPath = "assets/levels/text/UserCreated/";
	_userCreatedLevelFileName = "file.txt";
}

void GameLoops::loopManager()
{
	//test code
	bool builtlevel = false;
	bool leveleditor = true;
	bool mainmenu = false;
	//test end

	SDLSetup setup = SDLSetup();
	setup.SDL_Initialize_All_Functionalities();



	std::string title = "test";
	SDLWindow window = SDLWindow(title.c_str(), 38, 25);
	window.displayWindow();

	std::cout<<"grid width: "<<window.getWindowWidth()/window.getNumberOfGrids_X();
	std::cout<<"grid height: "<<window.getWindowHeight()/window.getNumberOfGrids_Y();

	if(builtlevel == true)
	{
		gameLevelLoop(&window);
	}

	if(leveleditor == true)
	{
		levelEditorLoop(&window);
	}

	if(mainmenu == true)
	{
	}

	if(gameLevelLoop(&window) == -1)
		SDL_Quit();
}

int GameLoops::mainMenuLoop(SDLWindow* window)
{
	int destinationInt;
	return destinationInt;
}

int GameLoops::gameLevelLoop(SDLWindow* window)
{
	int destinationInt;
	bool quit = false;

	Level l = Level(_userCreatedLevelPath + _userCreatedLevelFileName);
	l.createLevelForTargetWindow(window);
	l.setLevelOnTargetWindow(window);
	window->displayWindow();
	destinationInt = -1;

	while(quit==false)
	{
		while(SDL_PollEvent(&_event) != 0)
		{
			if(_event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
	return destinationInt;
}

//int GameLoops::levelEditorLoop(SDLWindow* window)
//levelEditorLoop(SDLWindow* window) is in levelEditorLoop.cpp

SDL_Rect GameLoops::checkMousePosition(std::vector<SDL_Rect> components, int* targetIndex)
{
	SDL_GetMouseState(&this->mouse_X_cor, &this->mouse_Y_cor);
	for(int x=0; x<components.size(); x++)
	{
		if((this->mouse_X_cor>= components[x].x) && (this->mouse_X_cor<=components[x].x+components[x].w)
			&& (this->mouse_Y_cor>=components[x].y) && (this->mouse_Y_cor<=components[x].y+components[x].h))
		{
			*targetIndex = x;
			return components[x];
		}
	}
	SDL_Rect d;
	d.x = -5;
	d.y = -5;
	d.h = -5;
	d.w = -5;
	return d;
}

bool GameLoops::checkIfMouseOnARectangle(SDL_Rect* target)
{
	if((this->mouse_X_cor>= target->x) && (this->mouse_X_cor<= (target->x + target->w))
		&&(this->mouse_Y_cor>= target->y) && (this->mouse_Y_cor<= (target->y + target->h)))
		return true;
	return false;
}

SDL_Rect GameLoops::getRectGridOfMouse(SDLWindow* window)
{
	SDL_Rect dest;
	dest.x = mouse_X_cor - (mouse_X_cor % window->getGridX_Length());
	dest.y = mouse_Y_cor - (mouse_Y_cor % window->getGridY_Length());
	dest.h = window->getGridY_Length();
	dest.w = window->getGridX_Length();
	return dest;
}

void GameLoops::destroyLevel(Level* level)
{
	delete level;
}

void GameLoops::destroyLoops()
{
}

GameLoops::~GameLoops()
{
}