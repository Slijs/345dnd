#include "Maps.h"
/*!Parameterized Constructor that takes a character pointer
Hardcoded map for testing purposes, using vector of string pointers.
Character now has a vector for his position which are used for 
X and Y coordinates on map*/
Maps::Maps(Characters* c)
{
	map.push_back("oeooo");
	map.push_back("o...o");
	map.push_back("ooo.o");
	map.push_back("op..o");
	map.push_back("ooooo");
	player = c;
	c->setPosition(3, 1);
	vector<int> pos = player->getPosition();
	Y = pos[0];
	X = pos[1];
	cleared = false;
}

//!Destructor
Maps::~Maps()
{
	if (player != nullptr)
		delete player;
	player = nullptr;
	map.clear();
}

//!Function for key detection of Up, down, left, right keys
void Maps::detectKey(int input)
{
	switch (input)
	{
	case KEY_UP:
		moveUp();
		break;
	case KEY_DOWN:
		moveDown();
		break;
	case KEY_LEFT:
		moveLeft();
		break;
	case KEY_RIGHT:
		moveRight();
		break;
	}
}

//!Function that moves postion of character up if there is no obstruction
void Maps::moveUp()
{
	char above = map[Y - 1].at(X);
	if (above == 'o')
		return;
	else
	{
		player->setPosition(Y - 1, X);
		replacePwithDot();

		char* next = &map[Y - 1].at(X);
		if (*next == 'e')
			cleared = true;
	
		*next = 'p';

		Y--;
		currentState();
	}
}

//!Function that moves postion of character left if there is no obstruction
void Maps::moveLeft()
{
	char left = map[Y].at(X-1);
	if (left == 'o')
		return;
	else
	{
		player->setPosition(Y, X - 1);
		replacePwithDot();

		char* next = &map[Y].at(X - 1);
		if (*next == 'e')
			cleared = true;

		*next = 'p';

		X--;
		currentState();
	}
}

//!Function that moves postion of character right if there is no obstruction
void Maps::moveRight()
{
	char right = map[Y].at(X + 1);
	if (right == 'o')
		return;
	else
	{
		player->setPosition(Y, X + 1);
		replacePwithDot();

		char* next = &map[Y].at(X + 1);
		if (*next == 'e')
			cleared = true;

		*next = 'p';

		X++;
		currentState();
	}

}

//!Function that moves postion of character down if there is no obstruction
void Maps::moveDown()
{
	char below = map[Y + 1].at(X);

	if (below == 'o')
		return;
	else
	{
		player->setPosition(Y + 1, X);
		replacePwithDot();

		char* next = &map[Y + 1].at(X);
		if (*next == 'e')
			cleared = true;
		*next = 'p';

		Y++;
		currentState();
	}
}

//!Function that changes previous positon to freepath
void Maps::replacePwithDot()
{
	char* prev = &map[Y].at(X);
	*prev = '.';
}

//!Displays the map of strings on console
void Maps::displayMap()
{
	string row;
	for (int i = 0; i<map.size(); i++)
	{
		row = map[i];
		cout << row.c_str() << endl;
	}
		
}

//!Informs subject of change in map to trigger redisplay in Map Observer.
void Maps::currentState()
{
	Notify();
}