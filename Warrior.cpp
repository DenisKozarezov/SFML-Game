#include "Warrior.h"

Warrior::Warrior(const float&x, const float&y)
{
	image->loadFromFile(ProjectResourcesPath::Sprites + sprite_name);
	image->createMaskFromColor(sf::Color::White);
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);
	sprite->setScale(0.3f, 0.3f);
	set_position(x, y);

	set_health(100);
	set_speed(1);
}

Warrior::~Warrior()
{

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