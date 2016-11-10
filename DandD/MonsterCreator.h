#include "Monster.h"
#include "Weapon.h"

//Source: https://roll20.net/compendium/dnd5e/Monsters%20by%20Challenge%20Rating#toc_1
//Note: all speeds are in block (speed in feet/(5block/ft))

//namespace MonsterCreator
//{
	//Challenge Level 1 (1/4 in rulebook):
	//Monster* GoblinSoldier = new Monster("Goblin Soldier", Humanoid, Small, playerLevel, 2, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), 15, new Weapon("Scimitar", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d6", 0));
	//Monster* GoblinArcher = new Monster("Goblin Archer", Humanoid, Small, playerLevel, 1, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), 15, new Weapon("Shortbow", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d6", 1));
	//Monster* Grimlock = new Monster("Grimlock", Humanoid, Medium, playerLevel, 2, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), 11, new Weapon("Spiked Bone Club", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d4", 0));
	//Monster* Pseudodragon = new Monster("Pseudodragon", Dragon, Tiny, playerLevel, 3, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), 13, new Weapon("Bite", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d4", 0));
	//Monster* Sprite = new Monster("Sprite", Fey, Tiny, playerLevel, 2, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), 15, new Weapon("Longsword", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d8", 0));
	//Monster* Wolf = new Monster("Wolf", Beast, Medium, playerLevel, 1, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), 13, new Weapon("Bite", 10, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "2d4", 0));
	//Monster* Skeleton = new Monster("Skeleton", Undead, Medium, playerLevel, 2, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), 13, new Weapon("Shortsword", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d6", 0));
	//Monster* Zombie = new Monster("Zombie", Undead, Medium, playerLevel, 2, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), 8, new Weapon("Slam", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d6", 0));
	//Monster* AxeBeak = new Monster("Axe Beak", Beast, Large, playerLevel, 4, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), 11, new Weapon("Beak", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d8", 0));
	//Monster* GiantBat = new Monster("Giant Bat", Beast, Large, playerLevel, 4, _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), _theDie.roll("3d6"), 13, new Weapon("Bite", 5, 5, "assets/defaultWeapon.jpg", { { 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, "1d6", 0));
}
