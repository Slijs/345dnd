#include "gameplayengine.h"

/*!
*default constructor just sets all values to default and false
*/
GamePlayEngine::GamePlayEngine()
{
	this->_level = nullptr;
	this->_event = nullptr;
	this->_moveSelect = false;
	this->_moveValidityTracker = false;
	this->_interactSelect = false;
	this->_attackSelect = false;
	this->_buttonSelect = false;
	this->_mapExit = false;
	this->_currentGrid.x = -1;
	this->_currentGrid.y = -1;
	this->_lastGrid.x = -1;
	this->_lastGrid.y = -1;
	this->_gridIndex = -1;
	this->_lastButtonIndex = -1;
	this->_exitCharacterIndex = -1;
	this->_exitStringIndex = -1;
	this->_currentButtonIndex = -1;
}

/*!
*attaches a level and an sdl event manager to engine
*/
void GamePlayEngine::attachLevel(PreBuiltLevel* level, SDL_Event* event_)
{
	this->_level = level;
	this->_event = event_;
	this->_buttons = this->_level->getAllButtonDestinations();
	this->_containers = this->_level->getContainersOnMap();
	this->_enemies = this->_level->getEnemiesOnMap();
	this->_observer = new MapObserver(level);

	std::vector<std::string> temp = this->_level->getMapSimpleVersion();
	//setup the exit coordinates
	for (int stringC = 0; stringC < temp.size(); stringC++)
	{
		for (int charInd = 0; charInd < temp[stringC].length(); charInd++)
		{
			if (temp[stringC].at(charInd) == SimplifiedMapSymbols::_ExitDoor_)
			{
				this->_exitStringIndex = stringC;
				this->_exitCharacterIndex = charInd;
				goto DONE;
			}
		}
	}
	DONE:
	;
}

/*!
*detaches level and sdl manager from engine
*/
void GamePlayEngine::detachLevel()
{
	this->_level = nullptr;
	this->_event = nullptr;
	this->_moveSelect = false;
	this->_moveValidityTracker = false;
	this->_interactSelect = false;
	this->_attackSelect = false;
	this->_buttonSelect = false;
	this->_mapExit = false;
	this->_currentGrid.x = -1;
	this->_currentGrid.y = -1;
	this->_lastGrid.x = -1;
	this->_lastGrid.y = -1;
	this->_gridIndex = -1;
	this->_currentButtonIndex = -1;
	this->_buttons.clear();
	this->_containers.clear();
	this->_enemies.clear();
	delete this->_observer;
	this->_observer = nullptr;
}

//index 0 is player status
//index 1 is move
//index 2 is interact
//index 3 is attack
//index 4 is save player
//index 5 is exit play
/*!
*function runs gameplay loop, returns 0 if player prefers going to next map, or 1 if player wants to quit playing campaign
*/
int GamePlayEngine::runEngine()
{
	//error check for level attachment
	if (this->_level == nullptr)
	{
		std::cout << "Error, attempting run gameplay engine without attaching a map, exting program\n";
		getch();
		exit(-1);
	}
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
				this->_attackSelect = false;
				this->_buttonSelect = false;
				if (this->_currentButtonIndex>=0)
					this->_level->getLevelWindow()->changeButtonColor(this->_currentButtonIndex, 255, 0, 0);
			}

			//check if end map has been reached
			if (this->_mapExit == true)
			{
				system("cls");
				this->_level->getLevelWindow()->hideWindow();
				std::cout << "CONGRATS!!! Map has been completed.\n\n";
				std::cout << this->_level->getPlayer()->getName() << " has leveled up!!" << endl;
				std::cout << "\n\nPress any key to see " << this->_level->getPlayer()->getName() << "'s new stats.\n";
				_getch();
				this->_level->getPlayer()->forceLevelIncrease();
				this->_level->getPlayer()->displayOnlyStats();
				std::cout << "\n\nPress any key to continue\n";
				_getch();
				return 0;
			}

			//if move select is true all move function
			if (this->_moveSelect == true)
				movePlayer();

			//if interact select is true and run container interact logic
			if (this->_interactSelect == true)
				interactEnvironment();

			//if attack select is true then run attack logic
			if (this->_attackSelect == true)
				attackEnemy();

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
				if (this->_buttonSelect == false)
				{
					buttonindex = onRIghtHandMenu();
					this->_currentButtonIndex = buttonindex;
					//first check for exit
					if (buttonindex == 5)
					{
						exit = true;
						return 1;
					}

					if (buttonindex == 0)
					{
						this->_buttonSelect = false;
						system("cls");
						this->_level->getLevelWindow()->hideWindow();
						//!!!!!!!!!!!!!!!!!!!!
						// DISPLAY CHARACTER STATS AND INVENTORY HERE
						//!!!!!!!!!!!!!!!!!!!!
						this->_level->getPlayer()->displayStats();
						//getch();
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

					if (buttonindex == 3)
					{
						this->_attackSelect = true;
					}

					if (buttonindex == 4)
					{
						this->_buttonSelect = false;
						this->_level->getLevelWindow()->hideWindow();
						CharacterSaveManager::saveCharacter(this->_level->getPlayer());
						this->_level->getLevelWindow()->unHideWindow();
					}
				}
			}
		}
	}
	return 0;
}

