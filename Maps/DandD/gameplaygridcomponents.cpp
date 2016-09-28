#include "gameplaygridcomponents.h"

GamePlayGridComponents::GamePlayGridComponents(std::string componentname, char componentchar, gameplayGridComponentTypes componenttype, bool obstructiontoplayer, std::string imagepath)
{
	this->_componentChar = componentchar;
	this->_componentImage = nullptr;
	this->_componentName = componentname;
	this->_componentType = componenttype;
	this->_obstructionToPlayer = obstructiontoplayer;
	this->_image_path = imagepath;
}

void GamePlayGridComponents::setupComponentOnTargetWindowRenderer(SDL_Renderer* window_renderer)
{
	_componentImage = new SDL_Image(_image_path);
	_componentImage->setupImageOnTargetWindowRenderer(window_renderer);
}

SDL_Image* GamePlayGridComponents::getImageDetails()
{
	return this->_componentImage;
}

char GamePlayGridComponents::getEnvironmentChar()
{
	return this->_componentChar;
}

bool GamePlayGridComponents::isComponentObstructionToPlayer()
{
	return this->_obstructionToPlayer;
}

std::string GamePlayGridComponents::getComponentName()
{
	return this->_componentName;
}

void GamePlayGridComponents::setObstructionToPlayer(bool isobstructiontoplayer)
{
	this->_obstructionToPlayer = isobstructiontoplayer;
}

void GamePlayGridComponents::destroyComponent()
{
	delete this->_componentImage;
	_componentImage = nullptr;
}

GamePlayGridComponents::~GamePlayGridComponents()
{
	destroyComponent();
}