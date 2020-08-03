#pragma once
#include "Drawable.h"
#include <vector>

class UnitEventHandler
{
private:
	typedef void(*Action)();
	Action event;
	DrawableObject* object;
public:
	UnitEventHandler(DrawableObject* object);

	UnitEventHandler* Dead;
	UnitEventHandler* Attacked;
	UnitEventHandler* Attacking;
	UnitEventHandler* Moving;

	void operator+(const Action& action);
};

