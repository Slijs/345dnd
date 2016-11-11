#pragma once

#include "game_loops.h"
/*!
* Advance Program design with C++, COMP 345
* Dungeons and Dragons game interim demonstration
* Program developed by:
*	Jeremiah
*	Sabin
*	Andres
*	Phil
*	Khatib Tamal
* Course Instructor: Dr Mohammed Taleb
* Program Submission Date: 10th November 2016
*/
int main(int argc, char** argv)
{
	std::cout << "CONCORDIA UNIVERSITY DEPARTMENT OF ENGINEERING AND COMPUTER SCIENCE" << std::endl<<std::endl;
	std::cout << "Advanced Program Design with C++: COMP345" << std::endl;
	std::cout << "Dungeons and Dragons game interim demonstration" << std::endl;
	std::cout << "Program Submission Date: 10th November 2016" << std::endl;
	std::cout << "Game developed by: Jeremiah, Sabin, Andres, Phil, Khatib." << std::endl;
	std::cout << "Course Instructor: Dr Mohammed Taleb" << std::endl << std::endl;
	int success = 0;

	std::cout << "press any key to continue with demonstration." << std::endl;
	getch();
	system("cls");

	//! my gameloops class our project driver, therefore we are not driving the demonstration from main
	GameLoops* gl = new GameLoops();
	gl->loopManager();
	system("cls");

	delete gl;
	gl = nullptr;

	std::cout << "Program executed successfully, exiting with code: " << success << std::endl;
	system("pause");
	return success;
}
