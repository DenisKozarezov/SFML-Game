#pragma once
#include "Vector2.h"

struct Rect
{
public:
	float x, y, width, height;

	Rect(const Vector2& position, const Vector2& size)
	{
		this->x = position.x;
		this->y = position.y;
		this->width = size.x;
		this->height = size.y;
	}
	Rect(const float& x, const float& y, const float& width, const float& height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	const static bool& contains(const Rect& rectangle, const Vector2& point);
	const static bool& intersects(const Rect& rectangle1, const Rect& rectangle2);

	const bool& contains(const Vector2& point);
	const bool& intersects(const Rect& rectangle);
};