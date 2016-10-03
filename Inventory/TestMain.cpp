#include <iostream>
#include "Item.h"
#include "Weapon.h"

using std::cout;
using std::endl;

int main() {
	Item *myItem = new Item();

	myItem->name = "Hello";
	myItem->value = 5;
	
	//int enchantmentArray[9] = {1, 2, 3, 4, 8, 4, 3, 2, 1};
	//int* enchantmentArrayP = enchantmentArray;

	//myItem.setEnchantments(enchantmentArrayP, 9);
	
	//cout << enchantmentArray.size() << endl;

	//cout << enchantmentArray[0];

	cout << myItem->name << " has value " << myItem->value;

	cout << endl;

	//cout myItem.toString();

	Weapon *myWeapon = new Weapon();

	myWeapon->name = "Water Balloon";
	myWeapon->weight = 4;
	myWeapon->damage = 2;

	cout << myWeapon->name << " has value " << myWeapon->weight <<
		" and damage " << myWeapon->damage << endl;
	
	Weapon *weapon1 = new Weapon("Garden Hose", 5, 3, "No Image Yet", {0,0,0,0,0,0,0,2,5});

	cout << endl;
	cout << "--------------------Weapon 1-------------------" << endl;
	cout << "------------------" << weapon1->name << "---------------" << endl;
	cout << "Weight: " << weapon1->weight << "\tValue: " <<
		weapon1->value << "\tImage: " << weapon1->image << endl;
	cout << "Enchantments:" << endl;
	cout << "STR\tDEX\tCON\tINT\tWIS\tCHA\tARM\tATT\tDEF" << endl;
	for (int i = 0; i < 9; i++) {
		cout << weapon1->enchantmentValues[i] << "\t";
	}



	return 0;
}
