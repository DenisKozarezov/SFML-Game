#include "Player.h"
#include <iostream>

Player::Player()
{

}
Player::Player(Unit* mainCharacter)
{
	this->mainCharacter = mainCharacter;
}

Player::~Player()
{
	delete this->name;
}

void Player::input_update(const sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (getMainCharacter()->get_animator()->currentAnimation != getMainCharacter()->get_animator()->get_animation("Run"))
		{
			if (getMainCharacter()->IsSwappedX()) getMainCharacter()->swapX(false);

			getMainCharacter()->get_animator()->play("Run");
		}
	}
	else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D)
	{
		getMainCharacter()->get_animator()->play("Idle");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (getMainCharacter()->get_animator()->currentAnimation != getMainCharacter()->get_animator()->get_animation("Run"))
		{
			if (!getMainCharacter()->IsSwappedX()) getMainCharacter()->swapX(true);

			getMainCharacter()->get_animator()->play("Run");
		}
	}
	else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A)
	{
		getMainCharacter()->get_animator()->play("Idle");
	}
}

void Player::set_main_character(Unit* unit)
{
	this->mainCharacter = unit;
}
Unit* Player::getMainCharacter()
{
	return mainCharacter;
}
