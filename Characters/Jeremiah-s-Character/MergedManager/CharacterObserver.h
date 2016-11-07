/**
*@file CharacterObserver.h
*@brief Declaration of the CharacterObserver class
*
#pragma once
#include "Observer.h"
#include "Characters.h"

/*!
	Class that inherits from the Observer class and is used to observe 
	the changes in stats of objects of class Characters or subclasses of Characters.
	
	Update() calls display which will display the character's based 
	on his current status. If the character is in battle, dead or leveling up,
	a corresponding display function will be called.  
*/

class CharacterObserver : public Observer
{
private:
	Characters* _sub;
public:
	CharacterObserver(Characters* s);
	~CharacterObserver();

	void Update();
	void display();
};
