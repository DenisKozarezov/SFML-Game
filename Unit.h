#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "DrawableObject.h"
#include "Animator.h"
#include "Collision.h"
#include "ProjectPath.cpp"
#include "GUI.h"

class Unit : public DrawableObject
{
private:
	std::string* name;
	std::string* tag;

	unsigned int* health;
	unsigned int* damage;
	float* speed;

	void initialize();

	virtual void update(sf::RenderWindow& window) override;
	sf::Drawable* get_drawable_object() override;
public:
	Unit(const Vector2& position);
	Unit(const float& x, const float& y);
	
	bool* isPaused;
	bool* isDead;
	bool* isMovable;

	void set_name(const std::string& name);
	void set_health(const unsigned int& value);
	void set_damage(const unsigned int& value);
	void set_speed(const float& factor);

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
	Animator* animator;

	std::map<const std::string, sf::Texture*>* sprite_sheets;
	Collision* collider;

	std::map<const std::string, GUIText*>* gui_text;
};
const bool operator==(const Unit& unit1, const Unit& unit2);
const bool operator!=(const Unit& unit1, const Unit& unit2);