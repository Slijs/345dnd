#pragma once
#include "stdafx.h"
#include <vector>
#include "Character.h"
#include "CharacterMapView.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	vector<string> *theMap = new vector<string>();
	theMap->push_back("oooooooooooeoooooooo");
	theMap->push_back("o..................o");
	theMap->push_back("o..................o");
	theMap->push_back("o..................o");
	theMap->push_back("o..................o");
	theMap->push_back("oooooooooooooooooooo");
	Character *myChar = new Character();
	myChar->setx(4);
	myChar->sety(5);
	CharacterMapView *myView = new CharacterMapView(myChar, theMap);
	myChar->attach(myView);
	myView->display();

	while (true) {
		char input = 'x';
		cin >> input;
		switch (input) {
		case 'w': // Move Up
			if (myView->validatePlayerMove((myChar->getx() - 1), myChar->gety()))
				myChar->setx(myChar->getx() - 1);
			break;
		case 'a': // Move left
			if (myView->validatePlayerMove(myChar->getx(), (myChar->gety()-1)))
				myChar->sety(myChar->gety() - 1);
			break;
		case 's': // Move down
			if (myView->validatePlayerMove((myChar->getx() + 1), myChar->gety()))
				myChar->setx(myChar->getx() + 1);
			break;
		case 'd': // Move right
			if (myView->validatePlayerMove(myChar->getx(), (myChar->gety() + 1)))
				myChar->sety(myChar->gety() + 1);
			break;
		default:
			break;
		}
	}

	return 0;
}

