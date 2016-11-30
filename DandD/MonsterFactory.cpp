/**
*@file MonsterFactory.cpp
*@brief Provides implementation of MonsterFactory methods
*/
#include "MonsterFactory.h"

/**
* Takes a playable Character's level and randomly generates one of 10 Monsters with the same level as the player.
* Returns a pointer to the newly generated Monster
*@param theChar Fighter* to the Fighter that will be used as reference
*@return Monster* to a randomly generated Monster
*/
Monster* MonsterFactory::createMonster(Fighter* theChar, bool friendFlag){
	Dice adie;
	int playerLevel = theChar->getLevel();
	int randNum = adie.roll("1d10");
	if (friendFlag == true)
	{
		return new Monster("Axe Beak", Beast, Large, playerLevel, 4, adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), 11,
			new Weapon("Beak", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d8", 0), theChar);
	}
	switch (randNum){
	case 1:
		return new Monster("Goblin Soldier", Humanoid, Small, playerLevel, 2, adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), 15, 
			new Weapon("Scimitar", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d6", 0), theChar);
	case 2:
		return new Monster("Goblin Archer", Humanoid, Small, playerLevel, 1, adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), 15, 
			new Weapon("Shortbow", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d6", 1), theChar);
	case 3:
		return new Monster("Grimlock", Humanoid, Medium, playerLevel, 2, adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), 11, 
			new Weapon("Spiked Bone Club", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d4", 0), theChar);
	case 4:
		return new Monster("Pseudodragon", Dragon, Tiny, playerLevel, 3, adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), 13, 
			new Weapon("Bite", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d4", 0), theChar);
	case 5:
		return new Monster("Sprite", Fey, Tiny, playerLevel, 2, adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), 15, 
			new Weapon("Longsword", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d8", 0), theChar);
	case 6:
		return new Monster("Skeleton", Undead, Medium, playerLevel, 2, adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), 13, 
			new Weapon("Shortsword", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d6", 0), theChar);
	case 7:
		return new Monster("Wolf", Beast, Medium, playerLevel, 1, adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), 13, 
			new Weapon("Bite", 10, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "2d4", 0), theChar);
	case 8:
		return new Monster("Zombie", Undead, Medium, playerLevel, 2, adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), 8, 
			new Weapon("Slam", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d6", 0), theChar);
	case 9:
		return new Monster("Axe Beak", Beast, Large, playerLevel, 4, adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), 11, 
			new Weapon("Beak", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d8", 0), theChar);
	case 10:
		return new Monster("Giant Bat", Beast, Large, playerLevel, 4, adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), adie.roll("3d6"), 13, 
			new Weapon("Bite", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d6", 0), theChar);
	}
}
