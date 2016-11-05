#include "Characters.h"
#include "Fighter.h"
#include "Monster.h"
#include "CharacterObserver.h"

void processChoice(Fighter*, int);

int input;
int main()
{
	int level;
	string name;
	string mName = "Goblin";
	Monster* m1 = new Monster(mName, Humanoid, Small, 4, 30, 8, 14, 10, 10, 8, 8, 15);
	m1->equipWeapon(new Weapon("Scimitar", "1d6", "Melee"));
	CharacterObserver *mo = new CharacterObserver(m1);

	cout << "Welcome to Dungeon and Dragon game!\n"<<endl;

	
	Fighter* f1 = new Fighter(1, Dwarf, "Gordon");
	
	f1->displayStats();

	CharacterObserver *co = new CharacterObserver(f1);

	string weaponName;
	string currentWeapon;

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
	
	cout << "Start Journey!\n";
	
	cout << "\nLevel up!" << endl;
	//to test leveling up
	f1->gainExperience(400);

	int index;
	cout << "\nWhich ability scores do you wish to increment?\n";
	cout << "0: STR, 1: DEX, 2: CON, 3: INT, 4: WIS, 5: CHA"<<endl;
	cin >> index;
	f1->levelUp(index);
	f1->currentState();


	//to test battle
	
	cout << "\n\nMonster Encounter!" << endl;
	m1->displayBattle();
	m1->startBattle(f1);
	int choice;
	do
	{
		cout << "\n" << m1->getName() << " attacks " << f1->getName() << "!\n" << endl;
		m1->attack(f1);

		cout << "\nWhat would you like to do? " << endl;
		cout << "1. Attack\n";
		cout << "2. Escape\n";
		cout << "(0: Exit Program) ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "\n" << f1->getName() << " attacks " << m1->getName() << "\n"<<endl;
			f1->attack(m1);
		}	
		else
		{
			system("PAUSE");
			exit(0);
		}
			
		
	}while (!m1->getIsDead());

	f1->endBattle();

	cout << "\n\n"<< mName << " has been defeated!" << endl;
	int expGained = m1->getExp();
	m1->~Monster();
	cout << f1->getName() << " has gained " << expGained << " experience!" << endl;

	f1->gainExperience(expGained);
	
	
	
	f1->~Fighter();
	
	mo->~CharacterObserver();
	co->~CharacterObserver();
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
