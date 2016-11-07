/**
*@file CharacterViewDriver.cpp
*@brief Driver to demonstrate functionality of the CharacterView
*<p> This file contains the main method. When run, it allows the user to create a new Character with the details they desire.
*	 It then prints the Character to the screen, and allows the user to change different details about a Character that would
*	 be modifiable in-game. Once the Character has been updated, it gets printed to the screen.
*/
#include "stdafx.h"
#include "Characters.h"
#include "CharacterView.h"
#include "CharacterBuilder.h"
#include "CharSaveManager.h"
#include <iostream>
#include <string>
using namespace std;

static void displayMenu(); // Will be used to display the menu
static void displayMainMenu();
static Character* createNewCharacter();
static void damageCharacter(Character* theChar); // Will be used to inflict damage to the Character
static void addExp(Character* theChar);	// Will be used to add experience points to the Character
static void modifyInventory(Character* theChar, CharacterView* theView); // Will be used to modify the Character's inventory
static void equipItem(Character *theChar, CharacterView* theView); // Will be used to equip an item to a Character
static void removeItem(Character *theChar, CharacterView* theView); // Will be used to remove an item from a Character
static void saveChar(Character *theChar);
static void loadChar(Character *theChar, CharacterView* theView);
static void removeCharacter();

int main() {
	char conf = 'X';	// Used to confirm choices
	Character *toLoad = NULL;
	Character *myChar = NULL;
	CharacterView *myView = NULL;

	bool cont = false;
	do {
		displayMainMenu();
		cin >> conf;
		switch (conf) {
		case '1': // User wants to create a new Character
			myChar = createNewCharacter();
			myView = new CharacterView(myChar);

			// The Character's details will be outputted
			cout << "The following are the details of your new character ... " << endl << endl;
			myView->display();
			cont = true;
			break;
		case '2': // User wants to load a character
			myChar = CharacterSaveManager::loadCharacter();
			if (myChar == NULL) {
				return 0;
			}
			myView = new CharacterView(myChar);
			myChar->attach(myView);
			myView->display();
			cont = true;
			break;
		case '3': // User wants to remove a Character
			removeCharacter();
			break;
		case 'e':
		case 'E':
			return 0;
			break;
		}
	} while (!cont);

	// Program loop, allowing changes to be made to the Character.
	do {
		displayMenu();	// Displays option menu
		cin >> conf;
		switch (conf) {
		case '1': // User wants to add experience points
			addExp(myChar);
			break;
		case '2': // User wants to inflict damage to the Character
			damageCharacter(myChar);
			break;
		case '3':
			saveChar(myChar);
			break;
		case '4':
			myChar = CharacterSaveManager::loadCharacter();
			delete myView;
			myView = new CharacterView(myChar);
			myChar->attach(myView);
			myView->display();
			myView->displayInventory();
			break;
		case '5':
			removeCharacter();
			break;
		case 'e':
		case 'E':
			break;
		}
		if (myChar->isDead()) // If Character is dead, the loop gets broken so that the program can quit
			break;
	} while (!(conf == 'e' || conf == 'E'));

	delete myChar;
	return 0;
}

/**
* This method prints the menu to the screen.
*/
static void displayMenu() {
	cout << "Please enter what you would like to do: " << endl;
	cout << "   [1] - Add experience points." << endl;
	cout << "   [2] - Do damage to your character." << endl;
	cout << "   [3] - Save Character." << endl;
	cout << "   [4] - Load Character." << endl;
	cout << "   [5] - Remove Character." << endl;
	cout << "Enter 'E' to exit." << endl;
	cout << "Enter your option here: ";
}

/**
* This method allows experience points to be added to the Character.
*@param theChar Character Pointer to the Character to be modified
*/
static void addExp(Character* theChar) {
	string input = "";
	int toAdd = -1;
	// Get input from user
	do {
		cout << "How many experience points would you like to add?" << endl;
		cout << "Please enter a number greater than 0." << endl;
		cin >> input;
		// Ensures that input is valid
		try {
			toAdd = stoi(input);
		}
		catch (invalid_argument) {
			cout << "You entered an invalid value! Please try again." << endl;
			continue;
		}
	} while (toAdd < 0);
	theChar->gainExperience(toAdd);
}

