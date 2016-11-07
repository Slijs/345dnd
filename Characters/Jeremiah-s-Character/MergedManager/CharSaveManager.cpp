/**
*@file CharSaveManager.cpp
*@brief Definition of methods for CharacterSaveManager class
*/
#include "stdafx.h"
#include "CharSaveManager.h"
#include "CharacterSaveMap.h"
#include <string>
#include <iostream>
using namespace std;

/**
* Will save a Fighter to file
*@param theChar Fighter pointer, pointing to the Fighter that will be saved to file
*/
void CharacterSaveManager::saveCharacter(Fighter *theChar) {
	CFile mapFile; // Map of all Character saves
	string input = "";
	CString charName = theChar->getName().c_str();

	// Will create charMap that will contain all Character save locations
	CharacterSaveMap* charMap = new CharacterSaveMap();
	// If the CharMap file can be opened successfully, charMap will be serialized to load the data
	try {
		mapFile.Open(_T("CharacterSaveMap.txt"), CFile::modeRead);
	}
	catch (CFileException &exp) {
		std::cout << "Error accessing Character data. Save attempt aborted." << endl;
		return;
	}
	CArchive mapArchive(&mapFile, CArchive::load);
	try {
		charMap->Serialize(mapArchive);
	}
	catch (CArchiveException &exp) {}
	mapArchive.Close();
	mapFile.Close();
	// Checks to see if the Character has already been saved
	if (charMap->contains(charName)) {
		std::cout << "There is already a save file for " << cstrTostr(charName) << "." << endl;
		std::cout << "Would you like to save over it? (Y/N): ";

		// Will continue to ask for user input until they provide something valid
		while (true) {
			cin >> input;
			if (input.at(0) == 'Y' || input.at(0) == 'y')
				break; // Breaks the loops to continue
			else if (input.at(0) == 'N' || input.at(0) == 'n') {
				std::cout << "Aborting save attempt." << endl;
				return;
			}
			else {
				std::cout << "I'm sorry, but you entered an invalid response." << endl;
				std::cout << "Would you like to save over the character? Please enter Y or N: ";
			}
		}
	}
	// UPDATE THIS Will create save path string
	//CString path = "/Character Saves/" + charName + "StateFile.dat";
	CString path = charName + "StateFile.txt";
	charMap->put(charName, path); // Puts the entry in the Character Map
	// Now, the Character themself will be Serialized
	CFile charFile;
	try {
		charFile.Open(path, CFile::modeCreate | CFile::modeWrite);
	}
	catch (CFileException &exp) {
		std::cout << "There was an error trying to save. Aborting attempt." << endl;
		return;
	}
	CArchive charArchive(&charFile, CArchive::store);
	theChar->Serialize(charArchive);
	charArchive.Close();
	charFile.Close();
	CFile anotherMapFile;
	// Now, the updated CharacterSaveMap will be serialized and saved
	try {
		anotherMapFile.Open(_T("CharacterSaveMap.txt"), CFile::modeCreate | CFile::modeWrite);
	}
	catch (CFileException &exp) {
		std::cout << "There was an error trying to save. Aborting attempt." << endl;
		return;
	}
	CArchive anotherMapArchive(&anotherMapFile, CArchive::store);
	charMap->Serialize(anotherMapArchive);
	anotherMapArchive.Close();
	try {
		anotherMapFile.Close();
	}
	catch (CFileException &exp) {
		std::cout << "There was an error closing out the save operation. Aborting attempt." << endl;
		return;
	}
	std::cout << cstrTostr(charName) << " has been saved!" << endl;
	delete charMap;
	return;
}

