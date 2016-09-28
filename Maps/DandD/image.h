#pragma once

#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <iostream>
#include <string>
#include <cstring>

class SDL_Image
{
private:
	SDL_Surface* _source;
	SDL_Texture* _image_texture;
	std::string _path;
	int _width;
	int _height;

public:
	SDL_Image(std::string path);
	void setupImageOnTargetWindowRenderer(SDL_Renderer* window_renderer);
	int getImageHeight();
	int getImageWidth();
	SDL_Texture* getImageTexture();
	void destroyImage();
	~SDL_Image();

	//unimplemented method
	void color_key_image(unsigned int r, unsigned int g, unsigned int b);
};