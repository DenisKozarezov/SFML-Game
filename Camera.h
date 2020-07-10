#pragma once
#include "SFML/Graphics.hpp"
#include "Drawable.h"

class Camera
{
private:
	bool* faded = new bool(false);
	bool* isMoving = new bool(false);

	float* speed = new float(0);

	DrawableObject* target;
public:
	Camera();

	const sf::Vector2f& screen_to_world_point(const sf::Vector2f& screen_point) const;
	const sf::Vector2f& world_to_screen_point(const sf::Vector2f& world_point) const;

	void move(const sf::Vector2f& point);
	void move(const float& x, const float& y);
	void move(const sf::Vector2f& point, const float& time);

	void attach_to(DrawableObject* object);
	void detach();

	enum class Fade_state { IN, OUT };
	void fade(const Fade_state& fade_state);

	~Camera();
};

