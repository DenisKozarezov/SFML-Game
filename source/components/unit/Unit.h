#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "../game object/GameObject.h"
#include "../animation/Animator.h"
#include "../collision/Collision.h"
#include "../../../ProjectPath.h"
#include "../collision/CircleCollider.h"

class Unit : public GameObject
{
private:
	unsigned int* health;
	unsigned int* damage;
	float* speed;

	bool* isPaused;
	bool* isDead;
	bool* isMovable;

	void initialize();

	virtual void update() override;
public:
	Unit(const Vector2& position);
	Unit(const float& x, const float& y);
	
	void set_health(const unsigned int& value);
	void set_damage(const unsigned int& value);
	void set_speed(const float& factor);

	const unsigned int& get_health() const;
	const unsigned int& get_damage() const;
	const float& get_speed() const;
	Animator* get_animator() const;
	Collision* get_collider();

	const bool& IsPaused() const;
	const bool& IsDead() const;
	const bool& IsMovable() const;

	void move(const Vector2& position) override;
	void move(const float& x, const float& y);
	void kill();

	const Unit& operator=(const Unit& unit);	

	virtual ~Unit();
protected:
	Animator* animator;
	CircleCollider* collider;
	std::map<const std::string, sf::Texture*>* sprite_sheets;
};
const bool operator==(const Unit& unit1, const Unit& unit2);
const bool operator!=(const Unit& unit1, const Unit& unit2);