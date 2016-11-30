#include "GameLog.h"	


void GameLog::log(string input)
{
	if (_toggle == true)
		SingletonInputOutputManager::getInstance()->appendToFile(_path, input);
}