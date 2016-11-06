/**
*@file CharacterMapView.cpp
*@brief View of the Character class in the MVC pattern. Implements Observer.
*
*<p>A CharacterMapView is a concrete implementation of the Observer class in the MVC pattern. A
*CharacterMapView is able to display a Character and the map that it is placed on.
*/
#pragma once
#include "Character.h"
#include "CharacterMapView.h"
using namespace std;

CharacterMapView::CharacterMapView(Character * myChar, std::vector<std::string> *theMap)
{
	_subject = myChar;
	_map = theMap;
}

CharacterMapView::~CharacterMapView()
{
	_subject->detach(this);
	delete _subject;
	delete _map;
}

/**
*Receives notification from the subject that an update has occured. Will perform the necessary tasks based on the flag it is given.
*@param flag integer representing what has occured
*/
void CharacterMapView::update(int flag)
{
	switch (flag) {
	// If the Character's position has been updated, then the map with the updated position will be displayed
	case CharPos:
		display();
		break;
	}
}

/**
* Prints out the Map with the Character's current position displayed on it
*/
void CharacterMapView::display() {
	system("CLS");
	int xpos = _subject->getx();
	int ypos = _subject->gety();
	for (int i = 0; i < xpos; ++i) {
		std::cout << _map->at(i) << endl;
	}
	for (int i = 0; i < _map->at(xpos).size(); ++i) {
		if (i == ypos)
			cout << 'P';
		else
			cout << _map->at(xpos).at(i);
	}
	cout << endl;
	for (int i = xpos + 1; i < _map->size(); ++i)
		std::cout << _map->at(i) << endl;
}

/**
*Validates a move in relation to the map the Character is on. Will not allow the Character to enter a square with 'o'.
*Will also ensure that the Character does not move out of bounds.
*/
bool CharacterMapView::validatePlayerMove(int x, int y)
{
	if (x < 0 || x >= _map->size())
		return false;
	if (y < 0 || y >= _map->at(0).size())
		return false;
	char posInQuestion = _map->at(x).at(y);
	if (posInQuestion == 'o')
		return false;
	else return true;
}
