#include "Player.h"

Player::Player(std::string name)
{
	this->name = name;
}

Unit* Player::getMainCharacter()
{
	return mainCharacter;
}
