#include "DrawableObject.h"
#include "DrawableContainer.h"

DrawableObject::DrawableObject()
{
	this->layer = new unsigned int(0);
	this->screen_position = new Vector2(0.f, 0.f);
	this->world_position = new Vector2(0.f, 0.f);
	this->sprite = new Sprite;
	this->isDrawable = new bool(true);
}

void DrawableObject::set_layer(const unsigned short& layer)
{
	GameDrawableContainer::get_layer(layer)->remove(this);
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

void DrawableObject::set_screen_position(const Vector2& point)
{
	*this->screen_position = point;
	this->sprite->setPosition(point.x, point.y);
}
void DrawableObject::set_screen_position(const float& x, const float& y)
{
	set_screen_position(Vector2(x, y));
}
void DrawableObject::set_world_position(const Vector2& point)
{
	*this->world_position = point;
}
void DrawableObject::set_world_position(const float& x, const float& y)
{
	set_world_position(Vector2(x, y));
}

void DrawableObject::initialize(DrawableObject* object)
{
	GameDrawableContainer::get_layer(*object->layer)->add(object);
}
void DrawableObject::initialize(DrawableObject* object, const unsigned short& layer)
{
	GameDrawableContainer::get_layer(layer)->add(object);
}
void DrawableObject::destroy(DrawableObject* object)
{
	if (object != NULL)
	{
		//GameDrawableContainer::remove(*object->layer, object);
		delete dynamic_cast<DrawableObject*>(object);
		object = NULL;
	}
}

const Vector2& DrawableObject::get_screen_position() const
{
	return *this->screen_position;
}
const Vector2& DrawableObject::get_world_position() const
{
	return *this->world_position;
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
		set_screen_position(this->get_screen_position() + Vector2(width, 0));
		if (this->sprite->getScale().x > 0)
			this->sprite->setScale(-this->sprite->getScale().x, this->sprite->getScale().y);
		this->sprite->swapX(true);
	}
	else
	{
		set_screen_position(this->get_screen_position() + Vector2(-width, 0));
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
		set_screen_position(this->get_screen_position() + Vector2(0, height));
		if (this->sprite->getScale().y > 0)
			this->sprite->setScale(this->sprite->getScale().x, -this->sprite->getScale().y);
		this->sprite->swapY(true);
	}
	else
	{
		set_screen_position(this->get_screen_position() + Vector2(0, -height));
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
	delete this->isDrawable;
	delete this->layer;

	delete this->screen_position;
	delete this->world_position;

	delete this->sprite;
}