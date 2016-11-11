/**
 * @brief Class for weapons.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

#include <string>
#include <stdexcept>
#include "Weapon.h"
#include "Dice.h"

IMPLEMENT_SERIAL(Weapon, Item, 1);

// Default constructor, useless item as is
Weapon::Weapon() :
	Item("None", 0, 0, "assets/defaultWeapon.jpg", { { 0,0,0,0,0,0,0,0,0 } }, { { 0,0,0,0,0,0,0,1,1 } })
{
	setAttackDice("1d4"); // Sets a default attack die
	setRange(0);
}

Weapon::Weapon(const Weapon* otherWeapon) : Item(otherWeapon) {
	this->attackDice = otherWeapon->attackDice;
}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Weapon::Weapon(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, string attackDice, int range) 
	: Item(name, weight, value, image, enchantmentValues, {0,0,0,0,0,0,0,1,1})
{
	setAttackDice(attackDice);
	setRange(range);
}

// Getters/Setters

int Weapon::getRange() {
	return range;
}

void Weapon::setRange(int newRange)
{
	if (newRange < 0 || newRange > 10) {
		throw "Range must be between 0 and 10.\n";
	}
	else {
		range = newRange;
	}
}

void Weapon::incrementRange() {
	if (range < 25) { range++; }
}

void Weapon::decrementRange() {
	if (range >= 1) {
		range--;		
	}
}

// Misc methods

string Weapon::getAttackDice()
{
	return attackDice;
}

void Weapon::setAttackDice(string attackDice)
{
	// check to make sure that the dice string is valid
	Dice tempDice = Dice();
	if (tempDice.roll(attackDice) < 0) {
		throw "Dice string is invalid.";
	}
	else {
		this->attackDice = attackDice;
	}
}

std::string Weapon::toString() {
	std::string tempString;

	tempString = "Weapon: ";
	tempString += Item::toString();
	
	tempString += "Attack Dice: " + getAttackDice() +
		"\tRange: " + std::to_string(getRange()) + "\n";

	return tempString;
}

void Weapon::Serialize(CArchive &ar) {
	Item::Serialize(ar);
	if (ar.IsStoring()) {
		CString c_attackDice(attackDice.c_str());
		ar << c_attackDice;
		ar << range;
	}
	else {
		CString c_attackDice = "";
		ar >> c_attackDice;
		attackDice = "";
		int strlen = c_attackDice.GetLength();
		for (int i = 0; i < strlen; ++i) {
			attackDice += c_attackDice.GetAt(i);
		}
		ar >> range;
	}
}