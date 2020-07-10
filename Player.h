#pragma once
#include <string>
#include "Unit.h"
class Player final
{
private:
	std::string name = "Player";
	Unit* mainCharacter;
public:
	Player(Unit* mainChararcter);

	Unit* getMainCharacter();
};

