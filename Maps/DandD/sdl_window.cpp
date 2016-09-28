#include "sdl_window.h"

//constructor creates the window but does not display it
SDLWindow::SDLWindow(const char* title)
{
	//set private pointers to null poniters and assign the title
	_grid_X_length = 1;
	_grid_Y_length = 1;
	_X_grids_for_gameplay = 34;
	_Y_grids_for_gameplay = 20;
	_grids_horizontal = 1;
	_grids_vertical = 1;
	_window_title = title;
	_window = nullptr;
	_renderer = nullptr;
	_red = 0;
	_green = 0;
	_blue = 100;

	//setup window height and width based on monitor height and width
	SDL_DisplayMode monitor;
	if(SDL_GetCurrentDisplayMode(0, &monitor) != 0)
	{
		std::cout<<"Failed to create an SDL window."<<std::endl;
		system("pause");
		exit(-1);
	}
	_window_height = ((monitor.h)/2);
	_window_width = ((monitor.w)/2);

	//now initialize the window
	_window = SDL_CreateWindow(_window_title, 30,30, _window_width, _window_height, SDL_WINDOW_SHOWN);

	//initialize window renderer
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(_renderer == nullptr)
	{
		std::cout<<"Failed to create renderer for window: "<<SDL_GetError()<<std::endl;
		system("pause");
		exit(-1);
	}
	std::cout<<"Window renderer successfully created."<<std::endl;
}

//constructor creates the window but does not display it
SDLWindow::SDLWindow(const char* title, int num_of_horizontal_grids, int num_of_vertical_grids)
{
	_X_grids_for_gameplay = 34;
	_Y_grids_for_gameplay = 20;
	//set private pointers to null poniters and assign the title
	if(num_of_horizontal_grids < 1 || num_of_vertical_grids < 1)
	{
		std::cout<<"Attempted grid dimension is too low, failed to create window. Exiting program."<<std::endl;
		system("pause");
		exit(-1);
	}
	_grids_vertical = num_of_vertical_grids;
	_grids_horizontal = num_of_horizontal_grids;
	_window_title = title;
	_window = nullptr;
	_renderer = nullptr;
	_red = 0;
	_green = 0;
	_blue = 100;

	//setup window height and width based on monitor height and width
	SDL_DisplayMode monitor;
	if(SDL_GetCurrentDisplayMode(0, &monitor) != 0)
	{
		std::cout<<"Failed to create an SDL window."<<std::endl;
		system("pause");
		exit(-1);
	}
	_window_height = (int)((float)(monitor.h)/1.5f) + (_grids_vertical-(((monitor.h)/2)%_grids_vertical));
	_window_width = (int)((float)(monitor.w)/1.5f) + (_grids_horizontal-(((monitor.w)/2)%_grids_horizontal));
	_grid_X_length = _window_width / _grids_horizontal;
	_grid_Y_length = _window_height / _grids_vertical;

	//now initialize the window
	_window = SDL_CreateWindow(_window_title, 30,30, _window_width, _window_height, SDL_WINDOW_SHOWN);

	//initialize window renderer
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(_renderer == nullptr)
	{
		std::cout<<"Failed to create renderer for window: "<<SDL_GetError()<<std::endl;
		system("pause");
		exit(-1);
	}
	std::cout<<"Window renderer successfully created."<<std::endl;
}

//load a texture on the renderer with additinal angle point and flip parameters
void SDLWindow::loadTextureOnRenderer(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	if(texture == nullptr)
	{
		std::cout<<"Null texture rendering attempted."<<std::endl;
		SDL_RenderPresent(_renderer);
		return;
	}
	SDL_RenderCopyEx(_renderer, texture, source, destination, angle, center, flip);
}

//load a simple texture on the renderer
void SDLWindow::loadTextureOnRenderer(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination)
{
	if(texture == nullptr)
	{
		std::cout<<"Null texture rendering attempted."<<std::endl;
		SDL_RenderPresent(_renderer);
		return;
	}
	SDL_RenderCopy(_renderer, texture, source, destination);
}

//clear the window renderer
void SDLWindow::clearWindowRenderer()
{
	SDL_RenderClear(_renderer);
}

//display window
void SDLWindow::displayWindow()
{
	SDL_RenderPresent(_renderer);
	//SDL_ShowWindow(_window);
}

//set the current drawing color on renderer
void SDLWindow::setDrawColor(int r, int g, int b)
{
	_red = r;
	_green = g;
	_blue = b;
	SDL_SetRenderDrawColor(_renderer, _red, _green, _blue, 0);
}

//access window renderer
SDL_Renderer* SDLWindow::getRenderer()
{
	return _renderer;
}

//access window height
unsigned int SDLWindow::getWindowHeight()
{
	return _window_height;
}

//access window width
unsigned int SDLWindow::getWindowWidth()
{
	return _window_width;
}

int SDLWindow::getGridX_Length()
{
	return _grid_X_length;
}

int SDLWindow::getGridY_Length()
{
	return _grid_Y_length;
}

int SDLWindow::getNumberOfGrids_X()
{
	return _grids_horizontal;
}

int SDLWindow::getNumberOfGrids_Y()
{
	return _grids_vertical;
}


int SDLWindow::getGamePlay_X_Grids()
{
	return _X_grids_for_gameplay;
}
int SDLWindow::getGamePlay_Y_Grids()
{
	return _Y_grids_for_gameplay;
}



//destroy window
void SDLWindow::destroyWindow()
{
	if(_window!=nullptr)
		SDL_DestroyWindow(_window);
	if(_renderer!=nullptr)
		SDL_DestroyRenderer(_renderer);
	_window = nullptr;
	_renderer = nullptr;
}

//destructor
SDLWindow::~SDLWindow()
{
	destroyWindow();
	std::cout<<"window destroyed";
}