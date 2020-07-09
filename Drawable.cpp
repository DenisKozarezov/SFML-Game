#include "Drawable.h"
#include <algorithm>

#pragma region DrawableObject
void DrawableObject::set_layer(const unsigned int& layer)
{
	GameDrawableContainer::remove(*this->layer, this);
	*this->layer = layer;
	initialize(this, layer);
}
const unsigned int& DrawableObject::get_layer()
{
	return *this->layer;
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
DrawableObject::~DrawableObject()
{
	delete isDrawable;
	delete layer;
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
bool GameDrawableContainer::is_layer_contains(const unsigned int& layer, const DrawableObject* object)
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

void GameDrawableContainer::render(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < layers->size(); i++)
	{
		std::vector<DrawableObject*>* _layer = get_layer(i);
		if (_layer->size() > 0)
		{
			for (auto object : *_layer)
			{
				DrawableObject* obj = dynamic_cast<DrawableObject*>(object);
				if (obj->isDrawable) window.draw(*obj->get_sprite());
			}
		}
	}
}
#pragma endregion
