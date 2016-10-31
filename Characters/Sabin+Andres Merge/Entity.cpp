#include "Entity.h"

//default constructor
Entity::Entity()
{
}

//parameterized constructor
Entity::Entity(Race entityRace, int entityLevel)
{
	this->charRace = entityRace;
	this->charLevel = entityLevel;
}

Entity::~Entity()
{}