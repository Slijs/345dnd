#include "game_loops.h"

int GameLoops::levelEditorLoop(SDLWindow* window)
{
	int destinationInt =-1;
	SDL_SetRenderDrawColor(window->getRenderer(), 0, 255, 0, 0);
	int y = (window->getGamePlay_Y_Grids() * window->getGridY_Length()) + 1;

	//first draw the horizontal line at bottom
	for(int x=0; x< window->getWindowWidth(); x++)
		SDL_RenderDrawPoint(window->getRenderer(), x, y);

	int x = (window->getGamePlay_X_Grids() * window->getGridX_Length()) + 1;
	//draw vertical line top down on the right
	std::cout<<"X is: "<<x<<std::endl<<"window width: "<<window->getWindowWidth();;
	for(int y=0; y<((window->getGamePlay_Y_Grids() * window->getGridY_Length()) + 1); y++)
	{
		SDL_RenderDrawPoint(window->getRenderer(), x, y);
	}
	window->displayWindow();

	// next put the options at the bottom
	UserLevel* level = new UserLevel(window);
	level->createLevelForTargetWindow(window);
	level->renderEnvironmentAtBottom(window);
	window->displayWindow();

	//put options at the right

	//run the loop till valid level is created
	SDL_SetRenderDrawBlendMode(window->getRenderer(), SDL_BLENDMODE_BLEND);
	std::vector<SDL_Rect> components;
	std::vector<GamePlayGridComponents*> envcomponents = level->getEnvironmentComponents();
	std::vector<std::string> templevel;
	
	for(int y=0; y<window->getGamePlay_Y_Grids(); y++)
	{
		templevel.push_back("");
		for(int x=0; x<window->getGamePlay_X_Grids(); x++)
			templevel[y] = templevel[y] + "."; 
	}

	//test
	for(int x=0; x< templevel.size(); x++)
	{
		std::cout<<templevel[x]<<std::endl;
	}
	//endtest

	int targetIndex;

	SDL_Rect target;
	target.x = 0;
	target.y = 0;
	GamePlayGridComponents* currentenvcomponent = nullptr;
	SDL_Texture* targetTexture = nullptr;
	bool quit = false;
	bool ontargetfirsttime = false;
	bool targetselected = false;
	bool wasAtGamePlayGrids = false;
	bool renderingOnGameplayGrids = false;
	bool loopstartflagfortargetrect = false;
	while(quit==false)
	{
		while(SDL_PollEvent(&_event) != 0)
		{
			SDL_GetMouseState(&this->mouse_X_cor, &this->mouse_Y_cor);
			//this is to ensure if left mouse button was clicked in gameplay grid and released elsewhere,
			//then when the mouse is taken back to gameplay grid nothing renders
			if(renderingOnGameplayGrids == true && (_event.type==SDL_MOUSEBUTTONUP))
				renderingOnGameplayGrids = false;
			if(_event.type == SDL_QUIT)
			{
				quit = true;
				destinationInt = -1;
			}

			//for right button click target selected is false all parameters get reset
			if((_event.type == SDL_MOUSEBUTTONUP)&&(_event.button.button == SDL_BUTTON_RIGHT))
			{
				targetselected = false;
				targetTexture = nullptr;
				ontargetfirsttime = false;
				level->renderEnvironmentAtBottom(window);
				window->displayWindow();
			}

			//for gameplaygrid alphablend on select grids NOTE the -2 as are to give a 2pixel line buffer between the gameplay grid rectangle and rest of the window
			if((mouse_Y_cor<=(((window->getGamePlay_Y_Grids())*window->getGridY_Length()-2))) && (mouse_X_cor<=(((window->getGamePlay_X_Grids())*window->getGridX_Length())-2)))
			{
				wasAtGamePlayGrids = true;
				//for no target selected just do a green alphablend
				if(targetselected == false)
				{
					//check if cursor is already on a target
					if(ontargetfirsttime == true)
					{
						
						//check if moved away from that target
						if(this->checkIfMouseOnARectangle(&target) == false)
						{
							//moved away from target render the target rect back to old state
							if(templevel[target.y/window->getGridY_Length()].at((target.x/window->getGridX_Length())) == '.')
							{
								SDL_SetRenderDrawColor(window->getRenderer(), 0,0,0, 255);
								SDL_RenderFillRect(window->getRenderer(), &target);
								window->displayWindow();
								ontargetfirsttime = false;
							}
						}
					}
					//by here it means at a new target on gameplaygrid
					else
					{
						components = level->getGameplayGridsRects();
						
						target = this->checkMousePosition(components, &targetIndex);

						if(target.x >= 0)
						{
							//alphablend only if the grid does not have an exsting texture
							if(templevel[target.y/window->getGridY_Length()].at((target.x/window->getGridX_Length())) == '.')
							{
								ontargetfirsttime = true;
								SDL_SetRenderDrawColor(window->getRenderer(), 0,255,0, 75);
								SDL_RenderFillRect(window->getRenderer(), &target);
								window->displayWindow();
							}
						}
					}
				}

				//if a target is selected render the texture on target rectangles
				else
				{
					//look for a left button click
					if((_event.type == SDL_MOUSEBUTTONDOWN)&&(_event.button.button == SDL_BUTTON_LEFT))
						renderingOnGameplayGrids = true;

					if(renderingOnGameplayGrids == true)
					{
						target = getRectGridOfMouse(window);
						SDL_RenderCopy(window->getRenderer(), targetTexture, nullptr, &target);
						templevel[target.y/window->getGridY_Length()].at((target.x/window->getGridX_Length())) = envcomponents[targetIndex]->getEnvironmentChar();
						window->displayWindow();
					}

					if((_event.type == SDL_MOUSEBUTTONUP)&&(_event.button.button == SDL_BUTTON_LEFT))
						renderingOnGameplayGrids = false;
				}
			}

			//check if mouse is in bottom range only if a target is not selected
			else if((mouse_Y_cor>(window->getGamePlay_Y_Grids())*window->getGridY_Length()) && (targetselected == false))
			{
				if(wasAtGamePlayGrids == true)
				{
					wasAtGamePlayGrids = false;
					ontargetfirsttime = false;
					if(templevel[target.y/window->getGridY_Length()].at((target.x/window->getGridX_Length())) == '.')
					{
						SDL_SetRenderDrawColor(window->getRenderer(), 0,0,0, 255);
						SDL_RenderFillRect(window->getRenderer(), &target);
						window->displayWindow();
					}
					
				}
				
				if(targetselected == false)
				{
					components = level->getLevelComponentRects();
					//check on which rect
					target = this->checkMousePosition(components, &targetIndex);
					//if mouse is on target check to see for a click event
					if(target.x >= 0)
					{
						if(ontargetfirsttime ==  false)
						{
							ontargetfirsttime = true;
							SDL_SetRenderDrawColor(window->getRenderer(), 0,255,0, 75);
							SDL_RenderFillRect(window->getRenderer(), &target);
							window->displayWindow();
						}

						//lookout for a click event for target
						if((_event.type == SDL_MOUSEBUTTONUP)&&(_event.button.button == SDL_BUTTON_LEFT))
						{
							targetselected = true;
							//targetTexture = level->getEnvironmentTexture(targetIndex);
							targetTexture = envcomponents[targetIndex]->getImageDetails()->getImageTexture();
						}
					}
					//if mouse is not on a target then render the bottom fresh
					else
					{
						ontargetfirsttime = false;
						level->renderEnvironmentAtBottom(window);
						window->displayWindow();
					}
				}
			}
		}
	}
	std::cout<<"After the shit: "<<std::endl<<std::endl;
	std::ofstream file;
	file.open(_userCreatedLevelPath + _userCreatedLevelFileName);

	for(int x=0; x<templevel.size(); x++)
	{
		file<<templevel[x]<<std::endl;
		std::cout<<templevel[x]<<std::endl;
	}
	file.close();

	destroyLevel(level);
	level = nullptr;
	//save the level on text file
	return destinationInt;
}