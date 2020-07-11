#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Drawable.h"
#include "Animator.h"

class Unit : public DrawableObject
{
private:
	std::string* name = new std::string("Empty name");
	std::string* tag = new std::string("Empty tag");

	unsigned int* health = new unsigned int(0);
	unsigned int* damage = new unsigned int(0);
	float* speed = new float(0);

	virtual void update() override;
public:
	Unit(const sf::Vector2f& position);
	Unit(const float& x, const float& y);
	
	bool* isPaused = new bool(false);
	bool* isDead = new bool(false);
	bool* isMovable = new bool(true);

	void set_name(const std::string& name);
	void set_health(const unsigned int& value);
	void set_damage(const unsigned int& value);
	void set_speed(const float& value);

	const std::string& get_name() const;
	const unsigned int& get_health() const;
	const unsigned int& get_damage() const;
	const float& get_speed() const;
	Animator* get_animator();

	void move(const sf::Vector2f& point);
	void move(const float& x, const float& y);
	void kill();

	const Unit& operator=(const Unit& unit);	

	virtual ~Unit();
protected:
	Animator* animator = new Animator(this);
};
const bool operator==(const Unit& unit1, const Unit& unit2);
const bool operator!=(const Unit& unit1, const Unit& unit2);