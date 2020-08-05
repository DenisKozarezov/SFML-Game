#include "Unit.h"

void Unit::update(sf::RenderWindow& window)
{

}

sf::Drawable* Unit::get_drawable_object()
{
	return this->get_sprite();
}

void Unit::initialize()
{	
	DrawableObject::initialize(this, 0);
	*this->get_sprite()->isMultiple = true;

	this->name = new std::string("Empty name");
	this->tag = new std::string("Empty tag");
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

	//Vector2 offset(0, -200);
	//this->gui_text = new std::map<const std::string, GUIText*>;
	//this->gui_text->insert(std::pair<const std::string, GUIText*>("Health", new GUIText(this->get_screen_position() + offset, "HEALTH")));
}

Unit::Unit(const Vector2& position)
{
	set_screen_position(position);
	set_world_position(position);
	move_sprite(position);

	initialize();
}
Unit::Unit(const float& x, const float& y)
{
	set_screen_position(Vector2(x, y));
	set_world_position(Vector2(x, y));
	move_sprite(Vector2(x, y));

	initialize();
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

	std::map<std::string, sf::Texture*>::iterator it;
	for (it = this->sprite_sheets->begin(); it != this->sprite_sheets->end(); it++)
	{
		delete it->second;
	}
	delete this->sprite_sheets;
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
Animator* Unit::get_animator() const
{
	return this->animator;
}
Collision* Unit::get_collider() const
{
	return this->collider;
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
void Unit::set_speed(const float& factor)
{
	*this->speed = factor;
}

void Unit::move(const Vector2& offset)
{
	if (*this->isMovable && !*this->isDead)
	{
		set_world_position(get_world_position() + offset * *this->speed);
		set_screen_position(get_screen_position() + offset * *this->speed);
		offset_sprite(offset);
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