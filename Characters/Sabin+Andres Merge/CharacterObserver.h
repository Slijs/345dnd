#pragma once
#include "Observer.h"
#include "Characters.h"

class CharacterObserver : public Observer
{
private:
	Characters* _sub;
public:
	CharacterObserver(Characters* s);
	~CharacterObserver();

	void Update();
	void display();
};