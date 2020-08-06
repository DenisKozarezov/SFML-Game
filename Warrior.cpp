#include "Warrior.h"

void Warrior::update()
{
	this->collider->update();
	if (this->animator->currentAnimation != nullptr) this->animator->currentAnimation->play();
}

Warrior::Warrior(const Vector2& position) : Unit(position)
{
	this->collider = new Collision(this);
	this->collider->add_point(Vector2(-100, -100));
	this->collider->add_point(Vector2(-100, 100));
	this->collider->add_point(Vector2(100, 100));
	this->collider->add_point(Vector2(100, -100));

	this->sprite_sheets->find("Idle")->second->loadFromFile(ProjectResourcesPath::Sprites + "idle.png");
	this->sprite_sheets->find("Run")->second->loadFromFile(ProjectResourcesPath::Sprites + "run.png");

	Animation* idle = new Animation(*this->sprite_sheets->find("Idle")->second, 6, this);
	Animation* run = new Animation(*this->sprite_sheets->find("Run")->second, 10, this);

	animator->add("Idle", idle);
	animator->add("Run", run);

	unsigned int size = this->animator->get_animation("Idle")->size();
	this->get_sprite()->set_frames_count(size);
	this->set_texture(*this->sprite_sheets->find("Idle")->second);
	this->get_sprite()->setTextureRect(sf::IntRect(0, 0, this->get_sprite()->getTexture()->getSize().x / size, this->get_sprite()->getTexture()->getSize().y));
	this->get_sprite()->setScale(1.4f, 1.4f);

	animator->get_animation("Idle")->set_interval(150);
	animator->get_animation("Run")->set_interval(100);

	this->set_speed(1.2f);

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