#include "Collision.h"
#include <iostream>

Collision::Collision(DrawableObject* object)
{
	this->object = object;
}
Collision::Collision(Vector2 points[], DrawableObject* object)
{
	this->offsets = points;
	this->object = object;
}

const bool& Collision::IsTrigger() const
{
	return *this->isTrigger;
}
const bool& Collision::IsEnabled() const
{
	return *this->enabled;
}

void Collision::update()
{
	if (this->size > 0)
	{
		for (int i = 0; i < *this->size; i++)
		{
			this->points[i] = this->object->get_world_position() + this->offsets[i];
		}
	}
}

void Collision::add_point(const Vector2& offset)
{
	this->offsets[*this->size] = Vector2(offset.x, offset.y);
	Vector2 position(this->object->get_world_position().x + offset.x, this->object->get_world_position().y + offset.y);
	this->points[*this->size] = Vector2(position.x, position.y);
	*this->size += 1;
}
void Collision::remove_point(const unsigned int& index)
{
	delete &this->offsets[index];
	delete &this->points[index];
	for (int i = index + 1; i < *this->size - index - 1; i++)
	{
		this->offsets[index - 1] = this->offsets[index];
		this->points[index - 1] = this->points[index];
	}
	delete &this->offsets[*this->size];
	delete &this->points[*this->size];
	*this->size -= 1;
}
void Collision::set_trigger(const bool& status)
{
	*this->isTrigger = status;
}
void Collision::set_enabled(const bool& status)
{
	*this->enabled = status;
}

void Collision::rotate(const float& angle)
{
	for (int i = 0; i < *this->size; i++)
	{
		this->points[i].x = this->points[i].x * cos(angle) - this->points[i].y * sin(angle);
		this->points[i].y = this->points[i].x * cos(angle) + this->points[i].y * sin(angle);
	}
}
const bool& Collision::intersects(const Collision& collision)
{
	if (*this->size > 0)
	{
		for (int i = 0; i < *collision.size; i++)
		{
			if (this->contains(collision.points[i])) return true;
		}
		return false;
	}
}
const bool& Collision::contains(const Vector2& point)
{
	/*bool result = false;
	int j = *this->size - 1;
	for (int i = 0; i < *this->size; i++)
	{
		if (this->points[i].y < point.y && this->points[j].y >= point.y || this->points[j].y < point.y && this->points[i].y >= point.y)
		{
			if (this->points[i].x + (point.y - this->points[i].y) / (this->points[j].y - this->points[i].y) * (this->points[j].x - this->points[i].x) < point.x)
			{
				result = !result;
			}
		}
		j = i;
	}
	return result;*/

	float min_distance = INFINITY;
	Vector2 min_point1, min_point2, min_point3;
	unsigned int index = 0;
	for (int i = 0; i < *this->size; i++)
	{
		float distance = Vector2::distance(this->points[i], point);
		if (distance < min_distance)
		{
			min_distance = distance;
			min_point1 = this->points[i];
			index = i;
		}
	}

	min_point2 = index > 0 ? this->points[index - 1] : this->points[*this->size - 1];
	min_point3 = index < *this->size - 1 ? this->points[index + 1] : this->points[0];

	std::cout << min_point1.x << " " << min_point1.y << "\n";
	std::cout << min_point2.x << " " << min_point2.y << "\n";
	std::cout << min_point3.x << " " << min_point3.y << "\n";

	Vector2 v1 = min_point2 - min_point1;
	Vector2 v2 = min_point3 - min_point1;
	Vector2 n1 = Vector2(v1.x, v2.y);
	Vector2 n2 = Vector2(v2.x, v2.y);
	Vector2 normal = Vector2::lerp(n1, n2, 0.5f);
	
	std::cout << Vector2::angle(min_point1, min_point2) << "\n";

	return Vector2::scalar(point, normal) > 0 ? true : false;
}

const bool& operator==(const Collision& collision1, const Collision& collision2)
{
	return collision1 == collision2;
}
const bool& operator!=(const Collision& collision1, const Collision& collision2)
{
	return !(collision1 == collision2);
}

Collision::~Collision()
{
	delete this->enabled;
	delete this->isTrigger;
	
	for (int i = 0; i < *this->size; i++)
	{
		delete &this->points[i];
		delete &this->offsets[i];
	}
	delete this->points;
	delete this->offsets;
	delete this->size;
}