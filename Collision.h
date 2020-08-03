#pragma once
#include "Vector2.h"
#include "Drawable.h"

class Collision final
{
private:
	Vector2* points = new Vector2[50];
	Vector2* offsets = new Vector2[50];
	unsigned int* size = new unsigned int(0);

	bool* isTrigger = new bool(false);
	bool* enabled = new bool(true);
public:
	DrawableObject* object;

	explicit Collision() = default;
	explicit Collision(Vector2 points[], DrawableObject* object);
	explicit Collision(DrawableObject* object);

	const bool& IsTrigger() const;
	const bool& IsEnabled() const;

	void update();
	void draw(sf::RenderWindow& window);

	void add_point(const Vector2& offset);
	void remove_point(const unsigned int& index);
	void set_trigger(const bool& status);
	void set_enabled(const bool& status);
	void rotate(const float& angle);
	const bool& intersects(const Collision& collision);
	const bool& contains(const Vector2& point);

	~Collision();
};
const bool& operator==(const Collision& collision1, const Collision& collision2);
const bool& operator!=(const Collision& collision1, const Collision& collision2);

