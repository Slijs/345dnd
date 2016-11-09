#include "gameplayengine.h"

GamePlayEngine::GamePlayEngine()
{
	this->_level = nullptr;
	this->_event = nullptr;
	this->_moveSelect = false;
	this->_moveValidityTracker = false;
	this->_currentGrid.x = -1;
	this->_currentGrid.y = -1;
	this->_lastGrid.x = -1;
	this->_lastGrid.y = -1;
	this->_gridIndex = -1;
	this->_lastButtonIndex = -1;
}
void GamePlayEngine::attachLevel(PreBuiltLevel* level, SDL_Event* event_)
{
	this->_level = level;
	this->_event = event_;
	this->_buttons = this->_level->getAllButtonDestinations();
}
void GamePlayEngine::detachLevel()
{
	this->_level = nullptr;
	this->_event = nullptr;
	this->_moveSelect = false;
	this->_moveValidityTracker = false;
	this->_currentGrid.x = -1;
	this->_currentGrid.y = -1;
	this->_lastGrid.x = -1;
	this->_lastGrid.y = -1;
	this->_gridIndex = -1;
	this->_buttons.clear();
}

//index 0 is inventory
//index 1 is move
//index 2 is exit play
int GamePlayEngine::runEngine()
{
	bool exit = false;
	int mouse_X;
	int mouse_Y;
	int buttonindex;

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
				//onGameplayGrids();
			}

			//other wise prolly on right hand menu
			else
			{
				buttonindex = onRIghtHandMenu();
				if (buttonindex == 2)
					exit = true;

				if (buttonindex == 0)
				{
					system("cls");
					this->_level->getLevelWindow()->hideWindow();
					std::cout << "inventory pane logic will be here.\npress any key to continue.\n";
					getch();
					system("cls");
					this->_level->getLevelWindow()->unHideWindow();
				}

				if (buttonindex == 1)
				{
					this->_moveSelect = true;
				}
			}
		}
	}
	
	//check mouse position on gameplaygrids

	//check mouse position on right hand menu
	return 0;
}

void GamePlayEngine::movePlayer()
{
	int mouseIndex = 0;

	this->_currentGrid = checkMousePosition(this->_level->getGameplayGridsRects(), &mouseIndex);
	this->_moveValidityTracker = this->_level->getPlayer()->validatePlayerMove(this->_currentGrid.x, this->_currentGrid.y);

	//if validity tracker is true then look for a left mouse click
	if (this->_moveValidityTracker == true)
	{
		if ((_event->type == SDL_MOUSEBUTTONDOWN) && (_event->button.button == SDL_BUTTON_LEFT))
		{
			//first render player to floor
			//loop till find player
			for (int y = 0; y < this->_level->getMapStringVersiion().size(); y++)
			{
				for (int x = 0; x < this->_level->getMapStringVersiion()[y].length(); x++)
				{
					//check if player then render floor
					if (this->_level->getMapStringVersiion()[y].at(x) == SimplifiedMapSymbols::_Player_)
					{
						this->_level->getMapStringVersiion()[y].at(x) = SimplifiedMapSymbols::_FreePath_;
						for (int k = 0; k < this->_level->getEnvironmentComponents().size(); k++)
						{
							if (this->_level->getEnvironmentComponents()[k]->getComponentName() == "floor")
							{
								SDL_Rect dest;
								dest.x = x;
								dest.y = y;
								dest.h = this->_level->getLevelWindow()->getGridY_Length();
								dest.w = this->_level->getLevelWindow()->getGridX_Length();
								//now render with the image details
								SDL_RenderCopy(this->_level->getLevelWindow()->getRenderer(), this->_level->getEnvironmentComponents()[k]->getImageDetails()->getImageTexture(), nullptr, &dest);
							}
						}
					}
				}
			}//done rendering player to floor

			//now render floor of current grid to player
			SDL_RenderCopy(this->_level->getLevelWindow()->getRenderer(), this->_level->getPlayerComponent()->getImageDetails()->getImageTexture(), nullptr, &this->_currentGrid);

			//now update the level vector
			this->_level->getMapStringVersiion()[this->_currentGrid.y].at(this->_currentGrid.x) = SimplifiedMapSymbols::_Player_;

			//finally update the players vector
			this->_level->getPlayer()->setMap(&this->_level->getMapStringVersiion());
		}
	}
}

void GamePlayEngine::onGameplayGrids()
{
	int mouseIndex = 0;

	this->_currentGrid = checkMousePosition(this->_level->getGameplayGridsRects(), &mouseIndex);
	this->_moveValidityTracker = this->_level->getPlayer()->validatePlayerMove(this->_currentGrid.x, this->_currentGrid.y);

	//if at valid index then alphablend the grid to green

	//if at same grid dont do anything
	/*if ((_currentGrid.x == _lastGrid.x) && (_currentGrid.x == _lastGrid.y))
	{

	}
	//otherwise if last grid was valid remove the alphablend from last grid and alphablend current grid
	else
	{

	}*/
}
int GamePlayEngine::onRIghtHandMenu()
{
	//first check which button I am on
	int x_cor, y_cor;
	SDL_GetMouseState(&x_cor, &y_cor);
	int index = _level->getLevelWindow()->getButtonIndexThatMouseIsOn(x_cor, y_cor);

	if (index < 0)
	{
		if (_lastButtonIndex != -1)
			_level->getLevelWindow()->changeButtonColor(_lastButtonIndex, 255, 0, 0);
		_lastButtonIndex = index;
	}
	//now if on a valid new button render new color and check for input and return corresponding index
	else
	{
		if (index != _lastButtonIndex)
		{
			_level->getLevelWindow()->changeButtonColor(index, 0, 255, 0);

			if (_lastButtonIndex != -1)
				_level->getLevelWindow()->changeButtonColor(_lastButtonIndex, 255, 0, 0);
			_lastButtonIndex = index;
		}
	}

	if ((_event->type == SDL_MOUSEBUTTONUP) && (_event->button.button == SDL_BUTTON_LEFT) && (index >= 0))
		return index;
	return -1;
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