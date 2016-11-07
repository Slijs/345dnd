/**
*@file CharacterBuilder.h
*@brief Defines the CharacterBuilder class, which is used to setup Character objects with randomized ability scores.
*/
#pragma once
#ifndef CHARACTERBUILDER_H
#define CHARACTERBUILDER_H
#include "Character.h"
#include "Entity.h"
#include "Fighter.h"
#include "Dice.h"
#include <iostream> // Allows the CharacterBuilder to print out


/**
*@class CharacterBuilder
*@brief Allows initialization of a Character with random ability scores
*/
class CharacterBuilder {
public:
	static Character* create(int level, Race race, string name, int X, int X, int X, int X, int X, int X);
};
#endif
