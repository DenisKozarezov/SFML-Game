#pragma once
#include <string>
#include "Unit.h"
#include "PlayerInput.h"
#include "GUI.h"

class Player final
{
private:
	std::string* name = new std::string("Player");
	Unit* mainCharacter;

	static Player* main;

	PlayerInput* input = PlayerInput::get_instance();
public:
	Player();
	Player(Unit* mainChararcter);

	void input_update(const sf::Event& event);

	void set_main_character(Unit* unit);
	Unit* get_main_character();

	static void set_main_player(Player* player);
	static Player* get_main_player();

	~Player();
};

