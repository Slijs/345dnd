#pragma once
#include <iostream>
using namespace std;

class GameLog
{
protected: 
	string _path;
	bool _toggle;
public:
	void log(string);

};