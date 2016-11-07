/**
*@file CharacterSaveMap.h
*@brief Declaration of CharacterSaveMap class
*<p> Allows storage in memory of Character Save files, with (name, path) pairs being saved
*
#pragma once
#ifndef CHARACTERSAVEMAP_H
#define CHARACTERSAVEMAP_H

#include <string>
#include <afx.h>
#include <iostream>
#include "CharSaveManager.h"
using namespace std;


class CharacterSaveMap : public CObject {
protected:
	DECLARE_SERIAL(CharacterSaveMap);
public:
	CharacterSaveMap(); // Default Constructor

	int size(); // returns number of characters
	bool isEmpty(); // returns if no Characters saved
	bool contains(const CString &charName); // returns t if contains k
	CString getPath(const CString &charName); // Searches for path associated w/ charName
	void put(const CString &charName, const CString &charPath);	// Adds character and path to Map
	CString remove(const CString &charName); // Removes the entry associated w/ charName
	void printNames();
	void Serialize(CArchive &ar);
	~CharacterSaveMap() {}; // Default destructor
private:
	static const int _MAX_SIZE = 20;
	CString _charMap[_MAX_SIZE][2]; // Multidimensional array containing [charName][charPath] pairs
	int _size; // # Characters saved so far
};
#endif
