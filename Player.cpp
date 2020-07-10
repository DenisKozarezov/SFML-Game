#include "Player.h"

Player::Player(Unit* mainCharacter)
{
	this->mainCharacter = mainCharacter;
}

Player::~Player()
{
	delete this->name;
}

Unit* Player::getMainCharacter()
{
	return mainCharacter;
}
