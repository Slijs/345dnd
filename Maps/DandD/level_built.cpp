#include "level_built.h"

Level::Level(std::string path)
{
	_path = path;
}

Level::Level()
{
}

//w = wall
//f = floors
//i = entrence
//e = water
//d = door
//q = door2
//. = blank space (just black)

void Level::createLevelForTargetWindow(SDLWindow* window)
{
	//SDL_Image* image;
	
	GamePlayGridComponents* comp;

	//index 0
	//image = new SDL_Image("assets/levels/sprites/environment/door.png");
	//_environment.push_back(image);
	comp = new GamePlayGridComponents("door", 'd', environment, true, "assets/levels/sprites/environment/door.png");
	_environment_components.push_back(comp);
	

	//index 1
	//image = new SDL_Image("assets/levels/sprites/environment/wall.png");
	//_environment.push_back(image);
	comp = new GamePlayGridComponents("wall", 'w', environment, true, "assets/levels/sprites/environment/wall.png");
	_environment_components.push_back(comp);

	//index 2
	//image = new SDL_Image("assets/levels/sprites/environment/floors.png");
	//_environment.push_back(image);
	comp = new GamePlayGridComponents("floor", 'f', environment, false, "assets/levels/sprites/environment/floors.png");
	_environment_components.push_back(comp);

	//index 3
	//image = new SDL_Image("assets/levels/sprites/environment/water.png");
	//_environment.push_back(image);
	comp = new GamePlayGridComponents("water", 'e', environment, true, "assets/levels/sprites/environment/water.png");
	_environment_components.push_back(comp);

	//index 4
	//image = new SDL_Image("assets/levels/sprites/environment/entrence.png");
	//_environment.push_back(image);
	comp = new GamePlayGridComponents("entrence door", 'i', environment, true, "assets/levels/sprites/environment/entrence.png");
	_environment_components.push_back(comp);

	//index 5
	//image = new SDL_Image("assets/levels/sprites/environment/door2.png");
	//_environment.push_back(image);
	comp = new GamePlayGridComponents("other door", 'q', environment, true, "assets/levels/sprites/environment/door2.png");
	_environment_components.push_back(comp);

	//for(int x=0; x<_environment.size(); x++)
		//_environment[x]->setupImageOnTargetWindowRenderer(window->getRenderer());
	for(int x=0; x<_environment_components.size(); x++)
		_environment_components[x]->setupComponentOnTargetWindowRenderer(window->getRenderer());
}

void Level::setLevelOnTargetWindow(SDLWindow* window)
{
	InputOutput inop = InputOutput();
	_level = inop.readFileLineByLine(_path);
	renderLevel(window);
}

//w = wall
//f = floors
//i = entrence
//e = water
//d = door
//q = door2
//. = blank space (just black)
void Level::renderLevel(SDLWindow* window)
{
	SDL_Rect dest;
	dest.h = window->getGridY_Length();
	dest.w = window->getGridX_Length();
	dest.x = 0;
	dest.y = 0;

	for(int y=0; y<window->getNumberOfGrids_Y(); y++)
	{
		if(_level.size()< y+1)
			break;
		dest.y = y * window->getGridY_Length();
		for(int x=0; x<=window->getNumberOfGrids_X(); x++)
		{
			this->_gameplayGrids.push_back(dest);
			if(_level[y].length() < x+1)
				break;
			dest.x = x * window->getGridX_Length();


			//render environment
			for(int j=0; j<_environment_components.size(); j++)
			{
				if(_level[y].at(x) == _environment_components[j]->getEnvironmentChar())
					window->loadTextureOnRenderer(_environment_components[j]->getImageDetails()->getImageTexture(), nullptr, &dest);
			}

			//render charecters

			//render items and chests

			//else nothing happens, grid remains blank
		}
	}
}

