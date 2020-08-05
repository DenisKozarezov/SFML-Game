#pragma once

struct Rect
{
public:
	float x, y, width, height;

	Rect(const float& x, const float& y, const float& width, const float& height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
};