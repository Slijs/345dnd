#if !defined (ENEMY_ON_MAP_H)
#define ENEMY_ON_MAP_H
#include "Monster.h"
struct EnemiesOnMap
{
	Monster* monster;
	int stringIndex;
	int charIndex;
};

#endif