#include "filereader.h"

FileReader::FileReader()
{
}

vector<string> FileReader::getFileVector(string path)
{
	ifstream inputfile;
	vector<string> lines;
	string currentinput;
	int counter = 0;
	inputfile.open(path);
	while(inputfile >> currentinput)
	{
		lines.push_back("X");
		lines[counter] = currentinput;
		counter++;
	}
}