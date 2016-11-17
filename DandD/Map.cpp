#include<iostream>
#include<stdexcept>
#include "Map.h"

IMPLEMENT_SERIAL(Map, CObject, 1);

/**
* @brief Create a new map of default size (10x10)
*/
Map::Map() : sizeX(10), sizeY(10) {
	fillWithEmpty();
}

/**
* @brief Create a new map of specified size
* @param sizeX The horizontal size
* @param sizeY The vertical size
*/
Map::Map(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY) {
	fillWithEmpty();
}

/**
 * Destructor, will delete all monsters and containers, but will leave the player
 */
Map::~Map()
{
	for (int i = 0; i < monsters.size(); i++) {
		delete monsters[i];
	}

	for (int i = 0; i < containers.size(); i++) {
		delete containers[i];
	}
}

/**
* @brief Assign a specific type to a square
* @param indexX The x coordinate to assign to
* @param indexY the y coordinate to assign to
* @param symbol The specific type
*/
void Map::assignType(int indexX, int indexY, char symbol) {
	// check first to make sure within bounds
	if (indexX < 0 || indexX >= sizeX || indexY < 0 || indexY >= sizeY) {
		std::cout << "Assign type failed. Possible values : \nX\t0 - " << (sizeX - 1) << "\nY\t0 - " << (sizeY - 1);
		throw std::invalid_argument("Error: assignType() failed.");
	}
	
	map[indexX][indexY] = symbol;
}

/**
* @brief Assign a specific type to a square
* @param position A position that the character should be assigned to
* @param symbol The specific type
*/
void Map::assignType(Position position, char symbol) {
	assignType(position.x, position.y, symbol);
}

/**
* @brief Get the type of the specified square
* @param indexX The index on the x coordinates
* @param indexY The index on the y coordinates
* @return The type of square
*/
char Map::getType(int indexX, int indexY)
{
	// check first to make sure within bounds
	if (indexX < 0 || indexX >= sizeX || indexY < 0 || indexY >= sizeY) {
		std::cout << "Assign type failed. Possible values : \nX\t0 - " << (sizeX - 1) << "\nY\t0 - " << (sizeY - 1);
		throw std::invalid_argument("Error: assignType() failed.");
	}
	else {
		return map[indexX][indexY];
	}
}

char Map::getType(Position position)
{
	return getType(position.x, position.y);
}

/**
* @brief Fill the entire map with empty, free paths
*/
void Map::fillWithEmpty() {
	for (int i = 0; i < sizeX; i++) {
		vector<char> newColumn;
		map.push_back(newColumn);
		for (int j = 0; j < sizeY; j++) {
			map[i].push_back('.');
		}
	}
}

void Map::setPlayerPosition(int coordinateX, int coordinateY)
{
	if (!player) {
		player = new Fighter();
		player->MovableEntity::setPosition(coordinateX, coordinateY);
	}
	else {
		player->MovableEntity::setPosition(coordinateX, coordinateY);
	}
}

Monster * Map::getMonster(int index)
{
	if (index < monsters.size()) {
		return monsters[index];
	}
	else {
		throw "Index out of bounds.";
	}
}

void Map::addMonster(Monster * newMonster)
{
	monsters.push_back(newMonster);
}

/**
 * @brief Will add a monster appropriate to the level of the player at the specified position.
 * If player is not yet set, will set the level of the monster to be appropriate for level 1 player
 * @param coordinateX The x coordinate desired
 * @param coordinateY The y coordinate desired
 */
void Map::addMonster(int coordinateX, int coordinateY)
{
	if (player != nullptr) {
		Monster* tempMonster = MonsterFactory::createMonster(player);
		tempMonster->setPosition(coordinateX, coordinateY);
		monsters.push_back(tempMonster);
	}
	else {
		Monster* tempMonster = MonsterFactory::createMonster(new Fighter());
		tempMonster->setPosition(coordinateX, coordinateY);
		monsters.push_back(tempMonster);
	}
}

Container * Map::getContainer(int index)
{
	if (index < containers.size()) {
		return containers[index];
	}
	else {
		throw "Index out of bounds.";
	}
}

void Map::addContainer(Container * newContainer)
{
	containers.push_back(newContainer);
}

/**
* @brief Will add a container appropriate to the level of the player at the specified position.
* If player is not yet set, will set the level of the container to be appropriate for level 1 player
* @param coordinateX The x coordinate desired
* @param coordinateY The y coordinate desired
*/
void Map::addContainer(int coordinateX, int coordinateY)
{
	if (player != nullptr) {
		Container* tempContainer = ContainerGenerator::generateContainer(player);
		tempContainer->setPosition(coordinateX, coordinateY);
		containers.push_back(tempContainer);
	}
	else {
		Container* tempContainer = ContainerGenerator::generateContainer(new Fighter());
		tempContainer->setPosition(coordinateX, coordinateY);
		containers.push_back(tempContainer);
	}
}

