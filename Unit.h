#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Drawable.h"
#include "Animator.h"
#include "Collision.h"

class Unit : public DrawableObject
{
private:
	std::string* name = new std::string("Empty name");
	std::string* tag = new std::string("Empty tag");

	unsigned int* health = new unsigned int(0);
	unsigned int* damage = new unsigned int(0);
	float* speed = new float(0);

	void initialize();

	virtual void update() override;
public:
	Unit(const Vector2& position);
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
	Animator* get_animator() const;
	Collision* get_collider() const;

	void move(const Vector2& point);
	void move(const float& x, const float& y);
	void kill();

	const Unit& operator=(const Unit& unit);	

	virtual ~Unit();
protected:
	Animator* animator = new Animator(this);

	std::map<std::string, sf::Texture*>* sprite_sheets = new std::map<std::string, sf::Texture*>;
	Collision* collider;
};
const bool operator==(const Unit& unit1, const Unit& unit2);
const bool operator!=(const Unit& unit1, const Unit& unit2);