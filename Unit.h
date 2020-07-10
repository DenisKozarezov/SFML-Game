#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Drawable.h"
#include "Animator.h"

class Unit : public DrawableObject
{
private:
	std::string* name = new std::string("Empty");
	std::string* tag = new std::string("Empty");

	unsigned int* health = new unsigned int(0);
	unsigned int* damage = new unsigned int(0);
	float* speed = new float(0);
	sf::Vector2f* position = new sf::Vector2f(0, 0);

	virtual void update() override;
public:
	Unit();
	sf::Sprite* get_sprite() override;
	bool* isPaused = new bool(false);
	bool* isDead = new bool(false);
	bool* isMovable = new bool(true);

	const std::string& get_name();
	const unsigned int& get_health();
	const unsigned int& get_damage();
	const float& get_speed();
	const sf::Vector2f& get_position();	
	Animator* get_animator();

	void move(const sf::Vector2f& point);
	void move(const float& x, const float& y);
	void kill();

	const Unit& operator=(const Unit& unit);	
	virtual ~Unit();
protected:
	sf::Texture* texture = new sf::Texture;
	sf::Image* image = new sf::Image;
	sf::Sprite* sprite = new sf::Sprite;

	Animator* animator = new Animator(this);

	void set_name(const std::string& name);
	void set_health(const unsigned int& value);
	void set_damage(const unsigned int& value);
	void set_speed(const float& value);
};
const bool operator==(const Unit& unit1, const Unit& unit2);
const bool operator!=(const Unit& unit1, const Unit& unit2);