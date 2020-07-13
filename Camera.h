#pragma once
#include "SFML/Graphics.hpp"
#include "Drawable.h"
#include "Math.h"

class Camera
{
private:
	sf::Vector2f* position = new sf::Vector2f(0.f, 0.f);

	bool* faded = new bool(false);
	bool* moving = new bool(false);

	float* speed = new float(1);
	float* time = new float(0);

	sf::Vector2f* lerp_position = new sf::Vector2f;
	float* factor = new float(0);

	DrawableObject* attached_target;
	sf::Vector2f* point_target = new sf::Vector2f;

	void offset_move(const sf::Vector2f& offset);
	void offset_move(const float& offset_x, const float& offset_y);
public:
	Camera();
	
	void update(const double& deltaTime);

	const bool& isMoving() const;
	const bool& isFaded() const;

	const sf::Vector2f& screen_to_world_point(const sf::Vector2f& screen_point) const;
	const sf::Vector2f& world_to_screen_point(const sf::Vector2f& world_point) const;
	const sf::Vector2f& get_position() const;

	void move_to(const sf::Vector2f& point);
	void move_to(const float& x, const float& y);
	void move_to(const sf::Vector2f& point, const float& time);
	void move_to(DrawableObject* object);
	void move_to(DrawableObject* object, const float& time);

	void stop();

	void attach_to(DrawableObject* object);
	void detach();

	void set_speed(const float& value);

	enum class Fade_state { IN, OUT };
	void fade(const Fade_state& fade_state, const float& time);

	~Camera();
};

