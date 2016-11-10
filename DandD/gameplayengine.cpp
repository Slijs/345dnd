#include "gameplayengine.h"

GamePlayEngine::GamePlayEngine()
{
	this->_level = nullptr;
	this->_event = nullptr;
	this->_moveSelect = false;
	this->_moveValidityTracker = false;
	this->_interactSelect = false;
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
	this->_containers = this->_level->getContainersOnMap();
}
void GamePlayEngine::detachLevel()
{
	this->_level = nullptr;
	this->_event = nullptr;
	this->_moveSelect = false;
	this->_moveValidityTracker = false;
	this->_interactSelect = false;
	this->_currentGrid.x = -1;
	this->_currentGrid.y = -1;
	this->_lastGrid.x = -1;
	this->_lastGrid.y = -1;
	this->_gridIndex = -1;
	this->_buttons.clear();
	this->_containers.clear();
}

//index 0 is player status
//index 1 is move
//index 2 is interact
//index 3 is exit play
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
			{
				this->_moveSelect = false;
				this->_interactSelect = false;
			}

			//if move select is true all move function
			if (this->_moveSelect == true)
				movePlayer();

			//if interact select is true and run container interact logic
			if (this->_interactSelect == true)
				interactEnvironment();

			//get current mouse coordinates
			SDL_GetMouseState(&mouse_X, &mouse_Y);

			//check if on gameplay grids
			if ((mouse_X < (this->_level->getLevelWindow()->getGamePlay_X_Grids() * this->_level->getLevelWindow()->getGridX_Length())) &&
				(mouse_Y < (this->_level->getLevelWindow()->getGamePlay_Y_Grids() * this->_level->getLevelWindow()->getGridY_Length())))
			{
				//onGameplayGrids();
			}

			//other wise prolly on right hand menu
			else
			{
				buttonindex = onRIghtHandMenu();
				//first check for exit
				if (buttonindex == 3)
					exit = true;

				if (buttonindex == 0)
				{
					system("cls");
					this->_level->getLevelWindow()->hideWindow();
					//!!!!!!!!!!!!!!!!!!!!
					// DISPLAY CHARACTER STATS AND INVENTORY HERE
					//!!!!!!!!!!!!!!!!!!!!
					this->_level->getPlayer()->displayStats();
					getch();
					system("cls");
					this->_level->getLevelWindow()->unHideWindow();
				}

				if (buttonindex == 1)
				{
					this->_moveSelect = true;
				}

				if (buttonindex == 2)
				{
					this->_interactSelect = true;
				}
			}
		}
	}
	
	//check mouse position on gameplaygrids

	//check mouse position on right hand menu
	return 0;
}

void GamePlayEngine::interactEnvironment()
{
	bool interact;
	int mouseIndex;
	int contGridX;
	int contGridY;
	this->_currentGrid = checkMousePosition(this->_level->getGameplayGridsRects(), &mouseIndex);
	int charIndex = _currentGrid.x / this->_level->getLevelWindow()->getGridX_Length();
	int vectorIndex = _currentGrid.y / this->_level->getLevelWindow()->getGridY_Length();
	for (int x = 0; x < this->_containers.size(); x++)
	{
		//std::cout << "vector index: " << this->_containers[x]->stringIndex << "char index: " << this->_containers[x]->charIndex<<std::endl;
		interact = this->_level->getPlayer()->validateChestWithinRange(this->_containers[x]->stringIndex, this->_containers[x]->charIndex);
		//interact = this->_level->getPlayer()->validateComponent
		//std::cout << "validate chest function return: " << interact << std::endl;
		//std::cout << "X: " << contGridX << "Y: " << contGridY <<"interact return: "<<interact<< std::endl;
		//if interact is true then lookout for a left button click on that part of the map
		if (interact == true)
		{
			contGridX = this->_containers[x]->charIndex * this->_level->getLevelWindow()->getGridX_Length();
			contGridY = this->_containers[x]->stringIndex * this->_level->getLevelWindow()->getGridY_Length();
			std::cout << "X cont: " << contGridX << "Y cont: " << contGridY << std::endl;
			std::cout << "X mouse: " << _currentGrid.x << "Y mouse: " << _currentGrid.y << std::endl;
			//check if mouse is range of this then lookout for a left mousebutton click
			
			if ((this->_currentGrid.x >= contGridX) && (this->_currentGrid.x <= contGridX + this->_level->getLevelWindow()->getGridX_Length()) &&
				(this->_currentGrid.y >= contGridY) && (this->_currentGrid.y <= contGridY + this->_level->getLevelWindow()->getGridY_Length()))
			{
				if ((_event->type == SDL_MOUSEBUTTONUP) && (_event->button.button == SDL_BUTTON_LEFT))
				{
					this->_level->getLevelWindow()->hideWindow();
					system("cls");
					std::cout<<this->_containers[x]->container->contentsToString();
					getch();
					system("cls");
					this->_level->getLevelWindow()->unHideWindow();
					return;
				}
			}
		}
	}	
}

