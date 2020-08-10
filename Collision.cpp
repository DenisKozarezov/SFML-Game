#include "Collision.h"
#include "BoxCollider.h"
#include "CircleCollider.h"

std::vector<Collision*>* Collision::colliders = new std::vector<Collision*>;
Collision::Collision()
{
	this->isTrigger = new bool(0);
	this->enabled = new bool(1);
	this->position = new Vector2;
	this->showOutline = new bool(1);
	this->colliders->push_back(this);
}

void Collision::set_trigger(const bool& status)
{
	*this->isTrigger = status;
}
void Collision::set_enabled(const bool& status)
{
	*this->enabled = status;
}
void Collision::set_position(const Vector2& position)
{
	*this->position = position;
}
void Collision::show_outline(const bool& status)
{
	*this->showOutline = status;
}

const bool& Collision::IsTrigger() const
{
	return *this->isTrigger;
}
const bool& Collision::IsEnabled() const
{
	return *this->enabled;
}
const Vector2& Collision::get_position() const
{
	return *this->position;
}
DrawableObject* Collision::get_object()
{
	return this->object;
}

void Collision::check_collision()
{
	if (colliders->size() > 1)
	{
		for (auto& collider1 : *colliders)
		{
			for (auto& collider2 : *colliders)
			{
				if (collider1 != collider2)
				{
					if	(
						(dynamic_cast<BoxCollider*>(collider1) && dynamic_cast<BoxCollider*>(collider2)
						&&
						dynamic_cast<BoxCollider*>(collider1)->intersects(dynamic_cast<BoxCollider*>(collider2)))

						||

						(dynamic_cast<BoxCollider*>(collider1) && dynamic_cast<CircleCollider*>(collider2)
						&&
						dynamic_cast<BoxCollider*>(collider1)->intersects(dynamic_cast<CircleCollider*>(collider2)))

						||

						(dynamic_cast<CircleCollider*>(collider1) && dynamic_cast<CircleCollider*>(collider2)
						&&
						dynamic_cast<CircleCollider*>(collider1)->intersects(dynamic_cast<CircleCollider*>(collider2)))
						)

					{

					}
				}
			}
		}
	}
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
	delete this->position;
	delete this->showOutline;
	delete this->outline;
	std::vector<Collision*>::iterator first = this->colliders->begin();
	std::vector<Collision*>::iterator last = this->colliders->end();
	std::vector<Collision*>::iterator find = std::find(first, last, this);
	this->colliders->erase(find);
}