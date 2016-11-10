#include "prebuiltlevel.h"

//!default constructor for testing purposes only
PreBuiltLevel::PreBuiltLevel()
{
	this->_player = nullptr;
}

//!parameterized constructor sets the path from which the pre built map needs to be loaded
PreBuiltLevel::PreBuiltLevel(std::string path, Fighter* player)
{
	this->_player = player;
	this->_directory_path_for_level_file_text_file = path;
}

//!loads the user created level in private member variables
void PreBuiltLevel::loadUserCreatedLevel(std::string path)
{
	//load the level and component path
	this->_level = SingletonFilePathAndFolderManager::getInstance()->loadUserGeneratedLevel(path, &this->_environmentComponentPath);

	//load the component names
	this->_environmentComponentNames = SingletonInputOutputManager::getInstance()->readFileLineByLine(this->_environmentComponentPath + SingletonFilePathAndFolderManager::getInstance()->getNameofFileContainingAssetNames());
}

//!sets the level text vector that would be used to set the level on the target window
void PreBuiltLevel::setLevelOnTargetWindow()
{
	this->_level = SingletonInputOutputManager::getInstance()->readFileLineByLine(_directory_path_for_level_file_text_file);
}

//!first creates a level window based on the level text vector
//!then calls parent function to setup the artwork on the window
void PreBuiltLevel::createLevelForTargetWindow()
{
	//make level window based on loaded text vector
	this->_level_window = new LevelWindow("PreBuilt", this->_level[0].length(), this->_level.size());

	//call parent function
	Level::createLevelForTargetWindow();

	//create button destinations
	this->_level_window->setFontType(9);
	this->_level_window->setTitleFontSize(72);

	this->_inventoryPaneDest.x = (this->_level_window->getGamePlay_X_Grids() * this->_level_window->getGridX_Length()) + (this->_level_window->getWindowWidth() - (this->_level_window->getGamePlay_X_Grids() * this->_level_window->getGridX_Length())) * 0.1;
	this->_inventoryPaneDest.y = this->_level_window->getWindowHeight() * 0.05;
	this->_inventoryPaneDest.w = (this->_level_window->getWindowWidth() - (this->_level_window->getGamePlay_X_Grids() * this->_level_window->getGridX_Length())) * 0.8;
	this->_inventoryPaneDest.h = this->_level_window->getWindowHeight() * 0.05;
	this->_level_window->addButton("Player Status", 255, 0, 0, this->_inventoryPaneDest);

	this->_movePlayerDest.x = this->_inventoryPaneDest.x;
	this->_movePlayerDest.w = this->_inventoryPaneDest.w;
	this->_movePlayerDest.h = this->_inventoryPaneDest.h;
	this->_movePlayerDest.y = this->_inventoryPaneDest.y + this->_inventoryPaneDest.h * 2;
	this->_level_window->addButton("Move Player", 255, 0, 0, this->_movePlayerDest);

	this->_interact.x = this->_inventoryPaneDest.x;
	this->_interact.w = this->_inventoryPaneDest.w;
	this->_interact.h = this->_inventoryPaneDest.h;
	this->_interact.y = this->_movePlayerDest.y + this->_inventoryPaneDest.h * 2;
	this->_level_window->addButton("Interact", 255, 0, 0, this->_interact);

	this->_exitPlay.x = this->_inventoryPaneDest.x;
	this->_exitPlay.w = this->_inventoryPaneDest.w * 0.8;
	this->_exitPlay.h = this->_inventoryPaneDest.h;
	this->_exitPlay.y = this->_interact.y + this->_inventoryPaneDest.h * 2;
	this->_level_window->addButton("Exit play", 255, 0, 0, this->_exitPlay);

	//setup the menu component
	this->_level_window->setMenuOnRenderer();
}

void PreBuiltLevel::setupContainersOnMap()
{
	ContainerOnMap* temp;
	//first find howmany an get there coordinates
	for (int y = 0; y < this->_level.size(); y++)
	{
		for (int x = 0; x < this->_level[y].size(); x++)
		{
			if (_level[y].at(x) == SimplifiedMapSymbols::_BasicContainer_)
			{
				temp = new ContainerOnMap();
				temp->stringIndex = y;
				temp->charIndex = x;
				temp->container = ContainerGenerator::generateContainer(this->_player);
				this->_containersOnMap.push_back(temp);
			}
		}
	}

	//testing if the container generation is happening properly.
	system("cls");
	std::cout << std::endl << std::endl;
	std::vector<std::string> maptemp = this->getMapSimpleVersion();
	for (int x = 0; x < maptemp.size(); x++)
	{
		std::cout << maptemp[x] << std::endl;
	}
	std::cout << std::endl;

	//now display containers details and coordinates
	for (int x = 0; x < this->_containersOnMap.size(); x++)
	{
		std::cout<<this->_containersOnMap[x]->container->contentsToString();
		std::cout << "Vector index: " << this->_containersOnMap[x]->stringIndex << std::endl;
		std::cout << "Character index: " << this->_containersOnMap[x]->charIndex << std::endl;
		std::cout << std::endl;
	}

	std::cout << "Press any key to continue\n";
	//getch();
}
std::vector<ContainerOnMap*> PreBuiltLevel::getContainersOnMap()
{
	return this->_containersOnMap;
}

//!environment component path accessor
std::string PreBuiltLevel::getEnvironmentComponentsPath() const
{
	return this->_environmentComponentPath;
}

//!level text file path accessor
std::string PreBuiltLevel::getDirectoryPathForLevelTextFile() const
{
	return this->_directory_path_for_level_file_text_file;
}

//!path for player image accessor
std::string PreBuiltLevel::getPlayerPath() const
{
	return this->_playerPath;
}

std::string PreBuiltLevel::getEnemyPath() const
{
	return this->_enemyPath;
}

//!level text vector accessor
std::vector<std::string> PreBuiltLevel::getBuiltLevelFile() const
{
	return this->_level;
}

Fighter* PreBuiltLevel::getPlayer()
{
	return this->_player;
}

std::vector<SDL_Rect> PreBuiltLevel::getAllButtonDestinations()
{
	std::vector<SDL_Rect> temp;
	temp.push_back(this->_inventoryPaneDest);
	temp.push_back(this->_movePlayerDest);
	temp.push_back(this->_exitPlay);
	return temp;
}


PreBuiltLevel::~PreBuiltLevel()
{
}