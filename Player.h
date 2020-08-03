#pragma once
#include <string>
#include "Unit.h"
#include "PlayerInput.h"

class Player final
{
private:
	std::string* name = new std::string("Player");
	Unit* mainCharacter;

	PlayerInput* input = PlayerInput::get_instance();
public:
	Player();
	Player(Unit* mainChararcter);

	void input_update(const sf::Event& event);

	void set_main_character(Unit* unit);
	Unit* getMainCharacter();

	~Player();
};

