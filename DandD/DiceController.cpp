#include "DiceController.h"

DiceController* DiceController::_diceController = nullptr;

DiceController::DiceController()
{
	_path = SingletonFilePathAndFolderManager::getInstance()->_path_to_diceController;
	SingletonInputOutputManager::getInstance()->clearFile(_path);
}

DiceController* DiceController::getInstance()
{
	if (_diceController == nullptr)
		_diceController = new DiceController();
	return _diceController;
}

DiceController::~DiceController()
{
	delete _diceController;
	_diceController = nullptr;
}

