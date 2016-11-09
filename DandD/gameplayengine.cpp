#include "gameplayengine.h"

GamePlayEngine::GamePlayEngine()
{
	this->_level = nullptr;
	this->_event = nullptr;
	this->_moveSelect = false;
	this->_currentGrid.x = -1;
	this->_currentGrid.y = -1;
	this->_lastGrid.x = -1;
	this->_lastGrid.y = -1;
	this->_gridIndex = -1;
}
void GamePlayEngine::attachLevel(PreBuiltLevel* level, SDL_Event* event_)
{
	this->_level = level;
	this->_event = event_;
}
void GamePlayEngine::detachLevel()
{
	this->_level = nullptr;
	this->_event = nullptr;
	this->_moveSelect = false;
	this->_currentGrid.x = -1;
	this->_currentGrid.y = -1;
	this->_lastGrid.x = -1;
	this->_lastGrid.y = -1;
	this->_gridIndex = -1;
}

int GamePlayEngine::runEngine()
{
	bool exit = false;
	int mouse_X;
	int mouse_Y;

	while (exit == false)
	{
		while (SDL_PollEvent(this->_event) != 0)
		{
			//first check for a right button if so ensure that player select becomes false.
			if ((_event->type == SDL_MOUSEBUTTONDOWN) && (_event->button.button == SDL_BUTTON_RIGHT))
				this->_moveSelect = false;

			//get current mouse coordinates
			SDL_GetMouseState(&mouse_X, &mouse_Y);

			//check if on gamplaye grids
			if ((mouse_X < (this->_level->getLevelWindow()->getGamePlay_X_Grids() * this->_level->getLevelWindow()->getGridX_Length())) &&
				(mouse_Y < (this->_level->getLevelWindow()->getGamePlay_Y_Grids() * this->_level->getLevelWindow()->getGridY_Length())))
			{
				onGameplayGrids();
			}

			//other wise prolly on right hand menu
			else
			{
				onRIghtHandMenu();
			}
		}
	}
	
	//check mouse position on gameplaygrids

	//check mouse position on right hand menu
	return 0;
}

void GamePlayEngine::onGameplayGrids()
{
	SDL_Rect on_Gameplay_Grids;
	int mouseIndex = 0;

	on_Gameplay_Grids = checkMousePosition(this->_level->getGameplayGridsRects(), &mouseIndex);
	this->_level->getPlayer()->validatePlayerMove(on_Gameplay_Grids.x, on_Gameplay_Grids.y);
	
}
void GamePlayEngine::onRIghtHandMenu()
{

}

SDL_Rect GamePlayEngine::checkMousePosition(std::vector<SDL_Rect> components, int* targetIndex)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	for (int z = 0; z<components.size(); z++)
	{
		if ((x >= components[z].x) && (x <= components[z].x + components[z].w)
			&& (y >= components[z].y) && (y <= components[z].y + components[z].h))
		{
			*targetIndex = z;
			return components[z];
		}
	}
	SDL_Rect d;
	d.x = -5;
	d.y = -5;
	d.h = -5;
	d.w = -5;
	return d;
}

//Fighter::validatePlayerMove(int x, int y)