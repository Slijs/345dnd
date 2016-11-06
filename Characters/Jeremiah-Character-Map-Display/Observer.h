/**
*@file Observer.h
*@brief Interface for the Observer class.
*
*<p>An Observer is an abstract version of a 'View' in the MVC model. Outlined here
*   is a sole virtual method, update(), which instructs the Observer to update its
*	information regarding its Subjects state.
*/

#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H

/**
*@Class Observer
*@brief Definition of an abstract Observer.
*<p>An observer keeps track of an object's state. Whenever the state of the object is updated,
*   the observer updates itself and carries out the necessary steps.
*/
class Observer {
public:
	//! Will tell the Observer to update its information regarding the state of its subject.
	virtual void update(int flag) = 0;

	//! Destructor for the Observer Class
	virtual ~Observer() {};
protected:

	//! Constructor for the Observer class
	Observer() {};
};

#endif
