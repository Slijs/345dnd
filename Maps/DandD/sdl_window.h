#pragma once

#include <SDL\SDL.h>
#include <iostream>
#include <cstring>
#include <vector>

class SDLWindow
{
private:
	unsigned int _window_height;
	unsigned int _window_width;
	int _red;
	int _green;
	int _blue;
	int _grid_X_length;
	int _grid_Y_length;
	int _grids_horizontal;
	int _grids_vertical;
	int _X_grids_for_gameplay;
	int _Y_grids_for_gameplay;
	const char* _window_title;
	SDL_Renderer* _renderer;
	SDL_Window* _window;

public:
	SDLWindow(const char* title);
	SDLWindow(const char* title, int num_of_horizontal_grids, int num_of_vertical_grids);
	SDL_Renderer* getRenderer();
	unsigned int getWindowHeight();
	unsigned int getWindowWidth();
	int getGridX_Length();
	int getGridY_Length();
	int getNumberOfGrids_X();
	int getNumberOfGrids_Y();
	int getGamePlay_X_Grids();
	int getGamePlay_Y_Grids();
	void setDrawColor(int r, int g, int b);
	void loadTextureOnRenderer(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination, double angle, SDL_Point* center, SDL_RendererFlip flip);
	void loadTextureOnRenderer(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination);
	void clearWindowRenderer();
	void displayWindow();
	void destroyWindow();
	~SDLWindow();
};