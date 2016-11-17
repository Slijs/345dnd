#include "MovableEntity.h"

IMPLEMENT_SERIAL(MovableEntity, CObject, 1);

//! Default constructor, sets to position (0, 0)
MovableEntity::MovableEntity() : position(0, 0)
{
}

/**
 * @brief Parameterized constructor, taking x and y values
 * @param x The x coordinate, must be positive. No checks will be performed here to ensure within map.
 * @param x The y coordinate, must be positive. No checks will be performed here to ensure within map.
 */
MovableEntity::MovableEntity(int x, int y)
{
	setPosition(x, y);
}


MovableEntity::~MovableEntity()
{
}

//! Get the position
Position MovableEntity::getPosition()
{
	return position;
}

/**
 * @brief Set the position equal to another position. Doesn't do any checking for validity.
 * @param newPosition A position
 */
void MovableEntity::setPosition(Position newPosition)
{
	position.x = newPosition.x;
	position.y = newPosition.y;
}

/**
 * @brief Set the position equal to another position.
 * @param xCoordinate The x coordinate desired, must be >= 0.
 * @param yCoordinate The y coordinate desired, must be >= 0.
 */
void MovableEntity::setPosition(int xCoordinate, int yCoordinate)
{
	if (xCoordinate >= 0 && yCoordinate >= 0) {
		position.x = xCoordinate;
		position.y = yCoordinate;
	}
}

void MovableEntity::Serialize(CArchive & ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << MovableEntity::position.x;
		ar << MovableEntity::position.y;
	}
	else {
		ar >> MovableEntity::position.x;
		ar >> MovableEntity::position.y;
	}
}
