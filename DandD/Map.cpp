#include<iostream>
#include<stdexcept>
#include "Map.h"

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

MovableEntity * Map::getMonster(int index)
{
	if (index < monsters.size()) {
		return monsters[index];
	}
	else {
		throw "Index out of bounds.";
	}
}

void Map::addMonster(MovableEntity * newMonster)
{
	monsters.push_back(newMonster);
}

MovableEntity * Map::getContainer(int index)
{
	if (index < containers.size()) {
		return containers[index];
	}
	else {
		throw "Index out of bounds.";
	}
}

void Map::addContainer(MovableEntity * newContainer)
{
	containers.push_back(newContainer);
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
					if (monsters[i]->getPosition().x == i && monsters[i]->getPosition.y == j) {
						std::cout << "Z ";
						alreadyPrintedElement = true;
					}
				}
			}
			// check if there's a container at this spot
			if (!alreadyPrintedElement) {
				for (int i = 0; i < containers.size(); i++) {
					if (containers[i]->getPosition().x == i && containers[i]->getPosition.y == j) {
						std::cout << "C ";
						alreadyPrintedElement = true;
					}
				}
			}
			// check if there's a player at this spot
			if (!alreadyPrintedElement) {
				if (player->getPosition().x == i && player->getPosition.y == j) {
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
