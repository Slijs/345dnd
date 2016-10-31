#pragma once
#include <string>

using namespace std;

class Equipment
{
public:

	string name;
	int weaponType;	//0 = melee 1 = range 

	Equipment();

	Equipment(string namVal, int weaponTypeVal);
	~Equipment();
};

/*Activate 'Project > Properties > Configuration Properties > C/C++ >  Code Generation > Runtime Library > Multi - threaded Debug DLL'
Go to 'Project > Properties > Configuration Properties  > C/C++ > General'.Put "D:\cppunit-1.12.1\include" in the 'Additional Include Directories' text box.
Go to 'Project > Properties > Configuration Properties  > Linker > Input'.Put "D:\cppunit-1.12.1\lib\cppunit.lib" in the 'Additional Dependences' text box.
Go to 'Project > Properties > Configuration Properties  > Build Events > Post-Build Event'.Put '"$(TargetPath)"' in the 'Command Line' textbox.Put 'Unit Tests...' in the 'Description' textbox.
*/