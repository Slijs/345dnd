/**
*@file prebuiltlevel.h
*@brief Allows use of pre built levels
*/
#pragma once
#include "levels.h"
#include "Fighter.h"
#include "containerOnMap.h"
#include "ContainerGenerator.h"
#include "enemyonmap.h"
#include "MonsterFactory.h"
#include "Subject.h"
/*!
*@class PreBuiltLevel
* Inherits from levels, not much specific functionalities added except
* for just loading a text file from a path and creating a graphical
* level out of it on the LevelWindow instance that it would contain
*/
class PreBuiltLevel : public Level, public Subject
{
protected:
	std::vector<SDL_Rect*> _levelComponentRects;
	SDL_Rect _inventoryPaneDest;
	SDL_Rect _movePlayerDest;
	SDL_Rect _exitPlay;
	SDL_Rect _interact;
	SDL_Rect _attack;
	SDL_Rect _savePlayer;
	Fighter* _player;
	std::vector<ContainerOnMap*> _containersOnMap;
	std::vector<EnemiesOnMap*> _enemisOnMap;

public:
	PreBuiltLevel();
	PreBuiltLevel(std::string path, Fighter* player);
	void loadUserCreatedLevel(std::string name);
	SDL_Rect _dest1ForObserver;
	SDL_Rect _dest2ForObserver;
	Environment* _environmentForObserver;
	std::vector<SDL_Rect*> getLevelComponentRects();
	void setLevelOnTargetWindow();
	void createLevelForTargetWindow();
	std::string getEnvironmentComponentsPath() const;
	std::string getDirectoryPathForLevelTextFile() const;
	std::string getPlayerPath() const;
	std::string getEnemyPath() const;
	std::vector<std::string> getBuiltLevelFile() const;
	Fighter* getPlayer();
	void setupContainersOnMap();
	void setupEnemiesOnMap();
	std::vector<ContainerOnMap*> getContainersOnMap();
	std::vector<EnemiesOnMap*> getEnemiesOnMap();
	std::vector<SDL_Rect> getAllButtonDestinations();
	~PreBuiltLevel();
};