/**
* Inflicts damage on the Character.
*@param theChar Character Pointer to the Character to be modified
*/
static void damageCharacter(Character* theChar) {
	string input = "";
	int toInflict = -1;
	// Requests from the user a positive value of damage to inflict. Ensures that it is provided validly.
	do {
		cout << "How much damage would you like to inflict?" << endl;
		cout << "Please enter a number between 0 and " << theChar->getCurrentHP() << "." << endl;
		cout << "(NOTE: Higher damage is possible, but will result in immediate death!)" << endl;
		cin >> input;
		try {
			toInflict = stoi(input);
		}
		catch (invalid_argument) {
			cout << "You entered an invalid value! Please try again." << endl;
			continue;
		}
	} while (toInflict < 0);
	theChar->hit(toInflict);
}

/**
* Confirms whether or not the User would like to equip or remove an item.
*@param theChar Character pointer to Character to be modified
*@param theView CharacterView of theChar (needed to display inventory to let user know their options
*/
static void modifyInventory(Character *theChar, CharacterView* theView) {
	char input = 'x';
	cout << "What would you like to do?" << endl;
	cout << "     [1] - Equip an item." << endl;
	cout << "     [2] - Remove an item." << endl;
	cin >> input;
	switch (input) {
	case '1':
		equipItem(theChar, theView);
		break;
	case '2':
		removeItem(theChar, theView);
		break;
	default:
		cout << "You entered an invalid option! Returning to main menu." << endl;
	}
}

/**
* Allows the user to equip an item to theChar. Displays the user's initial inventory first.
*@param theChar Character Pointer to the Character to be modified
*@param theView Character View of theChar
*/
static void equipItem(Character *theChar, CharacterView* theView) {

	cout << theChar->getName() << " has the following items equipped:" << endl;
	theView->displayInventory();
	cout << "Please enter the type of item you would like to equip, as per the names below." << endl;
	cout << "[Armour][Shield][Weapon][Boots][Ring][Helmet]" << endl;
	cout << "Enter your choice here: ";
	string input = "";
	cin >> input;
	if (input.compare("armour") == 0 || input.compare("Armour") == 0)
		theChar->equipArmour(5);
	else if (input.compare("shield") == 0 || input.compare("Shield") == 0)
		theChar->equipShield(5);
	else if (input.compare("weapon") == 0 || input.compare("Weapon") == 0)
		theChar->equipWeapon(10);
	else if (input.compare("boots") == 0 || input.compare("Boots") == 0)
		theChar->equipBoots();
	else if (input.compare("ring") == 0 || input.compare("Ring") == 0)
		theChar->equipRing();
	else if (input.compare("helmet") == 0 || input.compare("Helmet") == 0)
		theChar->equipHelmet();
	else {
		cout << "I'm sorry, I didn't understand your request. Please try again." << endl;
		equipItem(theChar, theView);
	}
}

/**
* Allows the user to remove an item from the Character
*@param theChar Character Pointer to the Character to be modified
*@param theView View of the Character
*/
static void removeItem(Character *theChar, CharacterView* theView) {

	cout << theChar->getName() << " has the following items equipped:" << endl;
	theView->displayInventory();
	cout << "Please enter the type of item you would like to remove, as per the names below." << endl;
	cout << "[Armour][Shield][Weapon][Boots][Ring][Helmet]" << endl;
	cout << "Enter your choice here: ";
	string input = "";
	cin >> input;
	if (input.compare("armour") == 0 || input.compare("Armour") == 0)
		theChar->removeArmour();
	else if (input.compare("shield") == 0 || input.compare("Shield") == 0)
		theChar->removeShield();
	else if (input.compare("weapon") == 0 || input.compare("Weapon") == 0)
		theChar->removeWeapon();
	else if (input.compare("boots") == 0 || input.compare("Boots") == 0)
		theChar->removeBoots();
	else if (input.compare("ring") == 0 || input.compare("Ring") == 0)
		theChar->removeRing();
	else if (input.compare("helmet") == 0 || input.compare("Helmet") == 0)
		theChar->removeHelmet();
	else {
		cout << "I'm sorry, I didn't understand your request. Please try again." << endl;
		equipItem(theChar, theView);
	}
}

static void saveChar(Character *theChar) {
	CharacterSaveManager::saveCharacter(theChar);
}

static void loadChar(Character *theChar, CharacterView *theView) {
	Character *loadedChar = CharacterSaveManager::loadCharacter();
	if (loadedChar == NULL)
		return;
	else
		theChar = loadedChar;
	return;
}

