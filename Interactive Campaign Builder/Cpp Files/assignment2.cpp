#include "assignment2.h"

//!parameterized constructor sets up the menu window
Assignment2Menu::Assignment2Menu(std::string title) : Menus(title)
{
}

//!sets up menu componenets on window renderer
void Assignment2Menu::setupMenu()
{
	SDL_Rect menucomponent;
	//set menu rectangle for title
	menucomponent.x = 30;
	menucomponent.y = 30;
	
	menucomponent.h = this->_menuWindow->getWindowHeight() * (0.04);
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.65);

	std::cout<<menucomponent.x<<" "<<menucomponent.y<<std::endl;

	//set menu font type
	this->_menuWindow->setFontType(9);

	//set menu background color
	this->_baseMenuColors[_MenuBackground_]->red;
	this->_menuWindow->setBackgroudColor(this->_baseMenuColors[_MenuBackground_]->red,this->_baseMenuColors[_MenuBackground_]->green,this->_baseMenuColors[_MenuBackground_]->blue);
	
	//setup title
	this->_menuWindow->setTitleFontSize(500);
	this->_menuWindow->setTitle("Advanced Program Design W ith C++: COMP345", this->_baseMenuColors[_Title_]->red,this->_baseMenuColors[_Title_]->green,this->_baseMenuColors[_Title_]->blue, menucomponent);

	//setup follow up text
	menucomponent.y = menucomponent.y + menucomponent.h;
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.8);
	this->_menuWindow->addTextLabel("Assignment 2 : Dungeons & Dragons Campaign Editor Engine", this->_baseMenuColors[_Title_]->red,this->_baseMenuColors[_Title_]->green,this->_baseMenuColors[_Title_]->blue, menucomponent);

	menucomponent.y = menucomponent.y + menucomponent.h;
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.65);
	this->_menuWindow->addTextLabel("Assignment submission date: November 4th 2016", this->_baseMenuColors[_Title_]->red,this->_baseMenuColors[_Title_]->green,this->_baseMenuColors[_Title_]->blue, menucomponent);

	menucomponent.y = menucomponent.y + menucomponent.h;
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.4);
	this->_menuWindow->addTextLabel("Program developed by: Khatib Tamal", this->_baseMenuColors[_Title_]->red,this->_baseMenuColors[_Title_]->green,this->_baseMenuColors[_Title_]->blue, menucomponent);

	menucomponent.y = menucomponent.y + menucomponent.h;
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.40);
	this->_menuWindow->addTextLabel("Student ID: 2 9 2 2 2 8 9 8", this->_baseMenuColors[_Title_]->red,this->_baseMenuColors[_Title_]->green,this->_baseMenuColors[_Title_]->blue, menucomponent);

	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.45);
	menucomponent.y = menucomponent.y + menucomponent.h;
	this->_menuWindow->addTextLabel("Course Instructor: Dr. Mohammed Taleb", this->_baseMenuColors[_Title_]->red,this->_baseMenuColors[_Title_]->green,this->_baseMenuColors[_Title_]->blue, menucomponent);

	//setup buttons
	//Open Campaign editor
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.30);
	menucomponent.x = (this->_menuWindow->getWindowWidth()/2) - (menucomponent.w / 2);
	menucomponent.y = menucomponent.y + (menucomponent.h * 6);
	this->_menuWindow->addButton("Create / Edit Campaign", this->_baseMenuColors[_NoButtonSelect_]->red,this->_baseMenuColors[_NoButtonSelect_]->green,this->_baseMenuColors[_NoButtonSelect_]->blue, menucomponent);
	
	//exit engine
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.30);
	menucomponent.x = (this->_menuWindow->getWindowWidth()/2) - (menucomponent.w / 2);
	menucomponent.y = menucomponent.y + (menucomponent.h * 2);
	this->_menuWindow->addButton("Exit Engine", this->_baseMenuColors[_NoButtonSelect_]->red,this->_baseMenuColors[_NoButtonSelect_]->green,this->_baseMenuColors[_NoButtonSelect_]->blue, menucomponent);

	//setup menu renderer and display
	this->_menuWindow->setMenuOnRenderer();
	this->_menuWindow->displayWindow();
}

//!maps destination based on the index of what button was clicked
int Assignment2Menu::destinationMap(int index)
{
	switch(index)
	{
	case 0:
		return _CampaignManagerMenu_;
	}
	return _ExitToCommandPrompt_;
}
