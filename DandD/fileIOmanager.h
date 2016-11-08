#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include "filepathandfoldermanager.h"
/*!
*This class is a singleton class designed to handle the text input output for the engine
*this class also complements the singleton class SingletonFilePathAndFolderManager in managing
*input output to the correct files for campaign editing, which involves
*creating, editing and deleting campaigns and maps within campaigns, also loading some prebuilt
*deafult maps if the user wants to.
*/
class SingletonInputOutputManager
{
private:
	static SingletonInputOutputManager* _IOManagerInstance;
	SingletonInputOutputManager();
public:
	std::vector<std::string> readFileLineByLine(std::string path);
	std::vector<std::string> readFileWordByWord(std::string path);
	void writeToFile(std::string path, std::vector<std::string> lines);
	std::vector<std::string> splitString(std::string toBeSplit);
	std::vector<std::string> loadAllCampaign();
	std::vector<std::string> loadONECampaign(std::string NAME);
	static SingletonInputOutputManager* getInstance();
	~SingletonInputOutputManager();
};


class RGB
{
public:
	int red;
	int green;
	int blue;
	RGB();
	RGB(const int r, const int g, const int b);
};

