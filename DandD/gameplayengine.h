#if !defined (GAMEPLAY_ENGINE_H)
#define GAMEPLAY_ENGINE_H
#include "prebuiltlevel.h"
#include "containerOnMap.h"
#include "enemyonmap.h"
#include "CharSaveManager.h"
#include <vector>
class GamePlayEngine
{
private:
	PreBuiltLevel* _level;
	SDL_Event* _event;
	bool _moveSelect;
	bool _interactSelect;
	bool _attackSelect;
	bool _moveValidityTracker;
	bool _firstTimeGridTarget;
	bool _buttonSelect;
	bool _mapExit;
	int _currentButtonIndex;
	int _exitStringIndex;
	int _exitCharacterIndex;
	SDL_Rect _currentGrid;
	SDL_Rect _lastGrid;
	int _gridIndex;
	int _lastButtonIndex;
	std::vector<SDL_Rect> _buttons;
	std::vector<ContainerOnMap*> _containers;
	std::vector<EnemiesOnMap*> _enemies;

public:
	GamePlayEngine();
	void attachLevel(PreBuiltLevel* level, SDL_Event* event_);
	void detachLevel();
	int runEngine();
	void onGameplayGrids();
	int onRIghtHandMenu();
	void movePlayer();
	void interactEnvironment();
	void attackEnemy();
	SDL_Rect checkMousePosition(std::vector<SDL_Rect> components, int* targetIndex);
};

#endif