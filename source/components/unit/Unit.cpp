#include "Unit.h"

void Unit::update()
{

}

void Unit::initialize()
{	
	GameObject::initialize(this, 0);
	*this->get_sprite()->isMultiple = true;

	this->health = new unsigned int(0);
	this->damage = new unsigned int(0);
	this->speed = new float(0);

	this->isPaused = new bool(false);
	this->isDead = new bool(false);
	this->isMovable = new bool(true);

	this->animator = new Animator(this);

	this->sprite_sheets = new std::map<const std::string, sf::Texture*>;
	this->sprite_sheets->insert(std::pair<const std::string, sf::Texture*>("Idle", new sf::Texture));
	this->sprite_sheets->insert(std::pair<const std::string, sf::Texture*>("Run", new sf::Texture));
	this->sprite_sheets->insert(std::pair<const std::string, sf::Texture*>("Jump", new sf::Texture));	

	this->collider = new CircleCollider;
}

Unit::Unit(const Vector2& position)
{
	set_position(position);
	move(position);

	initialize();
}
Unit::Unit(const float& x, const float& y)
{
	set_position(Vector2(x, y));
	move(Vector2(x, y));

	initialize();
}

void Unit::set_health(const unsigned int& value)
{
	*this->health = value;
}
void Unit::set_damage(const unsigned int& value)
{
	*this->damage = value;
}
void Unit::set_speed(const float& factor)
{
	*this->speed = factor;
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
Animator* Unit::get_animator() const
{
	return this->animator;
}
Collision* Unit::get_collider()
{
	return this->collider;
}

const bool& Unit::IsPaused() const
{
	return *this->isPaused;
}
const bool& Unit::IsDead() const
{
	return *this->isDead;
}
const bool& Unit::IsMovable() const
{
	return *this->isMovable;
}

void Unit::move(const Vector2& position)
{
	set_position(position);
	this->get_sprite()->setPosition(position.x, position.y);
	if (this->collider) this->collider->set_position(position);
}
void Unit::move(const float& offset_x, const float& offset_y)
{
	move(Vector2(offset_x, offset_y));
}
void Unit::kill()
{
	health = 0;
	GameObject::destroy(this);
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

Unit::~Unit()
{
	delete this->health;
	delete this->damage;
	delete this->speed;
	
	delete this->animator;

	delete this->isPaused;
	delete this->isMovable;
	delete this->isDead;

	std::map<std::string, sf::Texture*>::iterator it;
	for (it = this->sprite_sheets->begin(); it != this->sprite_sheets->end(); it++)
	{
		delete it->second;
	}
	delete this->sprite_sheets;
}