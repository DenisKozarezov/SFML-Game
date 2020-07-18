#include "Drawable.h"
#include <algorithm>
#include <iostream>

#pragma region DrawableObject
void DrawableObject::set_layer(const unsigned int& layer)
{
	GameDrawableContainer::remove(*this->layer, this);
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
	GameDrawableContainer::get_layer(*object->layer)->push_back(object);
}
void DrawableObject::initialize(DrawableObject* object, const bool& isDrawable)
{
	*object->isDrawable = isDrawable;
	GameDrawableContainer::get_layer(*object->layer)->push_back(object);
}
void DrawableObject::initialize(DrawableObject* object, unsigned int& layer)
{
	GameDrawableContainer::get_layer(layer)->push_back(object);
}
void DrawableObject::destroy(DrawableObject* object)
{
	if (object != nullptr)
	{
		GameDrawableContainer::remove(*object->layer, object);
		delete dynamic_cast<DrawableObject*>(object);
		object = nullptr;
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

const unsigned int& DrawableObject::get_layer() const
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
#pragma endregion

#pragma region GameDrawableContainer
std::map<unsigned int, std::vector<DrawableObject*>*>* GameDrawableContainer::layers =
	new std::map<unsigned int, std::vector<DrawableObject*>*>;
void GameDrawableContainer::initialize()
{
	layers->insert(std::make_pair(0, new std::vector<DrawableObject*>)); // якни 0
	layers->insert(std::make_pair(1, new std::vector<DrawableObject*>)); // якни 1
	layers->insert(std::make_pair(2, new std::vector<DrawableObject*>)); // якни 2
	layers->insert(std::make_pair(3, new std::vector<DrawableObject*>)); // якни 3
	layers->insert(std::make_pair(4, new std::vector<DrawableObject*>)); // якни 4
}
template<typename T>
void GameDrawableContainer::remove_group(const T& type)
{
	
}
void GameDrawableContainer::remove(const DrawableObject* object)
{	
	std::map<unsigned int, std::vector<DrawableObject*>*>::iterator layer = layers->begin();
	for (layer = layers->begin(); layer != layers->end(); layer++)
	{
		std::vector<DrawableObject*>::iterator first = layer->second->begin();
		std::vector<DrawableObject*>::iterator last = layer->second->end();
		std::vector<DrawableObject*>::iterator it = std::find(first, last, object);
		if (it != last)
		{
			layer->second->erase(it);
			break;
		}
	}
}
void GameDrawableContainer::remove(const unsigned int& layer, DrawableObject* object)
{	
	std::vector<DrawableObject*>* _layer = get_layer(layer);
	std::vector<DrawableObject*>::iterator first = _layer->begin();
	std::vector<DrawableObject*>::iterator last = _layer->end();
	std::vector<DrawableObject*>::iterator it = std::find(first, last, object);
	if (it != last) _layer->erase(it);
}
const bool GameDrawableContainer::is_layer_contains(const unsigned int& layer, const DrawableObject* object)
{
	std::vector<DrawableObject*>::iterator first = get_layer(layer)->begin();
	std::vector<DrawableObject*>::iterator last = get_layer(layer)->end();
	std::vector<DrawableObject*>::iterator it = std::find(first, last, object);
	return it != last;
}
void GameDrawableContainer::clear()
{
	for (int i = 0; i < layers->size(); i++) get_layer(i)->clear();
}
void GameDrawableContainer::terminate()
{
	std::map<unsigned int, std::vector<DrawableObject*>*>::iterator it;
	for (it = layers->begin(); it != layers->end(); it++)
	{
		std::vector<DrawableObject*>::iterator layer;
		for (layer = it->second->begin(); layer != it->second->end(); layer++) delete *layer;
		it->second->clear();
		delete it->second;
	}
	delete layers;
}
std::vector<DrawableObject*>* GameDrawableContainer::get_layer(const unsigned int& layer)
{
	return layers->find(layer)->second;
}
const unsigned int& GameDrawableContainer::get_layers_amount()
{
	return GameDrawableContainer::layers->size();
}
void GameDrawableContainer::update(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < layers->size(); i++)
	{
		std::vector<DrawableObject*>* _layer = get_layer(i);
		if (_layer->size() > 0)
		{
			for (auto object : *_layer)
			{
				DrawableObject* obj = dynamic_cast<DrawableObject*>(object);
				if (obj->isDrawable)
				{
					obj->update();
					window.draw(*obj->get_sprite());
				}
			}
		}
	}
}
#pragma endregion