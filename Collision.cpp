#include "Collision.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include <iostream>

std::list<Collision*>* Collision::colliders = new std::list<Collision*>;
Collision::Collision()
{
	this->isTrigger = new bool(0);
	this->enabled = new bool(1);
	this->collided = new bool(0);
	this->position = new Vector2;
	this->showOutline = new bool(1);

	this->OnCollisionEnter = new Delegate<Collision*>;
	this->OnCollisionExit = new Delegate<Collision*>;
	this->OnTriggerEnter = new Delegate<Collision*>;
	this->OnTriggerExit = new Delegate<Collision*>;

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
void Collision::set_object(GameObject* object)
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
GameObject* Collision::get_object() const
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
						if (!*collider1->isTrigger)
						{
							if (!*collider1->collided)
							{
								*collider1->collided = true;
								collider1->OnCollisionEnter->invoke(collider2);
								collider1->set_outline_color(sf::Color::Yellow);								
							}
							collider1->get_object()->move(collider1->get_position() - collider1->get_object()->get_velocity());
							collider1->get_object()->set_velocity(Vector2::zero);
						}
						else collider1->OnTriggerEnter->invoke(collider2);
					}
					else
					{
						if (!*collider1->isTrigger)
						{
							if (*collider1->collided)
							{
								*collider1->collided = false;
								collider1->OnCollisionExit->invoke(collider2);
								collider1->set_outline_color(sf::Color::Green);
							}
						}
						else collider1->OnTriggerExit->invoke(collider2);
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
	delete this->OnTriggerEnter;
	delete this->OnTriggerExit;

	std::list<Collision*>::iterator first = this->colliders->begin();
	std::list<Collision*>::iterator last = this->colliders->end();
	std::list<Collision*>::iterator find = std::find(first, last, this);
	this->colliders->erase(find);
}