void Level::updateTextFileEnvironment(SDL_Rect gridRef, int environmentIndex, SDLWindow* window)
{
	int xcor = gridRef.x / window->getGamePlay_X_Grids();
	int ycor = gridRef.y / window->getGamePlay_Y_Grids();
	SDL_Rect dest;
	dest.x = gridRef.x;
	dest.y = gridRef.y;
	dest.w = window->getGridX_Length();
	dest.h = window->getGridY_Length();

	//the gridrectangle could consist of multiple grids
	for(int y=gridRef.y; y<(gridRef.h)/(window->getGridY_Length()); y+=(window->getGridY_Length()))
	{
		dest.x = gridRef.x;
		for(int x=gridRef.x; x<(gridRef.w)/(window->getGridX_Length()); x+=(window->getGridX_Length()))
		{
			if(environmentIndex == -1)
			{
				_level[y/(window->getGridY_Length())][x/(window->getGridX_Length())] = '.';
			}
			else
			{
				//_level[y/(window->getGridY_Length())][x/(window->getGridX_Length())] = environmentChars[environmentIndex];
			}
		}
	}
	renderLevel(window);
}

std::vector<GamePlayGridComponents*> Level::getEnvironmentComponents()
{
	return _environment_components;
}

std::vector<SDL_Image*> Level::getEvironmentVector()
{
	return _environment;
}

void Level::addRectToGamePlayGrids(SDL_Rect dest)
{
	this->_gameplayGrids.push_back(dest);
}

std::vector<SDL_Rect> Level::getGameplayGridsRects()
{
	return this->_gameplayGrids;
}

SDL_Texture* Level::getEnvironmentTexture(int index)
{
	if((index+1)>this->_environment_components.size())
	{
		std::cout<<"Invalid index for texture access, exiting program."<<std::endl;
		exit(-1);
	}
	return _environment_components[index]->getImageDetails()->getImageTexture();
}

void Level::destroyLevel()
{
	for(int x=0; x< _environment.size(); x++)
	{
		if(_environment[x]!=nullptr)
		{
			_environment[x]->destroyImage();
			delete _environment[x];
			_environment[x] = nullptr;
		}
	}
	for(int x=0; x<_environment_components.size(); x++)
	{
		if(_environment_components[x]!=nullptr)
		{
			_environment_components[x]->destroyComponent();
			delete _environment_components[x];
			_environment_components[x] = nullptr;
		}
	}
}

Level::~Level()
{
	destroyLevel();
}


UserLevel::UserLevel(SDLWindow* window)
{
	this->_Y_start = (window->getGamePlay_Y_Grids() * window->getGridY_Length()) + (window->getGridY_Length() * 2);

	SDL_Rect dest;
	dest.h = window->getGridY_Length();
	dest.w = window->getGridX_Length();
	dest.x = 0;
	dest.y = 0;

	for(int y=0; y<window->getNumberOfGrids_Y(); y++)
	{
		dest.y = y * window->getGridY_Length();
		for(int x=0; x<=window->getNumberOfGrids_X(); x++)
		{
			dest.x = x * window->getGridX_Length();
			this->addRectToGamePlayGrids(dest);
		}
	}
}

void UserLevel::renderEnvironmentAtBottom(SDLWindow* window)
{
	//define starting and spacing points on the window
	int y_space = (window->getGridY_Length()/2);
	int x_start = (window->getGridX_Length()/2);
	int x_space = (window->getGridX_Length()/2);
	std::vector<GamePlayGridComponents*> env_components = this->getEnvironmentComponents();

	//setup the destination rectangle
	SDL_Rect dest;
	dest.x = x_start;
	dest.y = _Y_start;
	dest.h = window->getGridY_Length();
	dest.w = window->getGridX_Length();
	//render the entire image vector at the bottom 2 per column

	//iterate the columns
	for(int j=0; j<env_components.size(); j++)
	{
		//pushback the detination rect
		this->levelComponentRects.push_back(dest);

		//render top
		if(j%2 == 0)
		{
			window->loadTextureOnRenderer(env_components[j]->getImageDetails()->getImageTexture(), nullptr, &dest);
			dest.y = dest.y + y_space + dest.h;
		}
		
		//render bottom
		else
		{
			window->loadTextureOnRenderer(env_components[j]->getImageDetails()->getImageTexture(), nullptr, &dest);
			dest.y = _Y_start;
			dest.x = dest.x + x_space + dest.w;
		}
	}
}

int UserLevel::get_Y_start()
{
	return this->_Y_start;
}

std::vector<SDL_Rect> UserLevel::getLevelComponentRects()
{
	return this->levelComponentRects;
}