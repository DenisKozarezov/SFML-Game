#include "DrawableContainer.h"

#pragma region GameDrawableContainer
std::map<unsigned int, DrawableLayer*>* GameDrawableContainer::layers =
	new std::map<unsigned int, DrawableLayer*>;
void GameDrawableContainer::initialize(const unsigned short& container_size)
{
	for (int i = 0; i < container_size; i++)
	{
		layers->insert(std::make_pair(i, new DrawableLayer)); // ���� i-�.
	}
	layers->insert(std::make_pair(container_size, new DrawableLayer)); // ���� ������������ ���������� (������������ �� �������������)
}
void GameDrawableContainer::terminate()
{
	std::map<unsigned int, DrawableLayer*>::iterator it;
	for (it = layers->begin(); it != layers->end(); it++) delete it->second;
	delete layers;
}
DrawableLayer* GameDrawableContainer::get_layer(const unsigned short& layer)
{
	return layers->find(layer)->second;
}
const unsigned short& GameDrawableContainer::size()
{
	return GameDrawableContainer::layers->size();
}

void GameDrawableContainer::update(sf::RenderWindow& window)
{
	std::map<unsigned int, DrawableLayer*>::iterator it;
	for (it = layers->begin(); it != layers->end(); it++)
	{
		if (it->second->IsDrawable()) it->second->update(window);
	}
}
#pragma endregion