#pragma once
#include <iostream>
#include "fileIOmanager.h"


using namespace std;

class GameLog
{
protected: 
	string _path;
	bool _toggle;
	
public:
	string getPath(){ return _path; }
	void log(string);

};

