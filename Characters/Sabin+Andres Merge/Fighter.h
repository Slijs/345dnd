#pragma once
#include "Characters.h"

class Fighter : public Characters
{
private:
	const int HIT_DIE = 10; //d10
	int hitPoints;
	Race race;
	string name;


public:
	Fighter(int,Race, string);
	~Fighter();


	void initHitPoints();
	void displayStats();


	//TEST
	bool validateHitPoints();
};