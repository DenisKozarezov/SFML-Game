#include "Drawable.h"
#include <algorithm>

#pragma region DrawableObject
void DrawableObject::set_layer(const unsigned int& layer)
{
	GameDrawableContainer::remove(*this->layer, this);
	*this->layer = layer;
	initialize(this, layer);
}
void DrawableObject::set_texture(const sf::Texture& texture)
{
	*this->texture = texture;
	this->sprite->setTexture(texture);
}
void DrawableObject::set_image(const sf::Image& image)
{
	*this->image = image;
}
void DrawableObject::set_sprite(const sf::Sprite& sprite)
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

const unsigned int& DrawableObject::get_layer() const
{
	return *this->layer;
}
sf::Sprite* DrawableObject::get_sprite() const
{
	return this->sprite;
}
sf::Image* DrawableObject::get_image() const
{
	return this->image;
}
sf::Texture* DrawableObject::get_texture() const
{
	return this->texture;
}

DrawableObject::~DrawableObject()
{
	delete this->isDrawable;
	delete this->layer;

	delete this->screen_position;
	delete this->world_position;

	delete this->sprite;
	delete this->image;
	delete this->texture;
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