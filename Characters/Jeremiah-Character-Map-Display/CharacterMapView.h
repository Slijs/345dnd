/**
*@file CharacterMapView.h
*@brief Definition of the CharacterMapView class, allowing display of a Character on a map
*/
#ifndef CHARACTERMAPVIEW_H
#define CHARACTERMAPVIEW_H
#include "Character.h"
#include "Observer.h"
#include <vector>
#include <string>
#include <iostream>

/**
*@class CharacterMapView
*@brief Allows for display of a Character on the map.
*/
class CharacterMapView : public Observer {
public:
	
	CharacterMapView() {};
	CharacterMapView(Character* myChar, std::vector<std::string>* theMap);
	~CharacterMapView();
	void update(int flag);
	void display();
	bool validatePlayerMove(int x, int y);
protected:
	Character *_subject;
	std::vector<std::string> *_map;
};

#endif

