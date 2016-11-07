#pragma once
#include "Subject.h"
#include "Characters.h"
#include "namespaces.h"
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

/*!
	Dummy class for maps that has a single hard-coded map
	and allows a player to move through it until exit is reached
*/


class Maps : public Subject
{
private:
	bool cleared;
	std::vector<string> map;
	int X, Y;
	Characters* player;

	void moveUp();
	void moveLeft();
	void moveRight();
	void moveDown();

	void replacePwithDot();

public:
	Maps(Characters*);
	~Maps();

	bool getCleared(){ return cleared; };

	void detectKey(int);





	void displayMap();
	
	void currentState();

};