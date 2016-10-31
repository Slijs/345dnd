#include "Entity.h"

//default constructor
Entity::Entity()
{
}

//parameterized constructor
Entity::Entity(Race entityRace, Class entityClass, int entityLevel)
{
	this->charClass = entityClass;
	this->charRace = entityRace;
	this->charLevel = entityLevel;
}

Entity::~Entity()
{}

//int Entity::GetAbility(AbilityType type) {

//return Ability[type]; // Base case, none of the cases matched, so return the core value.
//}