/*!
*function used when player wants to interact with container on environment
*/
void GamePlayEngine::interactEnvironment()
{
	bool interact;
	int mouseIndex;
	int contGridX;
	int contGridY;
	int mouseX;
	int mouseY;
	this->_currentGrid = checkMousePosition(this->_level->getGameplayGridsRects(), &mouseIndex);
	int charIndex = _currentGrid.x / this->_level->getLevelWindow()->getGridX_Length();
	int vectorIndex = _currentGrid.y / this->_level->getLevelWindow()->getGridY_Length();
	for (int x = 0; x < this->_containers.size(); x++)
	{
		interact = this->_level->getPlayer()->validateMapComponentWithinRange(this->_containers[x]->stringIndex, this->_containers[x]->charIndex);
		if (interact == true)
		{
			contGridX = this->_containers[x]->charIndex * this->_level->getLevelWindow()->getGridX_Length();
			contGridY = this->_containers[x]->stringIndex * this->_level->getLevelWindow()->getGridY_Length();
			SDL_GetMouseState(&mouseX, &mouseY);
			if ((mouseX >= contGridX) && (mouseX <= contGridX + this->_level->getLevelWindow()->getGridX_Length()) &&
				(mouseY >= contGridY) && (mouseY <= contGridY + this->_level->getLevelWindow()->getGridY_Length()))
			{
				if ((_event->type == SDL_MOUSEBUTTONUP) && (_event->button.button == SDL_BUTTON_LEFT))
				{
					this->_level->getLevelWindow()->hideWindow();
					system("cls");
					this->_level->getPlayer()->interactWithContainer(this->_containers[x]->container);
					system("cls");
					this->_level->getLevelWindow()->unHideWindow();
					return;
				}
			}
		}
	}	
}

/*!
*funtion used when player wants to engage in combat with an enemy
*/
void GamePlayEngine::attackEnemy()
{
	bool attack;
	int mouseIndex;
	int enGridX;
	int enGridY;
	int mouseX;
	int mouseY;
	this->_currentGrid = checkMousePosition(this->_level->getGameplayGridsRects(), &mouseIndex);
	int charIndex = _currentGrid.x / this->_level->getLevelWindow()->getGridX_Length();
	int vectorIndex = _currentGrid.y / this->_level->getLevelWindow()->getGridY_Length();
	for (int x = 0; x < this->_enemies.size(); x++)
	{
		attack = this->_level->getPlayer()->validateMapComponentWithinRange(this->_enemies[x]->stringIndex, this->_enemies[x]->charIndex);
		if (attack == true)
		{
			enGridX = this->_enemies[x]->charIndex * this->_level->getLevelWindow()->getGridX_Length();
			enGridY = this->_enemies[x]->stringIndex * this->_level->getLevelWindow()->getGridY_Length();
			SDL_GetMouseState(&mouseX, &mouseY);
			if ((mouseX >= enGridX) && (mouseX <= enGridX + this->_level->getLevelWindow()->getGridX_Length()) &&
				(mouseY >= enGridY) && (mouseY <= enGridY + this->_level->getLevelWindow()->getGridY_Length()))
			{
				if ((_event->type == SDL_MOUSEBUTTONUP) && (_event->button.button == SDL_BUTTON_LEFT))
				{
					this->_level->getLevelWindow()->hideWindow();
					system("cls");
					this->_enemies[x]->monster->displayStats();
					std::cout << "\nPress any key to continue.\n";
					getch();
					system("cls");
					this->_level->getLevelWindow()->unHideWindow();
					return;
				}
			}
		}
	}
}

/*!
*function used to move player
*/
void GamePlayEngine::movePlayer()
{
	SDL_Rect dest;
	int mouseIndex = 0;
	std::vector<std::string> temp = this->_level->getMapStringVersiion();
	this->_currentGrid = checkMousePosition(this->_level->getGameplayGridsRects(), &mouseIndex);
	//this->_level->_dest2ForObserver = checkMousePosition(this->_level->getGameplayGridsRects(), &mouseIndex);
	int charIndex = _currentGrid.x / this->_level->getLevelWindow()->getGridX_Length();
	int vectorIndex = _currentGrid.y / this->_level->getLevelWindow()->getGridY_Length();
	this->_moveValidityTracker = this->_level->getPlayer()->validatePlayerMove(vectorIndex, charIndex);
	std::cout << "testing move function\n" << this->_moveValidityTracker<<"\n";
	std::cout << "X: " << _currentGrid.x/this->_level->getLevelWindow()->getGridX_Length() << ", Y: " << _currentGrid.y/this->_level->getLevelWindow()->getGridY_Length() << std::endl;
	
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
								dest.x = x*this->_level->getLevelWindow()->getGridX_Length();
								dest.y = y*this->_level->getLevelWindow()->getGridY_Length();
								dest.h = this->_level->getLevelWindow()->getGridY_Length();
								dest.w = this->_level->getLevelWindow()->getGridX_Length();
								
								//now update the environment for the observer
								this->_level->_environmentForObserver = this->_level->getEnvironmentComponents()[k];

								//make the x y of loop a free path
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
			}//done putting player to floor

			temp[vectorIndex].at(charIndex) = SimplifiedMapSymbols::_Player_;
			this->_level->setMainMapVector(temp);

			//finally update the players vector
			//this->_level->getPlayer()->setMap(&this->_level->getMapSimpleVersion());

			std::cout << std::endl;
			std::cout << "After move\n";
			for (int x = 0; x < this->_level->getMapSimpleVersion().size(); x++)
			{
				std::cout << this->_level->getMapSimpleVersion()[x];
				std::cout << std::endl;
			}
			std::cout << std::endl;
		
			//update the two destination rectangles in subject
			this->_level->setDestRectsForObserver(dest, this->_currentGrid);
			//call the observer update and render and display
			this->_level->Notify();

			//check for end level
			if ((vectorIndex == this->_exitStringIndex) && (charIndex == this->_exitCharacterIndex))
			{
				this->_mapExit = true;
			}
		}
	}
}

/*!
*function used to run the menu on right hand side
*/
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
	{
		this->_buttonSelect = true;
		return index;
	}
		
	return -1;
}

/*!
*function returns a rectangle grid on map based on current mouse position on window
*/
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
