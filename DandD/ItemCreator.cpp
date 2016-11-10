#include "ItemCreator.h"

using std::cout;
using std::endl;
using std::vector;

void ItemCreator::createItems()
{
	Container * userContainer = new Container();
	bool continuing = true;
	// create item loop
	while (continuing && userContainer->getNumContents() < userContainer->getMaxContents()) {
		// ask if the user wants to continue
		/*
		cout << "Continue? [y/n] ";
		char yesOrNo;
		std::cin >> yesOrNo;
		if (yesOrNo != 'y' && yesOrNo != 'Y') {
			continuing = false;
			break;
		}
		*/

		// check what type of item the user would like to create
		cout << "What do you want to do?\n";
		cout << "1) Create Weapon\n2) Create Armour\n3) Create Helmet\n4) Create Shield\n5) Create Belt\n6) Create Ring\n7) Create Boots\n8) Print created items\n9) Save Items to File\n10) Load Items from File\n11) Back to Menu\nEnter Choice: ";
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		string line;
		std::getline(std::cin, line);
		std::istringstream choice(line);
		int number;
		choice >> number;
		if (number)
		{
			if (number == 1)
			{
				string name;
				string attackDice;
				int range;
				int attackBonus;
				int damageBonus;
				int weight;
				int value;

				string line2;

				cout << "Enter name: ";
				std::getline(std::cin, name);

				cout << "Enter attack dice: [ndn] ";
				std::getline(std::cin, attackDice);

				cout << "Enter range: [0-10] ";
				std::getline(std::cin, line2);
				std::istringstream choice5(line2);
				choice5 >> range;

				cout << "Enter attack bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice6(line2);
				choice6 >> attackBonus;

				cout << "Enter damage bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice7(line2);
				choice7 >> damageBonus;

				cout << "Enter weight: [0-25] ";
				std::getline(std::cin, line2);
				std::istringstream choice8(line2);
				choice8 >> weight;

				cout << "Enter value: [0-999]";
				std::getline(std::cin, line2);
				std::istringstream choice9(line2);
				choice9 >> value;
				try
				{
					Weapon * weapon = new Weapon(name, weight, value, "assets/defaultWeapon.jpg", { 0,0,0,0,0,0,0,attackBonus, damageBonus }, attackDice, range);
					cout << "\nHere is the weapon that you created:\n";
					cout << weapon->toString();
					cout << "\n";
					userContainer->insertItem(weapon);
				}
				catch (...)
				{
					cout << "The values that you entered were invalid. The item was not created.\n";
				}

			}
			else if (number == 2)
			{
				string name;
				int defense;
				int armourBonus;
				int weight;
				int value;

				string line2;

				cout << "Enter name: ";
				std::getline(std::cin, name);

				cout << "Enter defense: [0-25] ";
				std::getline(std::cin, line2);
				std::istringstream choice4(line2);
				choice4 >> defense;

				cout << "Enter armour bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice6(line2);
				choice6 >> armourBonus;

				cout << "Enter weight: [0-25] ";
				std::getline(std::cin, line2);
				std::istringstream choice8(line2);
				choice8 >> weight;

				cout << "Enter value: [0-999]";
				std::getline(std::cin, line2);
				std::istringstream choice9(line2);
				choice9 >> value;
				try
				{
					Armor * armor = new Armor(name, weight, value, "assets/defaultArmor.jpg", { 0,0,0,0,0,0,armourBonus,0, 0 }, defense);
					cout << "\nHere is the armor that you created:\n";
					cout << armor->toString();
					cout << "\n";
					userContainer->insertItem(armor);
				}
				catch (...)
				{
					cout << "The values that you entered were invalid. The item was not created.\n";
				}
			}
			else if (number == 3)
			{
				string name;
				int intelligenceBonus;
				int wisdomBonus;
				int armourBonus;
				int weight;
				int value;

				string line2;

				cout << "Enter name: ";
				std::getline(std::cin, name);

				cout << "Enter intelligence bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice5(line2);
				choice5 >> intelligenceBonus;

				cout << "Enter wisdom bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice16(line2);
				choice16 >> wisdomBonus;

				cout << "Enter armour bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice6(line2);
				choice6 >> armourBonus;

				cout << "Enter weight: [0-25] ";
				std::getline(std::cin, line2);
				std::istringstream choice8(line2);
				choice8 >> weight;

				cout << "Enter value: [0-999]";
				std::getline(std::cin, line2);
				std::istringstream choice9(line2);
				choice9 >> value;
				try
				{
					Helmet * helmet = new Helmet(name, weight, value, "assets/defaultHelmet.jpg", { 0,0,0,intelligenceBonus,wisdomBonus,0,armourBonus,0, 0 });
					cout << "\nHere is the helmet that you created:\n";
					cout << helmet->toString();
					cout << "\n";
					userContainer->insertItem(helmet);
				}
				catch (...)
				{
					cout << "The values that you entered were invalid. The item was not created.\n";
				}
			}
			else if (number == 4) {
				string name;
				int defense;
				string attackDice;
				int range;
				int armourBonus;
				int weight;
				int value;

				string line2;

				cout << "Enter name: ";
				std::getline(std::cin, name);

				cout << "Enter defense: [0-25] ";
				std::getline(std::cin, line2);
				std::istringstream choice4(line2);
				choice4 >> defense;

				cout << "Enter attack dice [dnd]: ";
				std::getline(std::cin, attackDice);

				cout << "Enter range: [0-25] ";
				std::getline(std::cin, line2);
				std::istringstream choice14(line2);
				choice14 >> range;

				cout << "Enter armour bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice6(line2);
				choice6 >> armourBonus;

				cout << "Enter weight: [0-25] ";
				std::getline(std::cin, line2);
				std::istringstream choice8(line2);
				choice8 >> weight;

				cout << "Enter value: [0-999]";
				std::getline(std::cin, line2);
				std::istringstream choice9(line2);
				choice9 >> value;
				try
				{
					Shield * shield = new Shield(name, weight, value, "assets/defaultShield.jpg", { 0,0,0,0,0,0,armourBonus,0, 0 }, defense, attackDice, range);
					cout << "\nHere is the shield that you created:\n";
					cout << shield->toString();
					cout << "\n";
					userContainer->insertItem(shield);
				}
				catch (...)
				{
					cout << "The values that you entered were invalid. The item was not created.\n";
				}
			}
			else if (number == 5) {
				string name;
				int constitutionBonus;
				int strengthBonus;
				int weight;
				int value;

				string line2;

				cout << "Enter name: ";
				std::getline(std::cin, name);

				cout << "Enter constitution bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice6(line2);
				choice6 >> constitutionBonus;

				cout << "Enter strength bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice16(line2);
				choice16 >> strengthBonus;

				cout << "Enter weight: [0-25] ";
				std::getline(std::cin, line2);
				std::istringstream choice8(line2);
				choice8 >> weight;

				cout << "Enter value: [0-999]";
				std::getline(std::cin, line2);
				std::istringstream choice9(line2);
				choice9 >> value;
				try
				{
					Belt * belt = new Belt(name, weight, value, "assets/defaultBelt.jpg", { strengthBonus,0,constitutionBonus,0,0,0,0,0, 0 });
					cout << "\nHere is the belt that you created:\n";
					cout << belt->toString();
					cout << "\n";
					userContainer->insertItem(belt);
				}
				catch (...)
				{
					cout << "The values that you entered were invalid. The item was not created.\n";
				}
			}
			else if (number == 6) {
				string name;
				int defense;
				int constitutionBonus;
				int strengthBonus;
				int wisdomBonus;
				int charismaBonus;
				int armourBonus;
				int weight;
				int value;

				string line2;

				cout << "Enter name: ";
				std::getline(std::cin, name);

				cout << "Enter defense: [0-25] ";
				std::getline(std::cin, line2);
				std::istringstream choice4(line2);
				choice4 >> defense;

				cout << "Enter constitution bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice6(line2);
				choice6 >> constitutionBonus;

				cout << "Enter strength bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice16(line2);
				choice16 >> strengthBonus;

				cout << "Enter wisdom bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice116(line2);
				choice116 >> wisdomBonus;

				cout << "Enter charisma bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice126(line2);
				choice126 >> charismaBonus;

				cout << "Enter armour bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice136(line2);
				choice136 >> armourBonus;

				cout << "Enter weight: [0-25] ";
				std::getline(std::cin, line2);
				std::istringstream choice8(line2);
				choice8 >> weight;

				cout << "Enter value: [0-999]";
				std::getline(std::cin, line2);
				std::istringstream choice9(line2);
				choice9 >> value;
				try
				{
					Ring * ring = new Ring(name, weight, value, "assets/defaultRing.jpg", { strengthBonus,0,constitutionBonus,0,wisdomBonus,charismaBonus,armourBonus,0, 0 });
					cout << "\nHere is the ring that you created:\n";
					cout << ring->toString();
					cout << "\n";
					userContainer->insertItem(ring);
				}
				catch (...)
				{
					cout << "The values that you entered were invalid. The item was not created.\n";
				}
			}
			else if (number == 7) {
				string name;
				int dexterityBonus;
				int armourBonus;
				int weight;
				int value;

				string line2;

				cout << "Enter name: ";
				std::getline(std::cin, name);

				cout << "Enter dexterity bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice5(line2);
				choice5 >> dexterityBonus;

				cout << "Enter armour bonus: [0-5] ";
				std::getline(std::cin, line2);
				std::istringstream choice6(line2);
				choice6 >> armourBonus;

				cout << "Enter weight: [0-25] ";
				std::getline(std::cin, line2);
				std::istringstream choice8(line2);
				choice8 >> weight;

				cout << "Enter value: [0-999]";
				std::getline(std::cin, line2);
				std::istringstream choice9(line2);
				choice9 >> value;
				try
				{
					Boots * boots = new Boots(name, weight, value, "assets/defaultBoots.jpg", { 0,dexterityBonus,0,0,0,0,armourBonus,0, 0 });
					cout << "\nHere is the shield that you created:\n";
					cout << boots->toString();
					cout << "\n";
					userContainer->insertItem(boots);
				}
				catch (...)
				{
					cout << "The values that you entered were invalid. The item was not created.\n";
				}
			}
			else if (number == 8) {
				cout << userContainer->contentsToString();
			}
			else if (number == 9) {
				/* TODO LET USER DEFINE PATH
				cout << "Enter file name: ";
				string path;
				std::getline(std::cin, path);
				*/

				// serialize 
				CFile fileS;
				if (!fileS.Open(_T("serializedItems.dat"), CFile::modeWrite))
				{
					std::cout << "Unable to open output file" << std::endl;
					break;

					if (FILE *file = fopen("serializedItems.dat", "r")) {
						fclose(file);
						if (!fileS.Open(_T("serializedItems.dat"), CFile::modeWrite))
						{
							std::cout << "Unable to open output file" << std::endl;
							break;
						}
						cout << "Saving items...\n";
						CArchive arStore(&fileS, CArchive::store);
						userContainer->Serialize(arStore);
						arStore.Close();
						fileS.Close();
					}
					else {
						if (!fileS.Open(_T("serializedItems.dat"), CFile::modeWrite | CFile::modeCreate))
						{
							std::cout << "Unable to open output file" << std::endl;
							break;
						}
						cout << "Saving items...\n";
						CArchive arStore(&fileS, CArchive::store);
						userContainer->Serialize(arStore);
						arStore.Close();
						fileS.Close();
					}

				}
			} 
			else if (number == 10) {
				/* TODO -- make user be able to define path. At this time,
					* this isn't possible, because can't convert to type of
					* string that CFile.open will accept...
				cout << "Enter file name: ";
				string Lpath;
				std::getline(std::cin, Lpath);
				*/
				CFile fileL;
				if (!fileL.Open(_T("serializedItems.dat"), CFile::modeRead))
				{
					std::cout << "Unable to open input file" << std::endl;
					break;
				}
				cout << "Loading items...\n";
				CArchive arLoad(&fileL, CArchive::load);
				userContainer->Serialize(arLoad);
				arLoad.Close();
				fileL.Close();
			}
			else if (number == 11) {
				continuing = false;
				break;
			}
			else {
				cout << "Invalid choice.\n";
			}
		}
		else
		{
			cout << "input does not start with a number or is too big for an int\n";
		}
	}
}