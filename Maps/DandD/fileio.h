#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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

