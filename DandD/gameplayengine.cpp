#include "gameplayengine.h"

GamePlayEngine::GamePlayEngine()
{
	this->_level = nullptr;
}
void GamePlayEngine::attachLevel(PreBuiltLevel* level)
{
	this->_level = level;
}
void GamePlayEngine::detachLevel()
{
	this->_level = nullptr;
}

int GamePlayEngine::runEngine()
{
	//check mouse position on gameplaygrids

	//check mouse position on right hand menu
	return 0;
}

void GamePlayEngine::onGameplayGrids()
{
	SDL_Rect on_Gameplay_Grids;
	int mouseIndex = 0;
	on_Gameplay_Grids = checkMousePosition(this->_level->getGameplayGridsRects(), &mouseIndex);
	this->_level->getPlayer()->validatePlayerMove(on_Gameplay_Grids.x, on_Gameplay_Grids.y);
}
void GamePlayEngine::onRIghtHandMenu()
{

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