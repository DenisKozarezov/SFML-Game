#include "DrawableContainer.h"

std::map<const std::string, DrawableLayer*>* DrawableContainer::layers =
	new std::map<const std::string, DrawableLayer*>;
void DrawableContainer::remove(GameObject* object)
{
	std::map<const std::string, DrawableLayer*>::iterator it;
	for (it = layers->begin(); it != layers->end(); it++)
	{
		if (it->second->get_layer()->size() > 0)
		{
			std::list<GameObject*>::iterator first = it->second->get_layer()->begin();
			std::list<GameObject*>::iterator last = it->second->get_layer()->end();
			std::list<GameObject*>::iterator find = std::find(first, last, object);
			if (find != last)
			{
				it->second->remove(object);
				break;
			}
		}
	}
}
void DrawableContainer::initialize(const unsigned short& container_size)
{
	for (int i = 0; i < container_size; i++)
	{
		layers->insert(std::make_pair(std::to_string(i), new DrawableLayer)); // i-layer
	}
	layers->insert(std::make_pair("GUI-dynamic", new DrawableLayer));  // reserved layer for dynamic interface (that can move)
	layers->insert(std::make_pair("GUI-particle", new DrawableLayer)); // reserved layer for particle systems
	layers->insert(std::make_pair("GUI-static", new DrawableLayer));   // reserved layer for static interface (that cannot move)

	get_layer("GUI-static")->make_unupdatable();
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
DrawableLayer* DrawableContainer::get_layer(const std::string& layer)
{
	return layers->find(layer)->second;
}
const unsigned short& DrawableContainer::size()
{
	return DrawableContainer::layers->size();
}
void DrawableContainer::update(sf::RenderWindow& window)
{
	std::map<const std::string, DrawableLayer*>::iterator it;
	for (it = layers->begin(); it != layers->end(); it++)
	{
		if (!it->second->IsHidden() && it->second->IsUpdatable()) it->second->update(window);
	}
}