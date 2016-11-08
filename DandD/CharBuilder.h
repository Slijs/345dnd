/**
*@file CharacterBuilder.h
*@brief Defines the CharacterBuilder class, which is used to setup Character objects with randomized ability scores.
*/
#pragma once
#ifndef CHARACTERBUILDER_H
#define CHARACTERBUILDER_H
#include "Characters.h"
#include "Fighter.h"
#include "Entity.h"
#include "Dice.h"
#include <iostream> // Allows the CharacterBuilder to print out


/**
*@class CharacterBuilder
*@brief Allows initialization of a Character with random ability scores. Will return a pointer to the initialized Character
*/
class CharacterBuilder {
public:

	static Characters* create(int level, Race race, string name);
};
#endif