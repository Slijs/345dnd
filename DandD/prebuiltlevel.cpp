#include "prebuiltlevel.h"

//!default constructor for testing purposes only
PreBuiltLevel::PreBuiltLevel()
{
}

//!parameterized constructor sets the path from which the pre built map needs to be loaded
PreBuiltLevel::PreBuiltLevel(std::string path)
{
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

//!level text vector accessor
std::vector<std::string> PreBuiltLevel::getBuiltLevelFile() const
{
	return this->_level;
}