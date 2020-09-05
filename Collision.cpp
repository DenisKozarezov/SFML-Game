#include "Collision.h"
#include "BoxCollider.h"
#include "CircleCollider.h"

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

bool Collision::intersects(Collision* collider1, Collision* collider2)
{
	if (dynamic_cast<BoxCollider*>(collider1) && dynamic_cast<BoxCollider*>(collider2))
	{
		return dynamic_cast<BoxCollider*>(collider1)->intersects(dynamic_cast<BoxCollider*>(collider2));
	}

	if (dynamic_cast<BoxCollider*>(collider1) && dynamic_cast<CircleCollider*>(collider2))
	{
		return dynamic_cast<BoxCollider*>(collider1)->intersects(dynamic_cast<CircleCollider*>(collider2));
	}
	else if (dynamic_cast<BoxCollider*>(collider2) && dynamic_cast<CircleCollider*>(collider1))
	{
		return dynamic_cast<BoxCollider*>(collider2)->intersects(dynamic_cast<CircleCollider*>(collider1));
	}

	if (dynamic_cast<CircleCollider*>(collider1) && dynamic_cast<CircleCollider*>(collider2))
	{
		return dynamic_cast<CircleCollider*>(collider1)->intersects(dynamic_cast<CircleCollider*>(collider2));
	}

	return false;
}

void Collision::check_collision()
{
	if (colliders->size() > 1)
	{
		// PAIRS COUNT K = ((N - 1) * N) / 2;
		std::list<Collision*>::iterator it1 = colliders->begin();
		std::list<Collision*>::iterator it2 = colliders->begin();
		for (unsigned int i = 0; i < colliders->size() - 1; i++, std::advance(it1, 1))
		{
			for (unsigned int j = i + 1; j < colliders->size(); j++, it2 = colliders->begin())
			{
				std::advance(it2, j);
				Collision* collider1 = dynamic_cast<Collision*>(*it1);
				Collision* collider2 = dynamic_cast<Collision*>(*it2);

				if (collider1->intersects(collider2))
				{
					if (!*collider1->isTrigger)
					{
						if (!*collider1->collided)
						{
							*collider1->collided = true;
							collider1->OnCollisionEnter->invoke(collider2);
						}
						if (collider1->get_object() && collider1->get_object()->get_velocity() != Vector2::zero)
						{
							collider1->get_object()->move(collider1->get_position() - collider1->get_object()->get_velocity());
							collider1->get_object()->set_velocity(Vector2::zero);
						}
					}
					else collider1->OnTriggerEnter->invoke(collider2);

					if (!*collider2->isTrigger)
					{
						if (!*collider2->collided)
						{
							*collider2->collided = true;
							collider2->OnCollisionEnter->invoke(collider1);
						}
						if (collider2->get_object() && collider2->get_object()->get_velocity() != Vector2::zero)
						{
							collider2->get_object()->move(collider2->get_position() - collider2->get_object()->get_velocity());
							collider2->get_object()->set_velocity(Vector2::zero);
						}
					}
					else collider2->OnTriggerEnter->invoke(collider1);
				}
				else
				{
					if (!*collider1->isTrigger)
					{
						if (*collider1->collided)
						{
							*collider1->collided = false;
							collider1->OnCollisionExit->invoke(collider2);
						}
					}
					else collider1->OnTriggerExit->invoke(collider2);

					if (!*collider2->isTrigger)
					{
						if (*collider2->collided)
						{
							*collider2->collided = false;
							collider2->OnCollisionExit->invoke(collider1);
						}
					}
					else collider2->OnTriggerExit->invoke(collider1);
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