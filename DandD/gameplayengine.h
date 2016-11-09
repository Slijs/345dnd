#if !defined (GAMEPLAY_ENGINE_H)
#define GAMEPLAY_ENGINE_H
#include "prebuiltlevel.h"
#include <vector>
class GamePlayEngine
{
private:
	PreBuiltLevel* _level;

public:
	GamePlayEngine();
	void attachLevel(PreBuiltLevel* level);
	void detachLevel();
	int runEngine();
	void onGameplayGrids();
	void onRIghtHandMenu();
	SDL_Rect checkMousePosition(std::vector<SDL_Rect> components, int* targetIndex);
};

#endif