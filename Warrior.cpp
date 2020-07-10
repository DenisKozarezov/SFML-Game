#include "Warrior.h"

Warrior::Warrior(const float&x, const float&y)
{
	get_image()->loadFromFile(ProjectResourcesPath::Sprites + sprite_name);
	get_image()->createMaskFromColor(sf::Color::White);
	get_texture()->loadFromImage(*this->get_image());
	get_sprite()->setTexture(*this->get_texture());
	this->get_sprite()->setScale(0.3f, 0.3f);
	this->get_sprite()->setPosition(x, y);

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