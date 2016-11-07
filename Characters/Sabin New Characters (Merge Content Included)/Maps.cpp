#include "Maps.h"
/*!Parameterized Constructor that takes a character pointer
Hardcoded map for testing purposes, using vector of string pointers.
Character now has a vector for his position which are used for 
X and Y coordinates on map*/
Maps::Maps(Characters* c)
{
	map.push_back(".e...");
	map.push_back("o...o");
	map.push_back("ooo..");
	map.push_back(".p...");
	map.push_back(".....");
	map.shrink_to_fit();
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
		if (validatePlayerMove(X, Y - 1))
			moveUp();
		break;
	case KEY_DOWN:
		if (validatePlayerMove(X, Y + 1))
			moveDown();
		break;
	case KEY_UP_LEFT:
		if (validatePlayerMove(X - 1, Y - 1))
			moveUpLeft();
		break;
	case KEY_DOWN_LEFT:
		if (validatePlayerMove(X - 1, Y + 1))
			moveDownLeft();
		break;
	case KEY_LEFT:
		if (validatePlayerMove(X-1, Y)) 
			moveLeft();
		break;
	case KEY_UP_RIGHT:
		if (validatePlayerMove(X + 1, Y - 1))
			moveUpRight();
		break;
	case KEY_DOWN_RIGHT:
		if (validatePlayerMove(X + 1, Y + 1))
			moveUpRight();
		break;
	case KEY_RIGHT:
		if (validatePlayerMove(X + 1, Y))

			moveRight();
		break;
	default:
		cout << input << endl;
		break;
	}

	currentState();

}

//!Function that moves postion of character up if there is no obstruction
void Maps::moveUp()
{
		player->setPosition(Y - 1, X);
		replacePwithDot();

		char* next = &map[Y - 1].at(X);
		if (*next == 'e')
			cleared = true;
	
		*next = 'p';
		
		Y--;
}

void Maps::moveUpLeft()
{
	player->setPosition(Y - 1, X-1);
	replacePwithDot();

	char* next = &map[Y - 1].at(X-1);
	if (*next == 'e')
		cleared = true;

	*next = 'p';
	X--;
	Y--;
}

void Maps::moveDownLeft()
{
	player->setPosition(Y + 1, X - 1);
	replacePwithDot();

	char* next = &map[Y + 1].at(X - 1);
	if (*next == 'e')
		cleared = true;

	*next = 'p';
	X--;
	Y++;

}

//!Function that moves postion of character left if there is no obstruction
void Maps::moveLeft()
{
	player->setPosition(Y, X - 1);
	replacePwithDot();

	char* next = &map[Y].at(X - 1);
	if (*next == 'e')
		cleared = true;

	*next = 'p';

	X--;
	
}

void Maps::moveUpRight()
{
	player->setPosition(Y-1, X + 1);
	replacePwithDot();

	char* next = &map[Y-1].at(X + 1);
	if (*next == 'e')
		cleared = true;


	*next = 'p';

	X++;
	Y--;

}

void Maps::moveDownRight()
{
	player->setPosition(Y + 1, X + 1);
	replacePwithDot();

	char* next = &map[Y + 1].at(X + 1);
	if (*next == 'e')
		cleared = true;


	*next = 'p';

	X++;
	Y++;
}

//!Function that moves postion of character right if there is no obstruction
void Maps::moveRight()
{
	player->setPosition(Y, X + 1);
	replacePwithDot();

	char* next = &map[Y].at(X + 1);
	if (*next == 'e')
		cleared = true;

	*next = 'p';

	X++;

}

//!Function that moves postion of character down if there is no obstruction
void Maps::moveDown()
{
	player->setPosition(Y + 1, X);
	replacePwithDot();

	char* next = &map[Y + 1].at(X);
	if (*next == 'e')
		cleared = true;
	*next = 'p';

	Y++;
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

bool Maps::validatePlayerMove(int x, int y)
{
	if (x < 0 || x >= map[Y].length())
		return false;
	if (y < 0 || y >= map.size())
		return false;
	char posInQuestion = map[y].at(x);
	if (posInQuestion == 'o')
		return false;
	else return true;
}

//!Informs subject of change in map to trigger redisplay in Map Observer.
void Maps::currentState()
{
	Notify();
}