#include "GameController.h"

GameController* GameController::_gameController = nullptr;

//!Private default constructor that sets the path the game controller log
GameController::GameController()
{
	_path = SingletonFilePathAndFolderManager::getInstance()->_path_to_gameController;
	SingletonInputOutputManager::getInstance()->clearFile(_path);
	_toggle = true;
}

//!Function that returns a singleton instance of game controller (creates a new one if not already created)
GameController* GameController::getInstance()
{
	if (_gameController == nullptr)
		_gameController = new GameController();
	return _gameController;
}

//!Destructor
GameController::~GameController()
{
	delete _gameController;
	_gameController = nullptr;
}