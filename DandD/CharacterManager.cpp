/**
*@file CharacterManager.cpp
*@brief Provides implementation of methods for management of Characters
*/
#include "CharacterManager.h"

/**
* Allows the user to select a Character from a list of saved Characters
*/
Fighter* CharacterManager::getCharacter(){
	Fighter* loadedFighter = CharacterSaveManager::loadCharacter();
	if (loadedFighter == NULL)
		cout << "There were issues selecting character." << endl;
	return loadedFighter;
}

/**
* Provides a menu to allow the user to either create a new Character, edit a Character, or delete a Character
*/
void CharacterManager::createOrEditCharacter(){
	char conf = 'X'; // char that will be used to get user input
	bool cont = true;

	// Ask if user wants to CREATE or EDIT the character
	do{
		_displayCreateEditMenu;
		cin >> conf;
		switch (conf){
		case '1': // User wants to create a new character
			_createNewCharacter();
			cont = false;
			break;
		case '2': // User wants to edit a saved character
			_editCharacter();
			cont = false;
			break;
		case '3': // User wants to delete a character
			_deleteCharacter();
			cont = false;
			break;
		case 'm':
		case 'M':
			return;
		default:
			cout << "Sorry, I think you entered an option that isn't allowed. Please try again." << endl;
		}
	} while (cont);
	return;
}

/**
* Will be used to create a new Character and save it to file.
*/
void CharacterManager::_createNewCharacter(){
	string name = "";	// Will be used to get Character's name
	string input = "";	// Will store input
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

	// The Character will now be created and it will be saved to file
	Fighter *myChar = CharacterBuilder::create(selectedLevel, Race(selectedRace), name);
	CharacterSaveManager::saveCharacter(myChar);
	cout << myChar->getName() << " has been saved!";
	delete myChar;
	return;
}

void CharacterManager::_editCharacter(){
	Fighter *theChar = CharacterSaveManager::loadCharacter();
	
	// If no character was loaded, then the method will just return without doing anything
	if (theChar == NULL)
		return;
}

/**
* Allows the user to delete a saved Character
*/
void CharacterManager::_deleteCharacter(){
	CharacterSaveManager::removeCharacter();
}

/**
* Prints the Create / Edit menu to screen
*/
void CharacterManager::_displayCreateEditMenu(){
	cout << "Please enter what you would like to do: " << endl;
	cout << "     [1] - Create a new character" << endl;
	cout << "     [2] - Edit an existing character" << endl;
	cout << "     [3] - Delete a saved character" << endl;
	cout << "Enter 'M' to return to main menu." << endl;
	cout << "Enter your option here: ";
}