#include "mainmenu.h"

//!parameterized constructor sets up the menu window
MainMenu::MainMenu(std::string title) : Menus(title)
{
}

//!sets up menu componenets on window renderer
void MainMenu::setupMenu()
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
	this->_menuWindow->addTextLabel("Dungeons & Dragons interim demonstration", this->_baseMenuColors[_Title_]->red,this->_baseMenuColors[_Title_]->green,this->_baseMenuColors[_Title_]->blue, menucomponent);

	menucomponent.y = menucomponent.y + menucomponent.h;
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.65);
	this->_menuWindow->addTextLabel("Program submission date: November 10th 2016", this->_baseMenuColors[_Title_]->red,this->_baseMenuColors[_Title_]->green,this->_baseMenuColors[_Title_]->blue, menucomponent);

	menucomponent.y = menucomponent.y + menucomponent.h;
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.7);
	this->_menuWindow->addTextLabel("Game developed by: Jeremiah, Sabin, Andres, Phil, Khatib.", this->_baseMenuColors[_Title_]->red,this->_baseMenuColors[_Title_]->green,this->_baseMenuColors[_Title_]->blue, menucomponent);

	/*menucomponent.y = menucomponent.y + menucomponent.h;
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.40);
	this->_menuWindow->addTextLabel("Student ID: 2 9 2 2 2 8 9 8", this->_baseMenuColors[_Title_]->red,this->_baseMenuColors[_Title_]->green,this->_baseMenuColors[_Title_]->blue, menucomponent);*/

	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.45);
	menucomponent.y = menucomponent.y + menucomponent.h;
	this->_menuWindow->addTextLabel("Course Instructor: Dr. Mohammed Taleb", this->_baseMenuColors[_Title_]->red,this->_baseMenuColors[_Title_]->green,this->_baseMenuColors[_Title_]->blue, menucomponent);

	//setup buttons
	//play campaign
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.30);
	menucomponent.x = (this->_menuWindow->getWindowWidth()/2) - (menucomponent.w / 2);
	menucomponent.y = menucomponent.y + (menucomponent.h * 6);
	this->_menuWindow->addButton("Play Campaign", this->_baseMenuColors[_NoButtonSelect_]->red,this->_baseMenuColors[_NoButtonSelect_]->green,this->_baseMenuColors[_NoButtonSelect_]->blue, menucomponent);

	//create / edit item
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.30);
	menucomponent.x = (this->_menuWindow->getWindowWidth() / 2) - (menucomponent.w / 2);
	menucomponent.y = menucomponent.y + (menucomponent.h * 2);
	this->_menuWindow->addButton("Create / Edit Item", this->_baseMenuColors[_NoButtonSelect_]->red, this->_baseMenuColors[_NoButtonSelect_]->green, this->_baseMenuColors[_NoButtonSelect_]->blue, menucomponent);


	//create / edit player
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.30);
	menucomponent.x = (this->_menuWindow->getWindowWidth()/2) - (menucomponent.w / 2);
	menucomponent.y = menucomponent.y + (menucomponent.h * 2);
	this->_menuWindow->addButton("Create / Edit Player", this->_baseMenuColors[_NoButtonSelect_]->red,this->_baseMenuColors[_NoButtonSelect_]->green,this->_baseMenuColors[_NoButtonSelect_]->blue, menucomponent);

	//Open Campaign editor
	menucomponent.w = this->_menuWindow->getWindowWidth() * (0.30);
	menucomponent.x = (this->_menuWindow->getWindowWidth()/2) - (menucomponent.w / 2);
	menucomponent.y = menucomponent.y + (menucomponent.h * 2);
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
//0 = play campaign
//1 = create / edit player
//2 = campaign manager menu
int MainMenu::destinationMap(int index)
{
	switch(index)
	{
	case 0:
		return _PlayCampaign_;

	case 1:
		return _CreateEditItems_;

	case 2:
		return _CreateEditPlayer_;

	case 3:
		return _CampaignManagerMenu_;
	}
	return _ExitToCommandPrompt_;
}
