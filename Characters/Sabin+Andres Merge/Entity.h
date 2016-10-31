#pragma once

//enumeration  classes

enum Race {  //this is useful to check if the user inputted a valid entry
	Dwarf,
	Elf,
	Halfling,
	Human,
	Length2
};

enum Size{
	Small, Medium

}; // add more later

class Entity
{							//entity class that includes all entities like monsters, trees, characters, etc

public:

	//variables
	Race charRace;
	int charLevel;

	//int Ability[AbilityType::Length];						
	//creating an appropriate array size by referring to the amount of abilities there are in enumeration

	//constructors & destructor
	Entity();												//default constructor
	Entity(Race entityRace, int entityLevel);				//parameterized constructor
	~Entity();												//deconstructor

	//int GetAbility(AbilityType type);						
};