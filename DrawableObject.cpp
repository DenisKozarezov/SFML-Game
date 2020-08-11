#include "DrawableObject.h"
#include "DrawableContainer.h"

DrawableObject::DrawableObject()
{
	this->layer = new unsigned int(0);
	this->position = new Vector2;
	this->velocity = new Vector2;
	this->sprite = new Sprite;
	this->hidden = new bool(0);
}

void DrawableObject::set_layer(const unsigned short& layer)
{
	DrawableContainer::get_layer(layer)->remove(this);
	*this->layer = layer;
	initialize(this, layer);
}
void DrawableObject::set_texture(const sf::Texture& texture)
{
	this->sprite->setTexture(texture);
}
void DrawableObject::set_sprite(const Sprite& sprite)
{
	*this->sprite = sprite;
}
void DrawableObject::offset_sprite(const Vector2& offset)
{
	move(get_position() + offset);
}

void DrawableObject::set_position(const Vector2& position)
{
	*this->position = position;
}
void DrawableObject::set_position(const float& x, const float& y)
{
	set_position(Vector2(x, y));
}

void DrawableObject::initialize(DrawableObject* object)
{
	DrawableContainer::get_layer(*object->layer)->add(object);
}
void DrawableObject::initialize(DrawableObject* object, const unsigned short& layer)
{
	DrawableContainer::get_layer(layer)->add(object);
}
void DrawableObject::initialize(DrawableObject* object, const std::string& layer)
{
	DrawableContainer::layers->find(layer)->second->add(object);
}
void DrawableObject::destroy(DrawableObject* object)
{
	if (object != NULL)
	{
		DrawableContainer::remove(object);
		delete dynamic_cast<DrawableObject*>(object);
		object = NULL;
	}
}

const bool& DrawableObject::IsHidden() const
{
	return *this->hidden;
}

void DrawableObject::hide(const bool& status)
{
	*this->hidden = status;
}

void DrawableObject::set_velocity(const Vector2& velocity)
{
	*this->velocity = velocity;
}

void DrawableObject::set_velocity(const float& x_vector, const float& y_vector)
{
	set_velocity(Vector2(x_vector, y_vector));
}

const Vector2& DrawableObject::get_velocity() const
{
	return *this->velocity;
}
const Vector2& DrawableObject::get_position() const
{
	return *this->position;
}
const bool& DrawableObject::IsSwappedX() const
{
	return this->sprite->IsSwappedX();
}
const bool& DrawableObject::IsSwappedY() const
{
	return this->sprite->IsSwappedY();
}

const unsigned short& DrawableObject::get_layer() const
{
	return *this->layer;
}

void DrawableObject::swapX(const bool& status)
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
void DrawableObject::swapY(const bool& status)
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

Sprite* DrawableObject::get_sprite() const
{
	return this->sprite;
}

DrawableObject::~DrawableObject()
{
	delete this->hidden;
	delete this->layer;
	delete this->position;
	delete this->velocity;

	delete this->sprite;
}