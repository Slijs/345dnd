#pragma once
#include "image.h"


enum environment          {door, wall, floors, water, entrence, door2};
enum gameplayGridComponentTypes {environment, character};

class GamePlayGridComponents
{
private:
	std::string _image_path;
	std::string _componentName;
	SDL_Image* _componentImage;
	char _componentChar;
	gameplayGridComponentTypes _componentType;
	bool _obstructionToPlayer;

public:
	GamePlayGridComponents(std::string componentname, char componentchar, gameplayGridComponentTypes componenttype, bool obstructiontoplayer, std::string imagepath);
	void setupComponentOnTargetWindowRenderer(SDL_Renderer* window_renderer);
	SDL_Image* getImageDetails();
	char getEnvironmentChar();
	bool isComponentObstructionToPlayer();
	void setObstructionToPlayer(bool isobstructiontoplayer);
	std::string getComponentName();
	void destroyComponent();
	~GamePlayGridComponents();
};