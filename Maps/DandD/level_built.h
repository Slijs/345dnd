#pragma once
#include "image.h"
#include <vector>
#include <fstream>
#include "sdl_window.h"
#include "gameplaygridcomponents.h"

//w = wall
//f = floors
//i = entrence
//e = water
//d = door
//q = door2
//. = blank space (just black)


class Level
{
private:
	
	std::string _path;
	std::vector<std::string> _level;
	std::vector<SDL_Image*> _environment;
	std::vector<SDL_Rect> _gameplayGrids;
	std::vector<GamePlayGridComponents*> _environment_components;

public:
	//char environmentChars[];
	Level();
	Level(std::string path);
	void createLevelForTargetWindow(SDLWindow* window);
	void setLevelOnTargetWindow(SDLWindow* window);
	void renderLevel(SDLWindow* window);
	void destroyLevel();
	std::vector<SDL_Image*> getEvironmentVector();
	std::vector<SDL_Rect> getGameplayGridsRects();
	std::vector<GamePlayGridComponents*> getEnvironmentComponents();
	void updateTextFileEnvironment(SDL_Rect gridRef, int environmentIndex, SDLWindow* window);
	void addRectToGamePlayGrids(SDL_Rect dest);
	SDL_Texture* getEnvironmentTexture(int index);
	~Level();
};

class UserLevel : public Level
{
private:
	int _Y_start;
	std::vector<SDL_Rect> levelComponentRects;

public:
	UserLevel(SDLWindow* window);
	void renderEnvironmentAtBottom(SDLWindow* window);
	std::vector<SDL_Rect> getLevelComponentRects();
	GamePlayGridComponents* getEnvironmentComponentAtIndex(int index);
	int get_Y_start();
};

class InputOutput
{
public:
	InputOutput(){
	}
	std::vector<std::string> readFileCharByChar(std::string path)
	{
		std::ifstream inputfile;
		inputfile.open(path);
		if(inputfile.is_open() == false)
		{
			std::cout<<"Could not open file, "<<path<<" exiting program."<<std::endl;
			system("pause");
			exit(-1);
		}
		std::vector<std::string> lines;
		std::string currentinput;
		int counter = 0;
		while(inputfile >> currentinput)
		{
			lines.push_back("X");
			lines[counter] = currentinput;
			counter++;
		}
		inputfile.close();
		return lines;
	}

	std::vector<std::string> readFileLineByLine(std::string path)
	{
		std::ifstream inputfile;
		inputfile.open(path);
		if(inputfile.is_open() == false)
		{
			std::cout<<"Could not open file, "<<path<<" exiting program."<<std::endl;
			system("pause");
			exit(-1);
		}
		std::vector<std::string> lines;
		std::string currentinput;
		int counter = 0;
		while(std::getline(inputfile, currentinput))
		{
			lines.push_back("X");
			lines[counter] = currentinput;
			counter++;
		}
		inputfile.close();
		return lines;
	}
};
