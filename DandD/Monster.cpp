#include "Monster.h"

//!Default constructor - for making dummy monsters
Monster::Monster() : Characters() {
	this->name = "dummy";
	this->type = Beast;
	this->size = Medium;
	this->speed = 20;
	detHitDie();
	detHitPoints();
}

/* Commented out as it is causing errors
//!Parameterized Constructor that sets name, type, size, level, speed , ability scores and armor class
Monster::Monster(string name, Type type, Size size, int level, int speed, int STR, int DEX, int CON, int INT, int WIS, int CHA, int armorClass, Weapon* weapon) : Characters(level, STR, DEX, CON, INT, WIS, CHA, armorClass)
{
	this->name = name;
	this->type = type;
	this->size = size;
	this->speed = speed;
	detHitDie();
	detHitPoints();
	equipWeapon(weapon);
}
*/

//!Destructor
Monster::~Monster()
{}

/*!Function to determine the hitDie of the monster based on the size.
Tiny: d4, Small: d6, Medium: d8, Large: d10, Huge: d12 and Gargantuan: d20*/
void Monster::detHitDie()
{
	switch (size)
	{
	case Tiny:
		hitDie = 4;
	case Small:
		hitDie = 6;
	case Medium:
		hitDie = 8;
	case Large:
		hitDie = 10;
	case Huge:
		hitDie = 12;
	case Gargantuan:
		hitDie = 20;
	}
}

//!Function to calculate HitPoints based on initialized level
void Monster::detHitPoints()
{
	int level = this->getLevel();
	//At Level 1: HP = max_HitDie + CON_mod
	hitPoints = hitDie + this->getScores(1, 2);
	//For every level: HP = HP + roll_HitDie + CON_mod
	for (int i = 2; i <= level; i++)
	{
		hitPoints += this->rollDice(hitDie) + this->getScores(1, 2);
	}
}

//!Function to equip weapon and calculate Attack and Damage Bonuses
void Monster::equipWeapon(Weapon* w)
{
	//equip(w);
	calcAttackBonus();
	calcDamageBonus();
}

//!Function to display fighter battle stats, calls parent displayBattle()
void Monster::displayBattle()
{
	cout << "\nMonster: " << name << " Type: " << typeString[type];
	cout << "\nHit Points: " << hitPoints << endl;
	this->Characters::displayBattle();
}

/*!Function for attacking a Fighter, generates attack roll and checks it agains Fighter's AC
If larger than AC, damage roll is calculated and inflicted on Fighter, otherwise attack fails*/
void Monster::attack(Fighter* c)
{

	int aRoll = attackRoll(), dRoll;
	string name;

	cout << this->getName() << " rolled " << aRoll << " for attack!" << endl;

	if (aRoll < c->getArmorClass())
	{
		cout << "Attack missed!" << "\n" << endl;
	}
	else
	{
		cout << "Attack was successful!" << endl;
		dRoll = damageRoll();
		c->receiveDamage(dRoll);

	}
}

/*!Function that reduces hitpoints based on damage taken,
if hitpoints reduce to 0 or less, fighter is dead. Notifies change in character stats*/
void Monster::receiveDamage(int damage)
{
	hitPoints -= damage;
	cout << damage << " damage was inflicted on " << name << "!" << endl;
	if (hitPoints <= 0)
	{
		setIsDead(true);
		return;
	}
	currentState();
}

//!Function to display monster death, calls parent displayDeath()
void Monster::displayDeath()
{
	cout << "\n" << name;
	Characters::displayDeath();
}

void Monster::currentState()
{
	Notify();
}
