#include "Monster.h"

//Source: https://roll20.net/compendium/dnd5e/Monsters%20by%20Challenge%20Rating#toc_1
//Note: all speeds are in block (speed in feet/(5block/ft))

namespace MonsterCreator
{
	//Challenge Level 1 (1/4 in rulebook):
	Monster* GoblinSoldier = new Monster("Goblin Soldier", Humanoid, Small, 1, 6, 8, 14, 10, 10, 8, 8, 15, new Weapon("Scimitar", "1d6", "Melee"));
	Monster* GoblinArcher = new Monster("Goblin Archer", Humanoid, Small, 1, 6, 8, 14, 10, 10, 8, 8, 15, new Weapon("Shortbow", "1d6", "Ranged"));
	Monster* Grimlock = new Monster("Grimlock", Humanoid, Medium, 1, 6, 16, 12, 12, 9, 8, 6, 11, new Weapon("Spiked Bone Club", "1d4", "Melee"));
	Monster* Pseudodragon = new Monster("Pseudodragon", Dragon, Tiny, 2, 12, 6, 15, 13, 10, 12, 10, 13, new Weapon("Bite", "1d4", "Melee"));
	Monster* Sprite = new Monster("Sprite", Fey, Tiny, 1, 8, 3, 18, 10, 14, 13, 11, 15, new Weapon("Longsword", "1d8", "melee"));
	Monster* Wolf = new Monster("Wolf", Beast, Medium, 2, 4, 12, 15, 12, 3, 12, 6, 13, new Weapon("Bite", "2d4", "Melee"));
	Monster* Skeleton = new Monster("Skeleton", Undead, Medium, 2, 6, 10, 14, 15, 6, 8, 5, 13, new Weapon("Shortsword", "1d6", "Melee"));
	Monster* Zombie = new Monster("Zombie", Undead, Medium,2, 4, 13, 6, 16, 3, 6, 5, 8, new Weapon("Slam", "1d6", "Melee"));

	Monster* AxeBeak = new Monster("Axe Beak", Beast, Large, 3, 10, 14, 12, 12, 2, 10, 5, 11, new Weapon("Beak", "1d8", "Melee"));
	Monster* GiantBat = new Monster("Giant Bat", Beast, Large, 4, 12, 15, 16, 11, 2, 12, 6, 13, new Weapon("Bite", "1d6", "Melee"));

	//Challenge Level 2 (1/2 in rulebook)
	Monster* BlackBear = new Monster("Black Bear", Beast, Medium, 3, 8, 15, 10, 14, 2, 12, 7, 11, new Weapon("Claws", "2d4", "Melee"));


}
