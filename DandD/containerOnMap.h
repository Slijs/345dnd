#if !defined (CONTAINER_ON_MAP_H)
#define CONTAINER_ON_MAP_H
#include "Container.h"
/*!
*a structure just to track what would be the coordinates of the containers on the gameplay map
*/
struct ContainerOnMap
{
	Container* container;
	int stringIndex;
	int charIndex;
};

#endif