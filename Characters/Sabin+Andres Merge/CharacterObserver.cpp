#include "CharacterObserver.h"

CharacterObserver::CharacterObserver(Characters* s) 
{
	_sub = s;
	_sub->Attach(this);
};


CharacterObserver::~CharacterObserver()
{
	_sub->Dettach(this);
}

void CharacterObserver::Update()
{
	display();
}

void CharacterObserver::display()
{
	_sub->displayStats();
}
