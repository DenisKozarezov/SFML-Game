#include "Unit.h"
#include <iostream>

void Unit::update()
{

}

Unit::Unit(const Vector2& position)
{
	DrawableObject::initialize(this, 0);	
}
Unit::Unit(const float& x, const float& y)
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
	
	delete this->animator;

	delete this->isPaused;
	delete this->isMovable;
	delete this->isDead;
}

const std::string& Unit::get_name() const
{
	return *this->name;
}
const unsigned int& Unit::get_health() const
{
	return *this->health;
}
const unsigned int& Unit::get_damage() const
{
	return *this->damage;
}
const float& Unit::get_speed() const
{
	return *this->speed;
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

void Unit::move(const Vector2& offset)
{
	if (*this->isMovable && !*this->isDead)
	{
		set_position(get_position() + offset * *this->speed);
	}
}
void Unit::move(const float& offset_x, const float& offset_y)
{
	move(Vector2(offset_x, offset_y));
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