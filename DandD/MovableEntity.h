#ifndef MovableEntity_H
#define MovableEntity_H

#include <afx.h>

//! Keeps the (x, y) coordinates
struct Position {
	Position() : x(0), y(0) {}
	Position(int const a, int const b) : x(a), y(b) {}
	~Position() {}
	// coordinates
	int x;
	int y;
};
/**
 * @brief Allows classes to inherit a position and its associated 
 */
class MovableEntity : public CObject
{
protected:
	Position position;
	DECLARE_SERIAL(MovableEntity);
public:
	MovableEntity();
	MovableEntity(int x, int y);
	~MovableEntity();
	Position getPosition();
	int getXCoordinate() { return position.x; }
	int getYCoordinate() { return position.y; }
	void setPosition(Position position);
	void setPosition(int xCoordinate, int yCoordinate);
	virtual void Serialize(CArchive &ar);
};

#endif // !MovableEntity_H
