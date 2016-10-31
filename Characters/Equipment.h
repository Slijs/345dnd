#pragma once
#include <string>
#include <iostream>
using namespace std;

class Equipment
{
private:
	string equipName;


public:
	Equipment();
	Equipment(string name);
	~Equipment();

	string getName();
	bool compareName(string name);
};

class Armor :public Equipment
{
private:
	int ACBonus;

public:
	Armor();
	Armor(string name, int ACBonus);
	~Armor();
	int getACBonus();
};

class Shield : public Armor
{
private:
public:
	Shield();
	Shield(string name, int ACBonus);
	~Shield();

};

class Weapon : public Equipment
{
private:
	string dice;
	string weaponType;
public:
	Weapon();
	Weapon(string name, string dice, string weaponType);
	~Weapon();
	string getDice();
	string getWeaponType();
	bool compareType(string name);

};


class Boots : public Equipment
{
private:
	int bonusType; ///0 = NONE, 1 = DEX, 2 = AC
	int bonus;
public:
	Boots();
	Boots(string name, int bonusType, int bonus);
	~Boots();
	int getBonusType();
	int getBonus();

};

class Helmet : public Boots
{
private:
	//Bonus Types
	//0 = NONE, 1 = INT, 2 = WIS, 3 = AC
public:
	Helmet();
	Helmet(string name, int bonusType, int bonus);
	~Helmet();

};

class Ring : public Boots
{
private:
	//Bonus Types
	//0 = NONE, 1= STR, 2 = CON, 3 = WIS, 4 = CHA, 5 = AC
public:
	Ring();
	Ring(string name, int bonusType,int bonus);
	~Ring();

};