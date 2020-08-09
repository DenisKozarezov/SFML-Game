#include "Player.h"

Player* Player::main = 0;
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
	if (!GUI::IsFocused())
	{
		if (sf::Keyboard::isKeyPressed(input->Right()) && !sf::Keyboard::isKeyPressed(input->Left()))
		{
			if (this->mainCharacter->get_animator()->currentAnimation != this->mainCharacter->get_animator()->get_animation("Run"))
			{
				if (this->mainCharacter->IsSwappedX()) this->mainCharacter->swapX(false);

				this->mainCharacter->get_animator()->play("Run");
			}
			this->mainCharacter->set_velocity(Vector2::right * this->mainCharacter->get_speed());
			this->mainCharacter->move(Vector2::right * this->mainCharacter->get_speed());
		}
		else if (event.type == sf::Event::KeyReleased && event.key.code == input->Right())
		{
			this->mainCharacter->set_velocity(Vector2(0, this->mainCharacter->get_velocity().y));
			this->mainCharacter->get_animator()->play("Idle");
		}

		if (sf::Keyboard::isKeyPressed(input->Left()) && !sf::Keyboard::isKeyPressed(input->Right()))
		{
			if (this->mainCharacter->get_animator()->currentAnimation != this->mainCharacter->get_animator()->get_animation("Run"))
			{
				if (!this->mainCharacter->IsSwappedX()) this->mainCharacter->swapX(true);

				this->mainCharacter->get_animator()->play("Run");
			}
			this->mainCharacter->set_velocity(Vector2::left * this->mainCharacter->get_speed());
			this->mainCharacter->move(Vector2::left * this->mainCharacter->get_speed());
		}
		else if (event.type == sf::Event::KeyReleased && event.key.code == input->Left())
		{
			this->mainCharacter->set_velocity(Vector2(0, this->mainCharacter->get_velocity().y));
			this->mainCharacter->get_animator()->play("Idle");
		}
	}
}

void Player::set_main_character(Unit* unit)
{
	this->mainCharacter = unit;
}
Unit* Player::get_main_character()
{
	return mainCharacter;
}

void Player::set_main_player(Player* player)
{
	main = player;
}

Player* Player::get_main_player()
{
	return main;
}
