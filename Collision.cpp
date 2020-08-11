#include "Collision.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include <iostream>

std::vector<Collision*>* Collision::colliders = new std::vector<Collision*>;
Collision::Collision()
{
	this->isTrigger = new bool(0);
	this->enabled = new bool(1);
	this->collided = new bool(0);
	this->position = new Vector2;
	this->showOutline = new bool(1);

	this->OnCollisionEnter = new Delegate;
	this->OnCollisionExit = new Delegate;

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
void Collision::set_object(DrawableObject* object)
{
	this->object = object;
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
const bool& Collision::IsCollided() const
{
	return *this->collided;
}
const Vector2& Collision::get_position() const
{
	return *this->position;
}
DrawableObject* Collision::get_object() const
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
						*collider1->collided = true;
						*collider2->collided = true;
						//collider1->get_object()->move(collider1->get_correct_collision(collider2));
						collider1->get_object()->move(collider1->get_position() - collider1->get_object()->get_velocity());
						collider1->get_object()->set_velocity(Vector2::zero);
						collider1->OnCollisionEnter->invoke();
						collider2->OnCollisionEnter->invoke();
					}
					else
					{
						if (*collider1->collided) {	*collider1->collided = false; collider1->OnCollisionExit->invoke();	}
						if (*collider2->collided) {	*collider2->collided = false; collider2->OnCollisionExit->invoke(); }
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
	delete this->collided;
	delete this->position;
	delete this->showOutline;
	delete this->outline;

	delete this->OnCollisionEnter;
	delete this->OnCollisionExit;

	std::vector<Collision*>::iterator first = this->colliders->begin();
	std::vector<Collision*>::iterator last = this->colliders->end();
	std::vector<Collision*>::iterator find = std::find(first, last, this);
	this->colliders->erase(find);
}