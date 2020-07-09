#include "Unit.h"

sf::Sprite* Unit::get_sprite() const
{
	return sprite;
}

Unit::Unit()
{
	DrawableObject::initialize(this, 0);

	sf::Image image1;
	image1.loadFromFile(ProjectResourcesPath::Sprites + "owl.jpg");
	sf::Texture texture1;
	texture1.loadFromImage(image1);
	sf::Sprite sprite1;
	sprite1.setTexture(texture1);

	sf::Image image2;
	image2.loadFromFile(ProjectResourcesPath::Sprites + "owl.jpg");
	sf::Texture texture2;
	texture2.loadFromImage(image2);
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);

	sf::Sprite mas[] = {sprite1, sprite2};

	Animation* idle = new Animation(mas, 2);
	idle->set_name("Idle");
	animator->add(idle);
	animator->play("Idle");

	// hello world
}

Unit::~Unit()
{
	delete name;
	delete tag;
	delete health;
	delete mana;
	delete damage;
	delete speed;
	delete position;
	
	//delete animator;

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
const unsigned int& Unit::get_mana()
{
	return *this->mana;
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

void Unit::set_name(const std::string& name)
{
	*this->name = name;
}
void Unit::set_health(const unsigned int& value)
{
	*this->health = value;
}
void Unit::set_mana(const unsigned int& value)
{
	*this->mana = value;
}
void Unit::set_damage(const unsigned int& value)
{
	*this->damage = value;
}
void Unit::set_speed(const float& value)
{
	*this->speed = value;
}
void Unit::set_position(const float& x, const float& y)
{
	*position = sf::Vector2f(x, y);
	sprite->setPosition(*position);
}
void Unit::set_position(const sf::Vector2f& point)
{
	*position = point;
	sprite->setPosition(*position);
}

void Unit::move(const sf::Vector2f& point)
{
	if (isMovable && !isDead) set_position(point);
}
void Unit::move(const float& x, const float& y)
{
	move(sf::Vector2f(x, y));
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