static void displayMainMenu() {
	cout << "Please enter what you would like to do: " << endl;
	cout << "   [1] - Create a character" << endl;
	cout << "   [2] - Load a character" << endl;
	cout << "   [3] - Remove a character" << endl;
	cout << "Enter 'E' to exit." << endl;
	cout << "Enter your option here: ";
}

static Character* createNewCharacter() {
	string name = "";	// Will be used to get Character's name
	string input = "";	// Will store input
	int selectedClass = 0; // Will be used to get Character's class
	int selectedRace = 0; // Will be used to get Character's race
	int selectedLevel = 0;	// Will be used to get Character's level
	char conf = 'X';	// Used to confirm choices
	cout << "***** CHARACTER CREATER *****" << endl;

	// Get name of Character
	do {
		cout << "Please enter the name you would like to have for your character: ";
		cin >> name;
		cout << "You entered " << name << ". Are you happy with this? (Y/N) ";
		cin >> conf;
	} while (!(conf == 'Y' || conf == 'y'));
	conf = 'X';

	// Get Class of Character
	do {
		cout << "Please select the Class that you want for your character: " << endl;
		cout << "[0 = Cleric][1 = Fighter][2 = Rogue][3 = Wizard]" << endl;

		// Will get input and will confirm that it is a number
		cin >> input;
		try {
			selectedClass = stoi(input);
		}
		catch (invalid_argument) {
			cout << "You entered an invalid argument. Please try again." << endl;
			continue;
		}

		// This switch will output the selection the user made and confirm that they are satisfied with it
		switch (selectedClass) {
		case 0:
			cout << "You selected Cleric. Are you happy with this? (Y/N) ";
			break;
		case 1:
			cout << "You selected Fighter. Are you happy with this? (Y/N) ";
			break;
		case 2:
			cout << "You selected Rogue. Are you happy with this? (Y/N) ";
			break;
		case 3:
			cout << "You selected Wizard. Are you happy with this? (Y/N) ";
			break;
		default:
			cout << "You selected an invalid option. Please try again." << endl;
			continue;
		}
		cin >> conf;
	} while (!(conf == 'Y' || conf == 'y'));
	conf = 'X';

	// Now the program will get the Character's Race
	do {
		cout << "Please select the Class that you want for your character: " << endl;
		cout << "[0 = Dwarf][1 = Elf][2 = Halfling][3 = Human]" << endl;

		// Will get the integer representing the race the user wants, and will ensure that it is correct
		cin >> input;
		try {
			selectedRace = stoi(input);
		}
		catch (invalid_argument) {
			cout << "You entered an invalid argument. Please try again." << endl;
			continue;
		}

		// Will confirm the race for the user
		switch (selectedRace) {
		case 0:
			cout << "You selected Dwarf. Are you happy with this? (Y/N) ";
			break;
		case 1:
			cout << "You selected Elf. Are you happy with this? (Y/N) ";
			break;
		case 2:
			cout << "You selected Halfling. Are you happy with this? (Y/N) ";
			break;
		case 3:
			cout << "You selected Human. Are you happy with this? (Y/N) ";
			break;
		default:
			cout << "You selected an invalid option. Please try again." << endl;
			continue;
		}
		cin >> conf;
	} while (!(conf == 'Y' || conf == 'y'));
	conf = 'x';

	// Will get the starting level of the Character, confirming that a proper value is provided
	do {
		cout << "Please enter which level you would like your character to start at (1 - 20) : ";
		cin >> input;
		try {
			selectedLevel = stoi(input);
		}
		catch (invalid_argument) {
			cout << "You entered an invalid argument. Please try again." << endl;
			continue;
		}
		if (selectedLevel < 0 || selectedLevel > 20) {
			cout << "You entered an invalid level! Please try again." << endl;
			continue;
		}
		else {
			cout << "You entered " << selectedLevel << " as your starting level. Are you happy with this? (Y/N) : ";
			cin >> conf;
		}
	} while (!(conf == 'Y' || conf == 'y'));

	// The Character will now be created, and a view will be attached to it
	Character *myChar = CharacterBuilder::create(name, ClassType(selectedClass), RaceType(selectedRace), selectedLevel);
	return myChar;
}

static void removeCharacter() {
	CharacterSaveManager::removeCharacter();
}
