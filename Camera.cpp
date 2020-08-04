#include "Camera.h"

Camera::Camera()
{

}

Camera::~Camera()
{
	delete this->position;
	delete this->faded;
	delete this->moving;
	delete this->point_target;
	delete this->attached_target;
	delete this->speed;
	delete this->time;
	delete this->lerp_position;
}

void Camera::update(const double& deltaTime)
{
	if (*this->point_target != Vector2(0, 0))
	{
		if (*this->factor < 1)
		{
			Vector2 position = Vector2::lerp(*this->lerp_position, *this->point_target, *this->factor);
			move(position);
			*this->factor = Math::get_factor(*this->factor + deltaTime / *this->time);
		}
		else
		{
			*this->factor = 0;
			*this->position = *this->point_target;
			stop();
		}
	}
}
void Camera::input_update(const sf::RenderWindow& window)
{
	float left = Math::percent_of(0.03f, window.getSize().x);
	float right = Math::percent_of(0.97f, window.getSize().x);
	float up = Math::percent_of(0.03f, window.getSize().y);
	float down = Math::percent_of(0.97f, window.getSize().y);
	if (sf::Mouse::getPosition().x <= left)
	{
		Vector2 position = get_position() + Vector2::right;
		move_to(position);
	}
	if (sf::Mouse::getPosition().x >= right)
	{
		Vector2 position = get_position() + Vector2::left;
		move_to(position);
	}
	if (sf::Mouse::getPosition().y <= down)
	{
		Vector2 position = get_position() + Vector2::up;
		move_to(position);
	}
	if (sf::Mouse::getPosition().y >= up)
	{
		Vector2 position = get_position() + Vector2::down;
		move_to(position);
	}
}

const bool& Camera::isMoving() const
{
	return *this->moving;
}
const bool& Camera::isFaded() const
{
	return *this->faded;
}

const Vector2& Camera::get_position() const
{
	return *this->position;
}
const float& Camera::get_speed() const
{
	return *this->speed;
}

void Camera::move(const Vector2& offset)
{
	for (unsigned int i = 0; i < DrawableContainer::size() - DrawableContainer::reserved_size(); i++)
	{
		std::vector<DrawableObject*>::iterator it;
		std::vector<DrawableObject*>* layer = DrawableContainer::get_layer(i)->get_layer();
		if (layer->size() > 0)
		{
			for (it = layer->begin(); it != layer->end(); it++)
			{
				DrawableObject* object = dynamic_cast<DrawableObject*>(*it);
				object->set_screen_position(object->get_screen_position() + offset);
			}
		}
	}
}
void Camera::move(const float& offset_x, const float& offset_y)
{
	move(Vector2(offset_x, offset_y));
}

void Camera::move_to(const Vector2& point)
{
	Vector2 deltaPos = point - *this->position;
	*this->position += deltaPos;
	move(deltaPos);
}
void Camera::move_to(const float& x, const float& y)
{
	move(Vector2(x, y));
}
void Camera::move_to(const Vector2& point, const float& time)
{
	*this->moving = true;
	*this->time = time;
	*this->point_target = -point;	
	*this->lerp_position = *this->position;
}

void Camera::stop()
{
	*this->moving = false;
	*this->point_target = Vector2::negative_infinity;
}

void Camera::set_speed(const float& value)
{
	*this->speed = value;
}