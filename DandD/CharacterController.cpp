#include "CharacterController.h"

CharacterController* CharacterController::_characterController = nullptr;

//!Private default constructor that sets the path the character controller log
CharacterController::CharacterController()
{
	_path = SingletonFilePathAndFolderManager::getInstance()->_path_to_characterController;
	SingletonInputOutputManager::getInstance()->clearFile(_path);
}

//!Function that returns a singleton instance of character controller (creates a new one if not already created)
CharacterController* CharacterController::getInstance()
{
	if (_characterController == nullptr)
		_characterController = new CharacterController();
	return _characterController;
}

//!Destructor
CharacterController::~CharacterController()
{
	delete _characterController;
	_characterController = nullptr;
}