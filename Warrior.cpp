#include "Warrior.h"

void Warrior::update()
{
	if (this->animator->currentAnimation != nullptr) this->animator->currentAnimation->play();
}

Warrior::Warrior(const Vector2& position) : Unit(position)
{
	this->sprite_sheets->find("Idle")->second->loadFromFile(ProjectResourcesPath::Sprites + "idle.png");
	this->set_texture(*this->sprite_sheets->find("Idle")->second);
	this->get_sprite()->setTextureRect(sf::IntRect(0, 0, this->get_texture()->getSize().x / 6, this->get_texture()->getSize().y));
	this->get_sprite()->setScale(1.4f, 1.4f);

	Animation* animation = new Animation(*this->sprite_sheets->find("Idle")->second, 6, this);
	animator->add("Idle", animation);
	animator->get_animation("Idle")->set_interval(150);
	animator->play("Idle");
}

Warrior::Warrior(const float&x, const float&y) : Unit(x, y)
{
	
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