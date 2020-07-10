#include "Unit.h"

void Unit::update()
{

}

Unit::Unit()
{
	DrawableObject::initialize(this, 0);
}

Unit::~Unit()
{
	delete this->name;
	delete this->tag;
	delete this->health;
	delete this->damage;
	delete this->speed;
	delete this->position;
	
	delete this->animator;

	delete this->isPaused;
	delete this->isMovable;
	delete this->isDead;

	delete this->get_sprite();
	delete this->get_image();
	delete this->get_texture();
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
		get_sprite()->move(offset * *speed);
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