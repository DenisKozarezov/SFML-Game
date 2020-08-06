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
};