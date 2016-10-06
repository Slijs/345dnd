#include <iostream>
#include "Item.h"
#include "Weapon.h"

using std::cout;
using std::endl;

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
			
	cout << endl;

	cout << myItem->toString();

	//cout << weapon1->toString();
	cout << myWeapon->toString();


	return 0;
}
