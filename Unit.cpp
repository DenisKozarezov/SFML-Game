#include "Unit.h"

void Unit::update()
{

}
sf::Sprite* Unit::get_sprite()
{
	return sprite;
}

Unit::Unit()
{
	DrawableObject::initialize(this, 0);
}

Unit::~Unit()
{
	delete name;
	delete tag;
	delete health;
	delete damage;
	delete speed;
	delete position;
	
	delete animator;

	delete isPaused;
	delete isMovable;
	delete isDead;

	delete sprite;
	delete image;
	delete texture;	
}

const std::string& Unit::get_name()
{
	return *this->name;
}
const unsigned int& Unit::get_health()
{
	return *this->health;
}
const unsigned int& Unit::get_damage()
{
	return *this->damage;
}
const float& Unit::get_speed()
{
	return *this->speed;
}
const sf::Vector2f& Unit::get_position()
{
	return *this->position;
}
Animator* Unit::get_animator()
{
	return this->animator;
}

void Unit::set_name(const std::string& name)
{
	*this->name = name;
}
void Unit::set_health(const unsigned int& value)
{
	*this->health = value;
}
void Unit::set_damage(const unsigned int& value)
{
	*this->damage = value;
}
void Unit::set_speed(const float& value)
{
	*this->speed = value;
}

void Unit::move(const sf::Vector2f& offset)
{
	if (*this->isMovable && !*this->isDead)
	{
		*this->position += offset * *speed;
		this->sprite->move(offset * *speed);
	}
}
void Unit::move(const float& offset_x, const float& offset_y)
{
	move(sf::Vector2f(offset_x, offset_y));
}
void Unit::kill()
{
	health = 0;
	DrawableObject::destroy(this);
}

const Unit& Unit::operator=(const Unit& unit)
{
	return *this;
}
const bool operator==(const Unit& unit1, const Unit& unit2)
{
	return unit1 == unit2;
}
const bool operator!=(const Unit& unit1, const Unit& unit2)
{
	return !(unit1 == unit2);
}