void GamePlayEngine::movePlayer()
{
	
	int mouseIndex = 0;
	std::vector<std::string> temp = this->_level->getMapStringVersiion();
	this->_currentGrid = checkMousePosition(this->_level->getGameplayGridsRects(), &mouseIndex);
	int charIndex = _currentGrid.x / this->_level->getLevelWindow()->getGridX_Length();
	int vectorIndex = _currentGrid.y / this->_level->getLevelWindow()->getGridY_Length();
	this->_moveValidityTracker = this->_level->getPlayer()->validatePlayerMove(vectorIndex, charIndex);
	std::cout << "testing move function\n" << this->_moveValidityTracker<<"\n";
	std::cout << "X: " << _currentGrid.x/this->_level->getLevelWindow()->getGridX_Length() << ", Y: " << _currentGrid.y/this->_level->getLevelWindow()->getGridY_Length() << std::endl;
	//if validity tracker is true then look for a left mouse click
	
	std::cout << std::endl;
	std::cout << "Before move\n";
	for (int x = 0; x < this->_level->getMapSimpleVersion().size(); x++)
	{
		std::cout << this->_level->getMapSimpleVersion()[x];
		std::cout<<std::endl;
	}
	std::cout << std::endl;

	if (this->_moveValidityTracker == true)
	{
		if ((_event->type == SDL_MOUSEBUTTONDOWN) && (_event->button.button == SDL_BUTTON_LEFT))
		{
			//first render player to floor
			//loop till find player
			for (int y = 0; y < temp.size(); y++)
			{
				for (int x = 0; x < temp[y].length(); x++)
				{
					//check if player then render floor
					if (temp[y].at(x) == SimplifiedMapSymbols::_Player_)
					{
						//make the coordinate in map a free path
						//this->_level->getMapStringVersiion()[y].at(x) = SimplifiedMapSymbols::_FreePath_;
						for (int k = 0; k < this->_level->getEnvironmentComponents().size(); k++)
						{
							//render the floor
							if (this->_level->getEnvironmentComponents()[k]->getComponentName() == "floor")
							{
								SDL_Rect dest;
								dest.x = x*this->_level->getLevelWindow()->getGridX_Length();
								dest.y = y*this->_level->getLevelWindow()->getGridY_Length();
								dest.h = this->_level->getLevelWindow()->getGridY_Length();
								dest.w = this->_level->getLevelWindow()->getGridX_Length();
								//now render with the image details
								SDL_RenderCopy(this->_level->getLevelWindow()->getRenderer(), this->_level->getEnvironmentComponents()[k]->getImageDetails()->getImageTexture(), nullptr, &dest);
								SDL_RenderPresent(this->_level->getLevelWindow()->getRenderer());

								//make the x y of loop a free path
								//this->_level->getMapStringVersiion()[y].at(x) = SimplifiedMapSymbols::_FreePath_;
								temp[y].at(x) = this->_level->getEnvironmentComponents()[k]->getComponentChar();
								this->_level->setMainMapVector(temp);
								std::cout << std::endl;
								std::cout << "During move\n";
								for (int x = 0; x < this->_level->getMapSimpleVersion().size(); x++)
								{
									std::cout << this->_level->getMapSimpleVersion()[x];
									std::cout << std::endl;
								}
								std::cout << std::endl;
							}
						}
					}
				}
			}//done rendering player to floor


			//now render floor of current grid to player
			SDL_RenderCopy(this->_level->getLevelWindow()->getRenderer(), this->_level->getPlayerComponent()->getImageDetails()->getImageTexture(), nullptr, &this->_currentGrid);
			SDL_RenderPresent(this->_level->getLevelWindow()->getRenderer());

			temp[vectorIndex].at(charIndex) = SimplifiedMapSymbols::_Player_;
			this->_level->setMainMapVector(temp);

			//finally update the players vector
			this->_level->getPlayer()->setMap(&this->_level->getMapSimpleVersion());

			std::cout << std::endl;
			std::cout << "After move\n";
			for (int x = 0; x < this->_level->getMapSimpleVersion().size(); x++)
			{
				std::cout << this->_level->getMapSimpleVersion()[x];
				std::cout << std::endl;
			}
			std::cout << std::endl;
		
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