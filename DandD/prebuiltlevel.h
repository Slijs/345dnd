#pragma once
#include "levels.h"
/*!
* Inherits from levels, not much specific functionalities added except
* for just loading a text file from a path and creating a graphical
* level out of it on the LevelWindow instance that it would contain
*/
class PreBuiltLevel : public Level
{
protected:
	std::vector<SDL_Rect*> _levelComponentRects;

public:
	PreBuiltLevel();
	PreBuiltLevel(std::string path);
	void loadUserCreatedLevel(std::string name);
	std::vector<SDL_Rect*> getLevelComponentRects();
	void setLevelOnTargetWindow();
	void createLevelForTargetWindow();
	std::string getEnvironmentComponentsPath() const;
	std::string getDirectoryPathForLevelTextFile() const;
	std::string getPlayerPath() const;
	std::vector<std::string> getBuiltLevelFile() const;
};