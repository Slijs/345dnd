#include "Characters.h"
#include "Fighter.h"
#include "CharacterObserver.h"

void processChoice(Fighter*, int);

int input;
int main()
{
	int level;
	string name;

	cout << "Welcome to Character Creator!\n"<<endl;

	cout << "Enter a name and a level: ";
	cin >> name >> level;


	Fighter* f1 = new Fighter(level, Dwarf, name);
	f1->displayStats();

	CharacterObserver *co = new CharacterObserver(f1);

	string weaponName;
	string currentWeapon;

	if (level > 1)
	{
		cout << "\nWould you like to change equipment? (1: YES, 0: NO) ";
		cin >> input;
		while (input != 0)
		{
			int input2;
			cout << "What do you wish to equip? (0: EXIT) " << endl;
			cout << "1. ";
			currentWeapon = f1->currentWeapon().c_str();
			if (currentWeapon.compare("Light Crossbow") == 0)
				weaponName = "Longsword";
			else
				weaponName = "Light Crossbow";
			printf("%-10s %-10s", weaponName.c_str(), "2. Light Shield\n");
			printf("%-10s %-10s\n", "3. Helmet", "4. Ring of Strength");
			printf("%-10s\n", "5. Boots of Agility");
			cin >> input2;
			cout << endl;
			processChoice(f1,input2);
			
		} 
	}
	
	f1->~Fighter();

	system("pause");
	return 0;
}

void processChoice(Fighter* f,int in)
{
	string current;
	switch (in)
	{
	case 1: //Weapon
		current = f->currentWeapon().c_str();
		if (current.compare("Light Crossbow")==0)
		{
			cout << "Longsword is now equipped.\n" << endl;
			f->equip(new Weapon("Longsword", "1d8", "Melee"));
		}
		else
		{
			cout << "Light Crossbow is now equipped.\n" << endl;
			f->equip(new Weapon("Light Crossbow", "1d8", "Ranged"));
		}
		break;	
	case 2: //Shield
			current = f->currentShield().c_str();
			if (current.compare("NONE") == 0)
			{
				cout << "This shield increases AC by 2\n" << endl;
				f->equip(new Shield("Light Shield", 2));
			}
			else
			{
				cout << "Shield already equipped.\n" << endl;
			}
			break;
	case 3: //Helmet
		current = f->currentHelmet().c_str();
		if (current.compare("NONE") == 0)
		{
			cout << "This Helmet increases INT by 1\n" << endl;
			f->equip(new Helmet("Helmet", 2, 1));
		}
		else
		{
			cout << "Helmet already equipped.\n" << endl;
		}
		break;
	case 4: //Ring
		current = f->currentRing().c_str();
		if (current.compare("NONE") == 0)
		{
			cout << "This ring will increase STR by 1.\n" << endl;
			f->equip(new Ring("Ring of Strength", 1, 1));
		}
		else
		{
			cout << "Ring already equipped.\n" << endl;
		}
		break;
	case 5: //Boots
		current = f->currentBoots().c_str();
		if (current.compare("NONE") == 0)
		{
			cout << "These boots will increase DEX by 1.\n" << endl;
			f->equip(new Boots("Boots of Agility", 1, 1));
		}
		else
		{
			cout << "Boots already equipped." << endl;
		}
		break;
	case 0:
		input = 0;
		break;
	default: //Invalid Entry
		cout << "Invalid Entry. Please enter a number from 1 to 5.\n" << endl;
		break;
	}
}