#include "Warrior.h"

void Warrior::update()
{
	if (this->animator->currentAnimation != nullptr) this->animator->currentAnimation->play();
}

Warrior::Warrior(const Vector2& position) : Unit(position)
{
	sf::Texture texture1, texture2;
	texture1.loadFromFile(ProjectResourcesPath::Sprites + "1.jpg");
	texture2.loadFromFile(ProjectResourcesPath::Sprites + "2.jpg");
	set_texture(texture1);
	set_position(position);

	sf::Texture idle_mas[] = { texture1, texture2 };
	Animation* animation = new Animation(idle_mas, 2, this);
	animator->add("Idle", animation);
	animator->get_animation("Idle")->set_interval(1000);
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