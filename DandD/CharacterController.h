#pragma once
#include "GameLog.h"

class CharacterController : public GameLog
{
private:
	CharacterController();
	static CharacterController* _characterController;
public:
	static CharacterController* getInstance();
	~CharacterController();


};