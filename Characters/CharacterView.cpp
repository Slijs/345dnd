/**
*@file CharacterView.cpp
*@brief Implementation of the CharacterView class
*<p> This file contains the definition of all CharacterView methods. A CharacterView is used to display a Character model to the user.
*    A CharacterView is notified any time its subject (a Character) has had one of its stats modified/updated. It then displays the
*	 Character's information.
*<p> The only external library that was used was iostream to allow the CharacterView to print to the console.
*/

#include "stdafx.h"
#include "CharacterView.h"
#include <iostream>
/**
* Default constructor for the CharacterView class. Does nothing as no
* Character was provided to it.
*/
CharacterView::CharacterView(){}

/**
* Paramaterized Constructor. Takes a Character to become the View's subject,
* and attaches itself to said character.
*@param myChar Character pointer, this is the Character that becomes the View's
			   Subject, and the View becomes attached to this Character
*/
CharacterView::CharacterView(Character * myChar)
{
	_subject = myChar;
	_subject->attach(this);
}
/**
* CharacterView Destructor. Detaches the View from the Subject so that the Subject will not reference
* deallocated memory. Does not delete the Subject because it may in use by another View.
*/
CharacterView::~CharacterView()
{
	_subject->detach(this);
}

/**
* Displays the Character's details to the console upon update. If the Character is dead, then it indicates this and does not display
* anything else.
*/
void CharacterView::update()
{
	cout << "Something has changed for " << _subject->getName() << "! Here are their new details!" << endl;
	if (_subject->getCurrentHP() == 0) {
		cout << "Your character is dead." << endl;
	} else {
		display();
		displayInventory();
	}
}

/**
* Method for printing to the console.
*/
void CharacterView::display()
{
		cout << "Name: " << _subject->getName() << endl; // Display Subject's name
		cout << "Race: " << _subject->getRace() << endl; // Display Subject's race
		cout << "Class: " << _subject->getClass() << endl; // Display Subject's class
		cout << endl;
		cout << "Level: " << _subject->getLevel() << endl;
		cout << "EXP: " << _subject->getExp() << endl;
		cout << "Hit Points: " << _subject->getCurrentHP() << "/" << _subject->getMaxHP() << endl;
		cout << endl;
		cout << "Abilities" << endl;
		cout << "    [Str]: " << _subject->getStrength() << endl;
		cout << "    [Dex]: " << _subject->getDexterity() << endl;
		cout << "    [Con]: " << _subject->getConstitution() << endl;
		cout << "    [Int]: " << _subject->getIntelligence() << endl;
		cout << "    [Wis]: " << _subject->getWisdom() << endl;
		cout << "    [Cha]: " << _subject->getCharisma() << endl;
		cout << endl;
		cout << "Armour Class: " << _subject->getArmourClass() << endl;
		cout << "Attack Bonus: " << _subject->getAttackBonus() << endl;
		cout << "Damage Bonus: " << _subject->getDamageBonus() << endl;
		cout << "Proficiency Bonus: " << _subject->getProficiencyBonus() << endl;
		cout << endl;
}

/**
* Prints Subject's inventory to the console
*/
void CharacterView::displayInventory() {
	cout << "Inventory" << endl;
	if (_subject->isArmourEquipped())
		cout << "     Armour" << endl;
	if (_subject->isShieldEquipped())
		cout << "     Shield" << endl;
	if (_subject->areBootsEquipped())
		cout << "     Boots" << endl;
	if (_subject->isRingEquipped())
		cout << "     Ring" << endl;
	if (_subject->isWeaponEquipped())
		cout << "     Weapon" << endl;
	if (_subject->isHelmetEquipped())
		cout << "     Helmet" << endl;
	cout << endl;
}
