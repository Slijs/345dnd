// header guard
#ifndef Map_H
#define Map_H

#include<vector>
#include<array>
#include<memory>
#include "MovableEntity.h"

using std::vector;

class Map
{
protected:
	int sizeX;
	int sizeY;
	vector<vector<char>> map;
	MovableEntity* player;
	vector<MovableEntity*> monsters;
	vector<MovableEntity*> containers;
public:
	Map();
	Map(int x, int y);
	~Map();
	int getSizeX() { return sizeX; }
	int getSizeY() { return sizeY; }
	void assignType(int indexX, int indexY, char symbol);
	void assignType(Position position, char symbol);
	char getType(int indexX, int indexY);
	char getType(Position position);
	void fillWithEmpty();
	void setPlayer(MovableEntity* player) { this->player = player; }
	MovableEntity* getPlayer() { return player; }
	void setMonsters(vector<MovableEntity*> newMonsters) { monsters = newMonsters; }
	vector<MovableEntity*> getMonsters() { return monsters; }
	MovableEntity* getMonster(int index);
	void addMonster(MovableEntity* newMonster);
	void setContainers(vector<MovableEntity*> newContainers) { containers = newContainers; }
	vector<MovableEntity*> getContainers() { return containers; }
	MovableEntity* getContainer(int index);
	void addContainer(MovableEntity* newContainer);
	void printMap();
	void printMapWithMovableElements();
	bool equals(std::shared_ptr<Map> anotherMap);
};

#endif