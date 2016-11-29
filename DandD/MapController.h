#pragma once
#include "GameLog.h"

class MapController : public GameLog
{
private:
	MapController();
	static MapController* _mapController;
public:
	static MapController* getInstance();
	~MapController();


};