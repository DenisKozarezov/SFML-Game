#pragma once
#include "GameObject.h"
#include <vector>

class UnitEventHandler
{
private:
	typedef void(*Action)();
	Action event;
	GameObject* object;
public:
	UnitEventHandler(GameObject* object);

	UnitEventHandler* Dead;
	UnitEventHandler* Attacked;
	UnitEventHandler* Attacking;
	UnitEventHandler* Moving;

	void operator+(const Action& action);
};

