#include "MapController.h"
#include "filepathandfoldermanager.h"

MapController* MapController::_mapController = nullptr;

MapController::MapController()
{
	_path = SingletonFilePathAndFolderManager::getInstance()->_path_to_mapController;
	SingletonInputOutputManager::getInstance()->clearFile(_path);
}

MapController* MapController::getInstance()
{
	if (_mapController == nullptr)
		_mapController = new MapController();
	return _mapController;
}

MapController::~MapController()
{
	delete _mapController;
	_mapController = nullptr;
}