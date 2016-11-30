#include "GameLog.h"	


void GameLog::log(string input)
{
		SingletonInputOutputManager::getInstance()->appendToFile(_unifiedPath, input);
}