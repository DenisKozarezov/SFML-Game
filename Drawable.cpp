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

void DrawableObject::set_position(const sf::Vector2f& point)
{
	*this->position = point;
	this->sprite->setPosition(point);
}
void DrawableObject::set_position(const float& x, const float& y)
{
	set_position(sf::Vector2f(x, y));
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

const sf::Vector2f& DrawableObject::get_position() const
{
	return *this->position;
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

	delete this->position;

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
void GameDrawableContainer::extern_move(const sf::Vector2f& screen_point)
{
	std::map<unsigned int, std::vector<DrawableObject*>*>::iterator it;
	for (it = layers->begin(); it != layers->end(); it++)
	{
		if (it->second->size() > 0)
		{
			std::vector<DrawableObject*>::iterator layer;
			for (layer = it->second->begin(); layer != it->second->end(); layer++)
			{
				dynamic_cast<DrawableObject*>(*layer)->set_position(screen_point);
			}
		}
	}
}
void GameDrawableContainer::extern_move(const float& x, const float& y)
{
	extern_move(sf::Vector2f(x, y));
}
void GameDrawableContainer::extern_move(const unsigned int& layer, const sf::Vector2f& screen_point)
{
	std::vector<DrawableObject*>* _layer = get_layer(layer);
	std::vector<DrawableObject*>::iterator it = _layer->begin();
	for (it = _layer->begin(); it != _layer->end(); it++)
	{
		dynamic_cast<DrawableObject*>(*it)->set_position(screen_point);
	}
}
void GameDrawableContainer::extern_move(const unsigned int& layer, const float& x, const float& y)
{
	extern_move(layer, sf::Vector2f(x, y));
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