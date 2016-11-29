#pragma once
#include "GameLog.h"

class DiceController : public GameLog
{
private:
	DiceController();
	static DiceController* _diceController;
public:
	static DiceController* getInstance();
	~DiceController();


};