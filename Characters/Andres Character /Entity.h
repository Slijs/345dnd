#pragma once

//enumeration  classes
enum Class {
	Fighter,
	Length1
};

enum Race {  //this is useful to check if the user inputted a valid entry
	Dwarf,
	Elf,
	Halfling,
	Human,
	Length2
};

enum Size{Small, Medium

}; // add more later

class Entity
{							//entity class that includes all entities like monsters, trees, characters, etc

public:

	//variables
	Class charClass;
	Race charRace;
	int charLevel;

	//int Ability[AbilityType::Length];						
	//creating an appropriate array size by referring to the amount of abilities there are in enumeration

	//constructors & destructor
	Entity();												//default constructor
	Entity(Race entityRace, Class entityClass, int entityLevel);				//parameterized constructor
	~Entity();												//deconstructor

															//int GetAbility(AbilityType type);						
};



/*
enum AbilityType : int { //can be used to store each value of a specific characters abilities
Strength,            //e.g. array index 1 represents wisdom, and the value there can be 10
Wisdom,
Dexterity,
Charisma,
Constitution,
Intelligence,
Length
};

*/
