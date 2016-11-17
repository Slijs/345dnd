// header guard
#ifndef Map_H
#define Map_H

#include <vector>
#include <array>
#include <memory>
#include <afx.h>
#include "Monster.h"
#include "Container.h"
#include "Fighter.h"
#include "MonsterFactory.h"
#include "ContainerGenerator.h"

using std::vector;

class Map : public CObject
{
protected:
	int sizeX;
	int sizeY;
	vector<vector<char>> map;
	Fighter* player = NULL;
	vector<Monster*> monsters;
	vector<Container*> containers;
	std::string environmentComponentPath; // This is the path to the theme that the map uses
	DECLARE_SERIAL(Map);
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
	void setPlayer(Fighter* player) { this->player = player; }
	Fighter* getPlayer() { return player; }
	void setPlayerPosition(int coordinateX, int coordinateY);
	void deletePlayer();
	void setMonsters(vector<Monster*> newMonsters) { monsters = newMonsters; }
	vector<Monster*> getMonsters() { return monsters; }
	Monster* getMonster(int index);
	void addMonster(Monster* newMonster);
	void addMonster(int coordinateX, int coordinateY);
	void removeMonster(int coordinateX, int coordinateY);
	void removeMonster(int index);
	void setContainers(vector<Container*> newContainers) { containers = newContainers; }
	vector<Container*> getContainers() { return containers; }
	Container* getContainer(int index);
	void addContainer(Container* newContainer);
	void addContainer(int coordinateX, int coordinateY);
	void removeContainer(int coordinateX, int coordinateY);
	void removeContainer(int index);
	string getEnvironmentComponentPath() { return environmentComponentPath; }
	void setEnvironmentComponentPath(string path) { environmentComponentPath = path; }
	void printMap();
	void printMapWithMovableElements();
	bool equals(std::shared_ptr<Map> anotherMap);
	virtual void Serialize(CArchive &ar);
};

#endif