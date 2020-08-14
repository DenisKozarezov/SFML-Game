#include "GameObject.h"
#include "DrawableContainer.h"

GameObject::GameObject()
{
	this->name = new std::string("Empty name");
	this->tag = new std::string("Empty tag");
	this->layer = new unsigned int(0);
	this->position = new Vector2;
	this->velocity = new Vector2;
	this->gravity = new float(0);
	this->sprite = new Sprite;
	this->hidden = new bool(0);
}

void GameObject::set_name(const std::string& name)
{
	*this->name = name;
}
void GameObject::set_tag(const std::string& name)
{
	*this->tag = name;
}
void GameObject::set_position(const Vector2& position)
{
	*this->position = position;
}
void GameObject::set_position(const float& x, const float& y)
{
	set_position(Vector2(x, y));
}
void GameObject::set_velocity(const Vector2& velocity)
{
	*this->velocity = velocity;
}
void GameObject::set_velocity(const float& x_vector, const float& y_vector)
{
	set_velocity(Vector2(x_vector, y_vector));
}
void GameObject::set_gravity(const float& scale)
{
	*this->gravity = scale;
}
void GameObject::set_layer(const unsigned short& layer)
{
	DrawableContainer::get_layer(layer)->remove(this);
	*this->layer = layer;
	initialize(this, layer);
}
void GameObject::swapX(const bool& status)
{
	float width;
	if (*this->sprite->isMultiple) width = abs(this->sprite->getTexture()->getSize().x / this->sprite->get_frames_count() * this->sprite->getScale().x);
	else width = abs(this->sprite->getTexture()->getSize().x * this->sprite->getScale().x);

	if (status)
	{
		*this->position += Vector2(width, 0);
		if (this->sprite->getScale().x > 0)
			this->sprite->setScale(-this->sprite->getScale().x, this->sprite->getScale().y);
		this->sprite->swapX(true);
	}
	else
	{
		*this->position += Vector2(-width, 0);
		if (this->sprite->getScale().x < 0)
			this->sprite->setScale(-this->sprite->getScale().x, this->sprite->getScale().y);
		this->sprite->swapX(false);
	}
}
void GameObject::swapY(const bool& status)
{
	float height;
	if (*this->sprite->isMultiple) height = abs(this->sprite->getTexture()->getSize().x / this->sprite->get_frames_count() * this->sprite->getScale().x);
	else height = abs(this->sprite->getTexture()->getSize().x * this->sprite->getScale().x);

	if (status)
	{
		*this->position += Vector2(0, height);
		if (this->sprite->getScale().y > 0)
			this->sprite->setScale(this->sprite->getScale().x, -this->sprite->getScale().y);
		this->sprite->swapY(true);
	}
	else
	{
		*this->position += Vector2(0, -height);
		if (this->sprite->getScale().y < 0)
			this->sprite->setScale(this->sprite->getScale().x, -this->sprite->getScale().y);
		this->sprite->swapY(false);
	}
}
void GameObject::hide(const bool& status)
{
	*this->hidden = status;
}
void GameObject::destroy(GameObject* object)
{
	if (object != NULL)
	{
		DrawableContainer::remove(object);
		delete dynamic_cast<GameObject*>(object);
		object = NULL;
	}
}

const std::string& GameObject::get_name() const
{
	return *this->name;
}
const std::string& GameObject::get_tag() const
{
	return *this->tag;
}
const unsigned short& GameObject::get_layer() const
{
	return *this->layer;
}
const Vector2& GameObject::get_position() const
{
	return *this->position;
}
const Vector2& GameObject::get_velocity() const
{
	return *this->velocity;
}
const float& GameObject::get_gravity() const
{
	return *this->gravity;
}
const bool& GameObject::IsSwappedX() const
{
	return this->sprite->IsSwappedX();
}
const bool& GameObject::IsSwappedY() const
{
	return this->sprite->IsSwappedY();
}
const bool& GameObject::IsHidden() const
{
	return *this->hidden;
}


void GameObject::set_texture(const sf::Texture& texture)
{
	this->sprite->setTexture(texture);
}
void GameObject::set_sprite(const Sprite& sprite)
{
	*this->sprite = sprite;
}
void GameObject::offset_sprite(const Vector2& offset)
{
	move(get_position() + offset);
}
void GameObject::initialize(GameObject* object)
{
	DrawableContainer::get_layer(*object->layer)->add(object);
}
void GameObject::initialize(GameObject* object, const unsigned short& layer)
{
	DrawableContainer::get_layer(layer)->add(object);
}
void GameObject::initialize(GameObject* object, const std::string& layer)
{
	DrawableContainer::layers->find(layer)->second->add(object);
}

Sprite* GameObject::get_sprite() const
{
	return this->sprite;
}

GameObject::~GameObject()
{
	delete this->name;
	delete this->tag;
	delete this->hidden;
	delete this->layer;
	delete this->position;
	delete this->velocity;
	delete this->gravity;
	delete this->sprite;
}