/**
 * @brief Print the map to console
 */
void Map::printMap()
{
	for (int j = 0; j < sizeY; j++) {
		for (int i = 0; i < sizeX; i++) {
			std::cout << map[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void Map::printMapWithMovableElements()
{
	for (int j = 0; j < sizeY; j++) {
		for (int i = 0; i < sizeX; i++) {
			bool alreadyPrintedElement = false;
			// check if there's a monster at this spot
			if (!alreadyPrintedElement) {
				for (int i = 0; i < monsters.size(); i++) {
					if (monsters[i]->MovableEntity::getPosition().x == i && monsters[i]->MovableEntity::getPosition().y == j) {
						std::cout << "Z ";
						alreadyPrintedElement = true;
					}
				}
			}
			// check if there's a container at this spot
			if (!alreadyPrintedElement) {
				for (int i = 0; i < containers.size(); i++) {
					if (containers[i]->MovableEntity::getPosition().x == i && containers[i]->MovableEntity::getPosition().y == j) {
						std::cout << "C ";
						alreadyPrintedElement = true;
					}
				}
			}
			// check if there's a player at this spot
			if (!alreadyPrintedElement) {
				if (player->MovableEntity::getPosition().x == i && player->MovableEntity::getPosition().y == j) {
					std::cout << "P ";
					alreadyPrintedElement = true;
				}
			}
			// otherwise, print the actual map element
			if (!alreadyPrintedElement) {
				std::cout << map[i][j] << " ";
			}
		}
		std::cout << "\n";
	}
}

 bool Map::equals(std::shared_ptr<Map> anotherMap)
 {
	 // first check dimensions
	 if (anotherMap->getSizeX() != sizeX || anotherMap->getSizeY() != sizeY) {
		 return false;
	 }

	 // the dimensions must be the same, so go through character by character
	 for (int j = 0; j < sizeY; j++) {
		 for (int i = 0; i < sizeX; i++) {
			 if (anotherMap->getType(i, j) != getType(i, j)) {
				 return false;
			 }
		 }
	 }

	 // all characters have been checked, map must be the same
	 return true;
 }

 void Map::Serialize(CArchive & ar)
 {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << sizeX;
		ar << sizeY;
		// store map
		for (int x = 0; x < sizeX; x++) {
			for (int y = 0; y < sizeY; y++) {
				ar << map[x][y];
			}
		}
		// store the player
		player->Serialize(ar);
		// store the monsters
		ar << monsters.size();
		for (int i = 0; i < monsters.size(); i++) {
			monsters.at(i)->Serialize(ar);
		}
		// store the containers
		ar << containers.size();
		for (int i = 0; i < containers.size(); i++) {
			containers.at(i)->Serialize(ar);
		}
		// store the environment component path (theme path for the map)
		CString c_environmentComponentPath(environmentComponentPath.c_str());
		ar << c_environmentComponentPath;
	}
	else {
		ar >> sizeX;
		ar >> sizeY;
		// load map
		std::vector<std::vector<char>> tempVectorX;
		for (int x = 0; x < sizeX; x++) {
			std::vector<char> tempVectorY;
			for (int y = 0; y < sizeY; y++) {
				char tempSymbol;
				ar >> tempSymbol;
				tempVectorY.push_back(tempSymbol);
			}
			tempVectorX.push_back(tempVectorY);
		}
		map = tempVectorX;
		// load player
		Fighter * tempPlayer = new Fighter();
		tempPlayer->Serialize(ar);
		// load monsters
		int tempNumMonsters;
		ar >> tempNumMonsters;
		for (int i = 0; i < tempNumMonsters; i++) {
			Monster * tempMonster = new Monster();
			tempMonster->Serialize(ar);
			monsters.push_back(tempMonster);
		}
		// load containers
		int tempNumContainers;
		ar >> tempNumContainers;
		for (int i = 0; i < tempNumContainers; i++) {
			Container* tempContainer = new Container();
			tempContainer->Serialize(ar);
			containers.push_back(tempContainer);
		}
		// load the environment component path (theme path for the map)
		CString c_environmentComponentPath = "";
		ar >> c_environmentComponentPath;
		environmentComponentPath = "";
		int strlen = c_environmentComponentPath.GetLength();
		for (int i = 0; i < strlen; ++i) {
			environmentComponentPath += c_environmentComponentPath.GetAt(i);
		}
	}
}
