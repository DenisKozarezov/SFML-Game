#include "Rect.h"

const bool& Rect::contains(const Rect& rectangle, const Vector2& point)
{
	float min_x = rectangle.x;
	float max_x = rectangle.x + rectangle.width;
	float min_y = rectangle.y;
	float max_y = rectangle.y + rectangle.height;
	return point.x >= min_x && point.x <= max_x && point.y >= min_y && point.y <= max_y;
}
const bool& Rect::intersects(const Rect& rectangle1, const Rect& rectangle2)
{
	return true;
}

const bool& Rect::contains(const Vector2& point)
{
	float min_x = this->x;
	float max_x = this->x + this->width;
	float min_y = this->y;
	float max_y = this->y + this->height;
	return point.x >= min_x && point.x <= max_x && point.y >= min_y && point.y <= max_y;
}
const bool& Rect::intersects(const Rect& rectangle)
{
	Vector2 r1_point1(this->x, this->y);
	Vector2 r1_point2(this->x, this->y - this->height);
	Vector2 r1_point3(this->x + this->width, this->y + this->height);
	Vector2 r1_point4(this->x + this->width, this->y);
	Vector2 rect1[] = {r1_point1, r1_point2, r1_point3, r1_point4 };

	Vector2 r2_point1(rectangle.x, rectangle.y);
	Vector2 r2_point2(rectangle.x, rectangle.y - rectangle.height);
	Vector2 r2_point3(rectangle.x + rectangle.width, rectangle.y + rectangle.height);
	Vector2 r2_point4(rectangle.x + rectangle.width, rectangle.y);
	Vector2 rect2[] = { r2_point1, r2_point2, r2_point3, r2_point4 };

	for (auto point : rect2)
	{
		if (contains(point)) return true;
		else continue;
	}
	return false;
}