/**
* Allows the user to retrieve a Character from file.
*@return Fighter* pointing to the loaded Character (or NULL if unsuccessful)
*/
Character* CharacterSaveManager::loadCharacter() {
	CFile mapFile; // Map of all Character saves
	string input = "";

	// Will create charMap that will contain all Character save locations
	CharacterSaveMap* charMap = new CharacterSaveMap();

	// If the CharMap file can be opened successfully, charMap will be serialized to load the data
	try {
		mapFile.Open(_T("CharacterSaveMap.txt"), CFile::modeRead);
	}
	catch (CFileException *e) {
		cout << "There was an error accessing Character save files. Attempt aborted." << endl;
		return NULL;
	}
	CArchive mapArchive(&mapFile, CArchive::load);
	charMap->Serialize(mapArchive);
	mapArchive.Close();
	mapFile.Close();
	// If the charMap is empty at this point, it means that there are no Characters to load
	if (charMap->isEmpty()) {
		cout << "There are no Characters to load." << endl;
		return NULL;
	}
	cout << "The following Characters are available: " << endl;
	charMap->printNames();
	// Will try to get proper selection from user
	while (true) {
		cout << "Which character would you like to load? (-1 to return)" << endl;
		cin >> input;
		if (input == "-1") {
			cout << "Quitting load attempt at your request." << endl;
			return NULL;
		}
		else if (charMap->contains(input.c_str())) {
			break;
		}
		else {
			cout << "Hmmm... it seems that character isn't available." << endl;
			continue;
		}
	}
	CString path = charMap->getPath(input.c_str()); // Gets path from map
	Fighter *loadedChar = new Fighter();

	// Now, the Character themself will be Serialized
	CFile charFile;
	try {
		charFile.Open(path, CFile::modeRead);
	}
	catch (CFileException &exp) {
		cout << "There was an error trying to save. Aborting attempt." << endl;
		return NULL;
	}
	CArchive charArchive(&charFile, CArchive::load);
	loadedChar->Serialize(charArchive);
	charArchive.Close();
	charFile.Close();
	cout << loadedChar->getName() << " has been loaded!" << endl;
	delete charMap;
	return loadedChar;
}

/**
* Allows the user to remove a Character from all saved Characters
*/
void CharacterSaveManager::removeCharacter() {
	CFile mapFile; // Map of all Character saves
	string input = "";

	// Will create charMap that will contain all Character save locations
	CharacterSaveMap* charMap = new CharacterSaveMap();

	// If the CharMap file can be opened successfully, charMap will be serialized to load the data
	try {
		mapFile.Open(_T("CharacterSaveMap.txt"), CFile::modeRead);
	}
	catch (CFileException *e) {
		cout << "There was an error accessing Character save files. Attempt aborted." << endl;
		return;
	}
	CArchive mapArchive(&mapFile, CArchive::load);
	charMap->Serialize(mapArchive);
	mapArchive.Close();
	mapFile.Close();
	// If the charMap is empty at this point, it means that there are no Characters to remove
	if (charMap->isEmpty()) {
		cout << "There are no Characters to remove." << endl;
		return;
	}
	cout << "The following Characters are available: " << endl;
	charMap->printNames();
	// Will try to get proper selection from user
	while (true) {
		cout << "Which character would you like to remove? (-1 to return)" << endl;
		cin >> input;
		if (input == "-1") {
			cout << "Quitting remove attempt at your request." << endl;
			return;
		}
		else if (charMap->contains(input.c_str())) {
			break;
		}
		else {
			cout << "Hmmm... it seems that character isn't available." << endl;
			continue;
		}
	}
	CString toRemove = input.c_str();
	CString path = charMap->getPath(toRemove); // Gets path from map

	// Deletes the Character's file
	try{
		CFile::Remove(_T(path));
	}
	catch (CFileException *pEx){
		cout << "There was an error removing file from disk." << endl;
	}
	// The entry will be removed from the Map
	charMap->remove(toRemove);

	CFile anotherMapFile;
	// Now, the updated CharacterSaveMap will be serialized and saved
	try {
		anotherMapFile.Open(_T("CharacterSaveMap.txt"), CFile::modeCreate | CFile::modeWrite);
	}
	catch (CFileException &exp) {
		std::cout << "There was an error trying to record efforts. Aborting attempt." << endl;
		return;
	}
	CArchive anotherMapArchive(&anotherMapFile, CArchive::store);
	charMap->Serialize(anotherMapArchive);
	anotherMapArchive.Close();
	try {
		anotherMapFile.Close();
	}
	catch (CFileException &exp) {
		std::cout << "There was an error closing out the remove operation. Aborting attempt." << endl;
		return;
	}

	if (!charMap->contains(toRemove)) {
		cout << cstrTostr(toRemove) << " has been removed!" << endl;
		delete charMap;
		return;
	}
	else {
		cout << "There was an error removing " << cstrTostr(toRemove) << "." << endl;
		delete charMap;
		return;
	}
}

/**
*Converts a CString back to a string
*@param &cstr Reference to a CString
*@return string version of the CString
*/
string CharacterSaveManager::cstrTostr(CString &cstr) {
	int strlen = cstr.GetLength();
	string toRet = "";
	for (int i = 0; i < strlen; ++i) {
		toRet += cstr.GetAt(i);
	}
	return toRet;
}