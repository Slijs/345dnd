/**
*@file Observer.h
*@brief Interface for the Observer class.
*
*<p>An Observer is an abstract version of a 'View' in the MVC model. Outlined here
*   is a sole virtual method, update(), which instructs the Observer to update its
*	information regarding its Subjects state.
*/
#pragma once

//!Abstract Class used for Observer Pattern 

class Observer
{
protected:
	Observer();
public:
	~Observer();
	virtual void Update() = 0;
};
