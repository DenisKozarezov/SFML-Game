#include "BoxCollider.h"
#include "CircleCollider.h"

void BoxCollider::initialize()
{
	this->size = new Vector2;
	this->points[0] = new Vector2;
	this->points[1] = new Vector2;
	this->points[2] = new Vector2;
	this->points[3] = new Vector2;
	this->outline = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(this->outline)->setOutlineThickness(1);
	dynamic_cast<sf::RectangleShape*>(this->outline)->setOutlineColor(sf::Color::Green);
	dynamic_cast<sf::RectangleShape*>(this->outline)->setFillColor(sf::Color::Transparent);
}

BoxCollider::BoxCollider()
{
	initialize();
	GUI::add(this);
}
BoxCollider::BoxCollider(const Vector2& position, const Vector2& size)
{
	initialize();
	set_position(position);
	set_size(size);
	dynamic_cast<sf::RectangleShape*>(this->outline)->setPosition(position.x, position.y);
	dynamic_cast<sf::RectangleShape*>(this->outline)->setSize(sf::Vector2f(size.x, size.y));
	GUI::add(this);
}

void BoxCollider::set_position(const Vector2& position)
{
	*this->position = position;
	dynamic_cast<sf::RectangleShape*>(this->outline)->setPosition(position.x, position.y);
}
void BoxCollider::set_position(const float& x, const float& y)
{
	set_position(Vector2(x, y));
}
void BoxCollider::set_size(const Vector2& size)
{
	*this->size = size;
	dynamic_cast<sf::RectangleShape*>(this->outline)->setSize(sf::Vector2f(size.x, size.y));
	*this->points[0] = Vector2(*this->position - size);
	*this->points[1] = Vector2(*this->position + Vector2(-size.x, size.y));
	*this->points[2] = Vector2(*this->position + size);
	*this->points[3] = Vector2(*this->position + Vector2(size.x, -size.y));
}
void BoxCollider::set_size(const float& width, const float& height)
{
	set_size(Vector2(width, height));
}

const Vector2& BoxCollider::get_size() const
{
	return *this->size;
}

const bool& BoxCollider::intersects(Collision* collider) const
{
	if (dynamic_cast<BoxCollider*>(collider))
	{
		Rect rect1(*this->position, *this->size);
		Rect rect2(*dynamic_cast<BoxCollider*>(collider)->position, *dynamic_cast<BoxCollider*>(collider)->size);
		return rect1.intersects(rect2);
	}

	if (dynamic_cast<CircleCollider*>(collider))
	{
		if (contains(collider->get_position())) return true;

		for (unsigned short i = 0; i < 4; i++)
		{
			if (collider->contains(*this->points[i])) return true;
		}
		return false;
	}
}
const bool& BoxCollider::contains(const Vector2& point) const
{
	Rect rect(*this->position, *this->size);
	return rect.contains(point);
}

BoxCollider::~BoxCollider()
{
	delete this->size;
	for (unsigned short i = 0; i < 4; i++) delete this->points[i];
	delete this->points;
}