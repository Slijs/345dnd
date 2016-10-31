//! @file 
//! @brief Driver file to create and execute the test suite 
//!
//! Brief instruction on how to set CppUnit:
//! from: http ://www.comp.nus.edu.sg/~cs3215/tools/cppunitAll.html
//!
//!	First, to install cppUnit :
//!
//!	 1. Unpack the CppUnit archive (https://sourceforge.net/projects/cppunit/files/cppunit/1.12.1/) to a directory of your choice, in this example I assume it is D:\. 
//!  2. Go to D:/cppunit-1.12.1/src and open the CppUnitLibraries.dsw in Visual Studio.
//!  3. Select the cppunit project in the Solution Explorer and go to 'Project > Properties > Configuration Properties > Librarian > General. Put "Debug\cppunit.lib" in the �Output File� textbox. 
//!  4. Right-click on the cppunit project in the Solution Explorer pane and choose Build.
//!  5. After successful compilation, D:/cppunit-1.12.1/lib/cppunit.lib is produced which you then need to setup the Visual Studio Linker with (see below).

//!
//! To setup a project from scratch for Compilation / Linking:
//!
//!	  1. Activate 'Project > Properties > C/C++ >  Code Generation > Runtime Library > Multi - threaded Debug DLL'
//!	  2. Go to 'Project > Properties > C/C++ > General'. Put "D:\cppunit-1.12.1\include" in the 'Additional Include Directories' text box.
//!	  3. Go to 'Project > Properties > Linker > Input'. Put "D:\cppunit-1.12.1\lib\cppunit.lib" in the 'Additional Dependences' text box.
//!	  4. Go to 'Project > Properties > Build Events > Post-Build Event'. Put '"$(TargetPath)"' in the 'Command Line' textbox.Put 'Unit Tests...' in the 'Description' textbox.

// cppUnit includes
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

// my includes
#include <iostream>
#include <vector>
#include <memory>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Belt.h"
#include "Boots.h"
#include "Helmet.h"
#include "Ring.h"
#include "Shield.h"
#include "Container.h"

using std::cout;
using std::endl;
using std::vector;
//#include "stdafx.h"

//! main() function. Entry point of the program
//! It does the following: 
//! 1. Create a test suite object from the registry as populated by the code in the Test Classes
//! 2. Create a test runner that will execute all the tests in the registry
//! 3. (optionally) sets an outputter that will output the results
//! 4. Run the test cases. 
int main(int argc, char* argv[])
{
  // Get the top level suite from the registry
  CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( suite );

  // Change the default outputter to a compiler error format outputter
  runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
                                                       std::cerr ) );
  // Run the tests.
  bool wasSucessful = runner.run();

  getchar();

  // Return error code 1 if the one of test failed.
  //return wasSucessful ? 0 : 1;

  // If the tests weren't successful, exit with an error code.
  // Otherwise, keep on going
  if (!wasSucessful) {
	  return 1;
  }

  Item *myItem = new Item("Water Balloon", 4, 1, "NopeNotYet", { 1, 2, 3, 4, 5, 4, 3, 2, 1 });

  Weapon *myWeapon = new Weapon();

  Armor *myArmor = new Armor("Chainmail", 12, 52, "/home/pbrink/Pictures/puppy.jpg", { 0,0,0,0,0,0,5,0,0 }, 8);

  cout << endl;

  cout << myItem->toString();

  cout << myWeapon->toString();

  cout << myArmor->toString();

  vector<Item *> myItems;
  myItems.push_back(myItem);
  myItems.push_back(myWeapon);
  myItems.emplace_back(myArmor);

  cout << myItems[2]->toString();

  cout << std::endl;

  int someVariable = 5;

  Container *myContainer = new Container(4, myItems);
  cout << myContainer->toString();
  cout << myContainer->contentsToString();

  return 0;
}