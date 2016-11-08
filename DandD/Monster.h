#pragma once
#include "Characters.h"
#include "Fighter.h"

/*!
Class that inherits from Characters and each Monster has a Type, Size, name, hitDie, hitPoints and a speed
in addition to attributes inherited from Characters.
Upon use of constructor to create monster, the equipWeapon() function must be called as
it calculated the damagebonus and attackbonus
Also note that the hitDie is determined by the monster size (the larger the monster the larger the hit die)
Hit Points are calculated in much the same way as Fighters (see Fighter Class for more detail)

*/

class Fighter;

class Monster : public Characters
{
private:
	Type type;
	Size size;
	string name;
	int hitDie;
	int hitPoints;
	int speed;
	void detHitDie();
	void detHitPoints();

public:
	//Commented out constructor b/c returning errors
	//Monster(string, Type, Size, int, int, int, int, int, int, int, int, int, Weapon*);
	Monster();
	~Monster();

	string getName(){ return name; }

	void Monster::equipWeapon(Weapon* w);
	void displayBattle();
	void displayDeath();

	void attack(Fighter* c);
	void receiveDamage(int);
	void currentState();

};
