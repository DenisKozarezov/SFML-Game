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
		Vector2 velocity = this->mainCharacter->get_velocity();

		if (sf::Keyboard::isKeyPressed(input->Right()) && !sf::Keyboard::isKeyPressed(input->Left()))
		{
			if (this->mainCharacter->get_animator()->currentAnimation != this->mainCharacter->get_animator()->get_animation("Run"))
			{
				//if (!this->mainCharacter->IsSwappedX()) this->mainCharacter->swapX(false);
				this->mainCharacter->get_animator()->play("Run");
			}
			velocity.x = Vector2::right.x * this->mainCharacter->get_speed();
			this->mainCharacter->set_velocity(velocity);
		}
		else if (event.type == sf::Event::KeyReleased && event.key.code == input->Right())
		{
			velocity.x = 0;
			this->mainCharacter->set_velocity(velocity);
			this->mainCharacter->get_animator()->play("Idle");
		}

		if (sf::Keyboard::isKeyPressed(input->Left()) && !sf::Keyboard::isKeyPressed(input->Right()))
		{
			if (this->mainCharacter->get_animator()->currentAnimation != this->mainCharacter->get_animator()->get_animation("Run"))
			{
				//if (!this->mainCharacter->IsSwappedX()) this->mainCharacter->swapX(true);
				this->mainCharacter->get_animator()->play("Run");
			}
			velocity.x = Vector2::left.x * this->mainCharacter->get_speed();
			this->mainCharacter->set_velocity(velocity);
		}
		else if (event.type == sf::Event::KeyReleased && event.key.code == input->Left())
		{
			velocity.x = 0;
			this->mainCharacter->set_velocity(velocity);
			this->mainCharacter->get_animator()->play("Idle");
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			velocity.y = Vector2::up.y * this->mainCharacter->get_speed();
			this->mainCharacter->set_velocity(velocity);
		}
		else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)
		{
			velocity.y = 0;
			this->mainCharacter->set_velocity(velocity);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			velocity.y = Vector2::down.y * this->mainCharacter->get_speed();
			this->mainCharacter->set_velocity(velocity);
		}
		else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S)
		{
			velocity.y = 0;
			this->mainCharacter->set_velocity(velocity);
		}

		if (velocity != Vector2::zero)
		{			
			this->mainCharacter->move(this->mainCharacter->get_position() + this->mainCharacter->get_velocity());
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
