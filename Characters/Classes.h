/**
*@file Classes.h
*@brief Definition of the 'Classes' class and its subclasses.
*<p> This file outlines the 'Classes' class, which governs the attributes specific to the Character Classes.
*@author Jeremiah Witt
*/

#pragma once
#ifndef CLASSES_H
#define CLASSES_H
#include <string>
using namespace std;


/**
* This enumerated type is used to easily refer to specific Classes types from within the program.
*/
enum ClassType {Cleric, Fighter, Rogue, Wizard};

/**
*@class Classes 
*@brief Allows a Character class to influence their HP
*/
class Classes {
protected:

	int baseHP;		// Base HP associated with the class
	string hitDie;	// String representing the hit die associated with the class (ie 1dX)
	ClassType whichClass;

public:

	Classes(ClassType theirType);
	~Classes() {};
	/* PUBLIC ACCESSORS */

	int getBaseHP();
	string getHitDie();
	string getWhichClass();

};

#endif
