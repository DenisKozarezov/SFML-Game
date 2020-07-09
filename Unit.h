#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Drawable.h"
#include "Animator.h"

class Unit : public DrawableObject
{
private:
	#pragma region œŒÀﬂ
	std::string* name = new std::string("Empty");
	std::string* tag = new std::string("Empty");

	unsigned int* health = new unsigned int(0);
	unsigned int* mana = new unsigned int(0);
	unsigned int* damage = new unsigned int(0);
	float* speed = new float(0);
	sf::Vector2f* position = new sf::Vector2f(0, 0);


	#pragma endregion

	sf::Sprite* get_sprite() const override;
public:
	Unit();

	#pragma region —“¿“”—
	bool* isPaused = new bool(false);
	bool* isDead = new bool(false);
	bool* isMovable = new bool(true);
	#pragma endregion

	#pragma region √≈““≈–€
	const std::string& get_name();
	const unsigned int& get_health();
	const unsigned int& get_mana();
	const unsigned int& get_damage();
	const float& get_speed();
	const sf::Vector2f& get_position();	
	#pragma endregion

	#pragma region Ã≈“Œƒ€
	void move(const sf::Vector2f& point);
	void move(const float& x, const float& y);

	void kill();
	#pragma endregion

	#pragma region ”Õ¿–Õ€≈ Œœ≈–¿“Œ–€
	const Unit& operator=(const Unit& unit);	
	#pragma endregion

	virtual ~Unit();
protected:
	sf::Texture* texture = new sf::Texture;
	sf::Image* image = new sf::Image;
	sf::Sprite* sprite = new sf::Sprite;

		Animator* animator = new Animator(this);
	#pragma region —≈““≈–€
	void set_name(const std::string& name);
	void set_health(const unsigned int& value);
	void set_mana(const unsigned int& value);
	void set_damage(const unsigned int& value);
	void set_speed(const float& value);

	void set_position(const float& x, const float& y);
	void set_position(const sf::Vector2f& point);
	#pragma endregion
};
const bool operator==(const Unit& unit1, const Unit& unit2);
const bool operator!=(const Unit& unit1, const Unit& unit2);