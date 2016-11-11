//!@file MapObserver.cpp
//!@brief Provides implementation of methods for the MapObserver class

#include "MapObserver.h"

MapObserver::MapObserver(PreBuiltLevel *toObserve){
	_theMap = toObserve;
	_theMap->attach(this);
}

MapObserver::~MapObserver(){
	_theMap->detach(this);
}

void MapObserver::Update(){

	// Render and display undated map

	//redner environment on players grid
	SDL_RenderCopy(this->_theMap->getLevelWindow()->getRenderer(), this->_theMap->_environmentForObserver->getImageDetails()->getImageTexture(), nullptr, &this->_theMap->_dest1ForObserver);

	//render player on environment grid
	SDL_RenderCopy(this->_theMap->getLevelWindow()->getRenderer(), this->_theMap->getPlayerComponent()->getImageDetails()->getImageTexture(), nullptr, &this->_theMap->_dest2ForObserver);

	//now update the window
	SDL_RenderPresent(this->_theMap->getLevelWindow()->getRenderer());

	//now update the players map
	this->_theMap->getPlayer()->setMap(&this->_theMap->getMapSimpleVersion());
}