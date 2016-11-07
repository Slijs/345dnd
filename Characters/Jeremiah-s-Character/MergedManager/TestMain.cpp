#include <iostream>
#include <vector>
#include <memory>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Belt.h"
#include "Boots.h"
#include "Helmet.h"
#include "Ring.h"
#include "Shield.h"
#include "Container.h"

using std::cout;
using std::endl;
using std::vector;

int main() {
	//int enchantmentArray[9] = {1, 2, 3, 4, 8, 4, 3, 2, 1};
	//int* enchantmentArrayP = enchantmentArray;

	//myItem.setEnchantments(enchantmentArrayP, 9);
	
	//cout << enchantmentArray.size() << endl;

	//cout << enchantmentArray[0];

	//cout myItem.toString();

	Item *myItem = new Item("Water Balloon", 4, 1, "NopeNotYet", {1, 2, 3, 4, 5, 4, 3, 2, 1});

	//Weapon *weapon1 = new Weapon("Garden Hose", 5, 3, "No Image Yet", 
	//		{0,0,0,0,0,0,0,2,5}, 3, 2, 4);

	Weapon *myWeapon = new Weapon();

	Armor *myArmor = new Armor("Chainmail", 12, 52, "/home/pbrink/Pictures/puppy.jpg", {0,0,0,0,0,0,5,0,0}, 8);

	//std::unique_ptr<Armor> myArmor;
			
	cout << endl;

	cout << myItem->toString();

	//cout << weapon1->toString();
	cout << myWeapon->toString();

	cout << myArmor->toString();

	vector<Item *> myItems;
	myItems.push_back(myItem);
	myItems.push_back(myWeapon);
	myItems.emplace_back(myArmor);
	//myItems.push_back(std::unique_ptr<Armor>(new Armor("Chainmail", 12, 52, "/home/pbrink/Pictures/puppy.jpg", {0,0,0,0,0,0,5,0,0}, 8)));

	cout << myItems[2]->toString();

	cout << std::endl;

	//cout << typeid(*myItems[2]);
	int someVariable = 5;
	//cout << typeid(*myArmor).name() << std::endl;
	//cout << typeid(*myItems[2]).name() << std::endl;

	Container *myContainer = new Container(4, myItems);
	cout << myContainer->toString();
	cout << myContainer->contentsToString();

	/*
	cout << "------------------- new test -----------------\n";

	Armor* newArmor = new Armor("Plate Armor", 20, 75, "/path/to/picture", {0,0,0,0,0,0,2,0,0}, 4);
	cout << typeid(newArmor).name();

	vector<std::unique_ptr<Item>> armourVector;

	armourVector.emplace_back(newArmor);
	
	cout << typeid(armourVector[0]).name();

	Armor* nextArmor = armourVector[0];

	cout << typeid(nextArmor).name();
	*/

	return 0;
}
