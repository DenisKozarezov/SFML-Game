#include "Player.h"

Player::Player(Unit* mainCharacter)
{
	this->mainCharacter = mainCharacter;
}

Unit* Player::getMainCharacter()
{
	return mainCharacter;
}
