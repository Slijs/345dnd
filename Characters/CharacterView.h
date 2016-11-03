/**
*@file CharacterView.h
*@brief View of the Character class in the MVC pattern. Implements Observer.
*
*<p>A CharacterView is the concrete implementation of the Observer class in the MVC pattern. A
*	CharacterView is able to display the Character which is its subject. In addition, it is notified
*	when any changes are made to its subject, and at that point it displays the new changes.
*/
#pragma once
#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H
#include "Character.h"
#include "Observer.h"

/**
*@class CharacterView 
*@brief Allows for display of any Character updates using MVC model
*/
class CharacterView : public Observer {
public:
	CharacterView();
	CharacterView(Character* myChar);
	~CharacterView();
	void update();
	void display();
	void displayInventory();
private:
	Character *_subject;
};

#endif