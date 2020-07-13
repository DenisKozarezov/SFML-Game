#include "Camera.h"
#include <iostream>

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
}

void Camera::update(const double& deltaTime)
{
	if (*this->point_target != sf::Vector2f(0, 0))
	{
		if (*this->factor < 1)
		{
			sf::Vector2f position = Math::lerp(*this->lerp_position, *this->point_target, *this->factor);
			offset_move(position);
			*this->factor = Math::get_factor(*this->factor + deltaTime / *this->time);
		}
		else
		{
			std::cout << "DESTINATION IS HERE!\n";
			*this->factor = 0;
			*this->position = *this->point_target;
			stop();
		}
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
const sf::Vector2f& Camera::get_position() const
{
	return *this->position;
}

void Camera::offset_move(const sf::Vector2f& offset)
{
	for (unsigned int i = 0; i < GameDrawableContainer::get_layers_amount(); i++)
	{
		std::vector<DrawableObject*>::iterator it;
		std::vector<DrawableObject*>* layer = GameDrawableContainer::get_layer(i);
		if (layer->size() > 0)
		{
			for (it = layer->begin(); it != layer->end(); it++)
			{
				DrawableObject* object = dynamic_cast<DrawableObject*>(*it);
				object->set_position(object->get_position() + offset);
			}
		}
	}
}
void Camera::offset_move(const float& offset_x, const float& offset_y)
{
	offset_move(sf::Vector2f(offset_x, offset_y));
}

void Camera::move_to(const sf::Vector2f& point)
{
	*this->position += point;
	offset_move(point - *this->position);
}
void Camera::move_to(const float& x, const float& y)
{
	offset_move(sf::Vector2f(x, y));
}
void Camera::move_to(const sf::Vector2f& point, const float& time)
{
	*this->moving = true;
	*this->time = time;
	*this->point_target = -point;	
	*this->lerp_position = *this->position;
}
void Camera::move_to(DrawableObject* object)
{
	move_to(object->get_position());
}
void Camera::move_to(DrawableObject* object, const float& time)
{
	*this->moving = true;
	*this->time = time;
	*this->point_target = object->get_position();
}

void Camera::stop()
{
	*this->moving = false;
	*this->point_target = sf::Vector2f(0, 0);
}

void Camera::set_speed(const float& value)
{
	*this->speed = value;
}