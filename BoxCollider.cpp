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

void BoxCollider::set_outline_color(const sf::Color& color)
{
	dynamic_cast<sf::RectangleShape*>(this->outline)->setOutlineColor(color);
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
	GUI::add(this);
}

void BoxCollider::set_position(const Vector2& position)
{
	*this->position = position;
	*this->points[0] = Vector2(*this->position + Vector2(0, this->size->y));
	*this->points[1] = *this->position;
	*this->points[2] = Vector2(*this->position + Vector2(this->size->x, 0));
	*this->points[3] = Vector2(*this->position + Vector2(this->size->x, this->size->y));
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
	*this->points[0] = Vector2(*this->position + Vector2(0, size.y));
	*this->points[1] = *this->position;
	*this->points[2] = Vector2(*this->position + Vector2(size.x, 0));
	*this->points[3] = Vector2(*this->position + Vector2(size.x, size.y));
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
		sf::FloatRect rect1(sf::Vector2f(this->position->x, this->position->y), sf::Vector2f(this->size->x, this->size->y));
		float pos_x = collider->get_position().x;
		float pos_y = collider->get_position().y;
		float size_x = dynamic_cast<BoxCollider*>(collider)->size->x;
		float size_y = dynamic_cast<BoxCollider*>(collider)->size->y;
		sf::FloatRect rect2(sf::Vector2f(pos_x, pos_y), sf::Vector2f(size_x, size_y));
		return rect1.intersects(rect2);
	}

	if (dynamic_cast<CircleCollider*>(collider))
	{
		Vector2 left = collider->get_position() + Vector2(0, dynamic_cast<CircleCollider*>(collider)->get_radius());
		Vector2 right = collider->get_position() + Vector2(dynamic_cast<CircleCollider*>(collider)->get_radius() * 2, dynamic_cast<CircleCollider*>(collider)->get_radius());
		Vector2 up = collider->get_position() + Vector2(dynamic_cast<CircleCollider*>(collider)->get_radius(), 0);
		Vector2 down = collider->get_position() + Vector2(dynamic_cast<CircleCollider*>(collider)->get_radius(), dynamic_cast<CircleCollider*>(collider)->get_radius() * 2);

		if (contains(left) || contains(right) || contains(up) || contains(down)) return true;

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