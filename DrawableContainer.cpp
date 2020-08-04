#include "DrawableContainer.h"

std::map<const std::string, DrawableLayer*>* DrawableContainer::layers =
	new std::map<const std::string, DrawableLayer*>;
unsigned short DrawableContainer::reserved_const = 0;

DrawableLayer* DrawableContainer::get_GUI()
{
	std::map<const std::string, DrawableLayer*>::iterator it = layers->begin();
	std::advance(it, size() - 1);
	return it->second;
}

void DrawableContainer::initialize(const unsigned short& container_size)
{
	for (int i = 0; i < container_size; i++)
	{
		layers->insert(std::make_pair(std::to_string(i), new DrawableLayer)); // i-layer.
	}
	layers->insert(std::make_pair("GUI-dymanic", new DrawableLayer));  // reserved layer for dynamical interface (that can move)
	layers->insert(std::make_pair("GUI-particle", new DrawableLayer)); // reserved layer for particle systems
	layers->insert(std::make_pair("GUI-static", new DrawableLayer));   // reserved layer for static interface (that cannot move)

	reserved_const = 3;
}
void DrawableContainer::terminate()
{
	std::map<const std::string, DrawableLayer*>::iterator it;
	for (it = layers->begin(); it != layers->end(); it++) delete it->second;
	delete layers;
}
DrawableLayer* DrawableContainer::get_layer(const unsigned short& layer)
{
	return layers->find(std::to_string(layer))->second;
}
const unsigned short& DrawableContainer::size()
{
	return DrawableContainer::layers->size();
}
const unsigned short& DrawableContainer::reserved_size()
{
	return reserved_const;
}

void DrawableContainer::update(sf::RenderWindow& window)
{
	std::map<const std::string, DrawableLayer*>::iterator it;
	for (it = layers->begin(); it != layers->end(); it++)
	{
		if (!it->second->IsHidden()) it->second->update(window);
	}
}