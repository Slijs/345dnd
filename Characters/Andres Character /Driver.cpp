#include <iostream>
#include <string>
#include "Entity.h"
#include "Character.h"

using namespace std;

int main()
{
	
	//Dwarf Fighter with Melee Weapon
	Character* player1 = new Character(Dwarf, Fighter, 1, 0);

	//Dwarf Fighter with Ranged Weapon
	Character* player2 = new Character(Dwarf, Fighter, 1, 1);

	Character::titleArtwork();
	cout << "Player 1\n\n";
	cout << player1->toString() << "\n";

	player1->characterArtwork();
	
	cout << "Player 2\n\n";
	cout << player2->toString()<<"\n";

	player1->characterArtwork();

	system("PAUSE");

	return 0;

}

