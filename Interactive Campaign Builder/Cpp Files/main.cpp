#include <cppunit\CompilerOutputter.h>
#include <cppunit\extensions\TestFactoryRegistry.h>
#include <cppunit\ui\text\TestRunner.h>
#pragma once

#include "game_loops.h"
/*!
* Advance Program design with C++, COMP 345
* Assignment 2: Dungeons and Dragons Interactive Campaign editor engine
* Program developed by: Khatib Tamal, ID 29222898
* Course Instructor: Dr Mohammed Taleb
* Assignment Submission Date: 6th November 2016
*/
int main(int argc, char** argv)
{
	std::cout << "CONCORDIA UNIVERSITY DEPARTMENT OF ENGINEERING AND COMPUTER SCIENCE" << std::endl<<std::endl;
	std::cout << "Advanced Program Design with C++: COMP345" << std::endl;
	std::cout << "Assignment 2: Dungeons and Dragons Interactive Campaign editor engine" << std::endl;
	std::cout << "Assignment submission date: November 6, 2016" << std::endl;
	std::cout << "Engine developed by: Khatib Tamal, ID 29222898" << std::endl;
	std::cout << "Course Instructor: Dr Mohammed Taleb" << std::endl << std::endl;
	system("pause");

	std::cout << "Running CPP Unit Test" << std::endl;

	// Get the top level suite from the registry
	CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

	// Adds the test to the list of test to run
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);

	// Change the default outputter to a compiler error format outputter
	runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(),
		std::cerr));
	// Run the tests.
	bool wasSucessful = runner.run();


	// Return error code 1 if the one of test failed.
	int success = wasSucessful ? 0 : 1;
	if (success == 1)
	{
		std::cout << "cpp unit test failed exiting program with code: " << success << std::endl;
		getch();
			return success;
	}

	std::cout << "Cpp unit test sucessfull!, press any key to continue with testing engine." << std::endl;
	getch();
	system("cls");

	//! my gameloops class is technically my project driver, therefore I am not driving the assignment from main
	GameLoops* gl = new GameLoops();
	gl->loopManager();
	system("cls");

	delete gl;
	gl = nullptr;


	std::cout << "Program executed successfully, exiting with code: " << success << std::endl;
	system("pause");
	return success;
}
