#pragma once
#include "SFML/Graphics.hpp"
#include "DrawableContainer.h"
#include "Math.h"
#include "Vector2.h"

class Camera
{
private:
	friend class Game;

	bool* faded;
	bool* moving;

	Vector2* position;
	float* speed;
	float* time;

	Vector2* lerp_position;
	float* factor;

	DrawableObject* attached_target;
	Vector2* point_target;

	void move(const Vector2& point);
	void move(const float& point_x, const float& offset_y);
public:
	Camera();
	
	void update(const double& deltaTime);
	void input_update(const sf::RenderWindow& window);

	const bool& isMoving() const;
	const bool& isFaded() const;

	const static Vector2& screen_to_world_point(const Vector2& screen_point);
	const static Vector2& world_to_screen_point(const Vector2& world_point);

	const Vector2& get_position() const;
	const float& get_speed() const;

	void move_to(const Vector2& point);
	void move_to(const float& x, const float& y);
	void move_to(const Vector2& point, const float& time);

	void stop();

	void attach_to(DrawableObject* object);
	void detach();

	void set_speed(const float& value);

	enum class Fade_state { IN, OUT };
	void fade(const Fade_state& fade_state, const float& time);

	~Camera();
};

