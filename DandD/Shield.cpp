/**
 * @brief Class for shields.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

#include <string>
#include <stdexcept>
#include "Shield.h"

IMPLEMENT_SERIAL(Shield, Item, 1);

// Default constructor, useless item as is
Shield::Shield() : 	
	Item("No name set", 0, 0, "assets/defaultShield.jpg", { {0,0,0,0,0,0,0,0,0} }, { { 0,0,0,0,0,0,1,0,0 } }), defense(0), attackDice("1d4"), range(0)
{

}

Shield::Shield(const Shield* otherShield) : Item(otherShield){
	this->attackDice = otherShield->attackDice;
	this->range = otherShield->range;

}

// Constructor where all attributes EXCEPT the enchantmentsPossible
// will be set.
Shield::Shield(std::string name, int weight, int value, std::string image,
		std::array<int, 9> enchantmentValues, int defense, std::string attackDice, int range)
	: Item(name, weight, value, image, enchantmentValues, {0,0,0,0,0,0,1,0,0})
{
	setDefense(defense);
	setAttackDice(attackDice);
	setRange(range);
}

// Getters/Setters

int Shield::getDefense() {
	return defense;
}

int Shield::getRange() {
	return range;
}

void Shield::setDefense(int defense) {
	if (defense < 0 || defense > 25) {
		throw "Defense must be between 0 and 25.";
	}
	else {
		this->defense = defense;
	}
}

void Shield::incrementDefense() {
	defense++;
}

void Shield::decrementDefense() {
	defense--;
}


void Shield::setRange(int range)
{
	if (range < 0 || range > 10) {
		throw "Range must be between 0 and 10.";
	}
	else {
		this->range = range;
	}
}

void Shield::incrementRange() {
	range++;
}

void Shield::decrementRange() {
	range--;
}

std::string Shield::getAttackDice()
{
	return attackDice;
}

void Shield::setAttackDice(std::string diceString)
{
	// check to make sure that the dice string is valid
	Dice tempDice = Dice();
	if (tempDice.roll(diceString) < 0) {
		throw "Dice string is invalid.";
	}
	else {
		this->attackDice = diceString;
	}
}

// Misc methods

std::string Shield::toString() {
	std::string tempString;

	tempString = Item::toString();
	
	tempString += "Defense: " + std::to_string(getDefense()) + 
		"Attack dice: " + getAttackDice() +
		"" "\n";

	return tempString;
}

void Shield::Serialize(CArchive &ar) {
	Item::Serialize(ar);
	if (ar.IsStoring()) {
		ar << defense;
		CString c_attackDice(attackDice.c_str());
		ar << c_attackDice;
		ar << range;
	}
	else {
		ar >> defense;
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