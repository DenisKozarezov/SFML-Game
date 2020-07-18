#pragma once
#include <string>
#include "Unit.h"

class Player final
{
private:
	std::string* name = new std::string("Player");
	Unit* mainCharacter;
public:
	Player();
	Player(Unit* mainChararcter);

	void input_update(const sf::Event& event);

	void set_main_character(Unit* unit);
	Unit* getMainCharacter();

	~Player();
};

