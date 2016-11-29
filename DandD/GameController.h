#pragma once
#include "GameLog.h"

class GameController : public GameLog
{
private:
	GameController();
	static GameController* _gameController;
public:
	static GameController* getInstance();
	~GameController();


};