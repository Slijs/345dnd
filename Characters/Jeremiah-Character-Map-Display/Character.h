/**
*@file Character.h
*@brief Character semi-implementation for testing with maps, allowing Character to hold an x and y position
*/
#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Subject.h"

class Character : public Subject {
protected:
	int _x;
	int _y;
public:
	Character() : _x(0), _y(0) {};
	~Character() {};
	int getx() { return _x; };
	int gety() { return _y; };

	void setx(int x) { _x = x; notify(CharPos); };
	void sety(int y) { _y = y; notify(CharPos);  };
};

#endif