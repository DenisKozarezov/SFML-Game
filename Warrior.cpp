#include "Warrior.h"

Warrior::Warrior(const float&x, const float&y)
{
	this->image->loadFromFile(ProjectResourcesPath::Sprites + sprite_name);
	this->image->createMaskFromColor(sf::Color::White);
	this->texture->loadFromImage(*image);
	this->sprite->setTexture(*texture);
	this->sprite->setScale(0.3f, 0.3f);
	this->sprite->setPosition(x, y);

	set_health(100);
	set_speed(25);
}

Warrior::~Warrior()
{

}

void Warrior::update()
{
	this->animator->currentAnimation->play();
}

const Warrior& Warrior::operator=(const Warrior& unit)
{
	return *this;
}
const bool operator==(const Warrior& unit1, const Warrior& unit2)
{
	return unit1 == unit2;
}
const bool operator!=(const Warrior& unit1, const Warrior& unit2)
{
	return !(unit1 == unit2);
}