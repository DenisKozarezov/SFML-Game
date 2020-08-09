#include "CircleCollider.h"
#include "BoxCollider.h"

void CircleCollider::initialize()
{
	this->radius = new float(0);
	this->outline = new sf::CircleShape;
	dynamic_cast<sf::CircleShape*>(this->outline)->setOutlineThickness(1);
	dynamic_cast<sf::CircleShape*>(this->outline)->setOutlineColor(sf::Color::Green);
	dynamic_cast<sf::CircleShape*>(this->outline)->setFillColor(sf::Color::Transparent);
	dynamic_cast<sf::CircleShape*>(this->outline)->setRadius(0);
}

CircleCollider::CircleCollider()
{
	initialize();
	GUI::add(this);
}
CircleCollider::CircleCollider(const Vector2& position, const float& radius)
{
	initialize();
	set_position(position);
	set_radius(radius);
	GUI::add(this);
}

void CircleCollider::set_radius(const float& radius)
{
	*this->radius = radius;
	dynamic_cast<sf::CircleShape*>(this->outline)->setRadius(radius);
}
void CircleCollider::set_position(const Vector2& position)
{
	*this->position = position;
	dynamic_cast<sf::CircleShape*>(this->outline)->setPosition(position.x, position.y);
}
void CircleCollider::set_position(const float& x, const float& y)
{
	set_position(Vector2(x, y));
}

const float& CircleCollider::get_radius() const
{
	return *this->radius;
}

const bool& CircleCollider::intersects(Collision* collider) const
{
	if (dynamic_cast<CircleCollider*>(collider))
	{
		//Rect rect2(*dynamic_cast<BoxCollider*>(collider)->position, *dynamic_cast<BoxCollider*>(collider)->size);
	}
	return true;
}

//const bool& CircleCollider::intersects(BoxCollider* collider) const
//{
//	return collider->intersects(this);
//}
//const bool& CircleCollider::intersects(CircleCollider* collider) const
//{
//	return Vector2::distance(*this->position, *collider->position) <= *this->radius + *collider->radius;
//}
const bool& CircleCollider::contains(const Vector2& point) const
{
	return Vector2::distance(*this->position, point) <= *this->radius;
}

CircleCollider::~CircleCollider()
{
	delete this->radius;
}