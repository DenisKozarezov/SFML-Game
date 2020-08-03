#include "DrawableLayer.h"

DrawableLayer::DrawableLayer()
{
	this->drawable = new bool(true);
	this->layer = new std::vector<DrawableObject*>;
}

const bool& DrawableLayer::IsDrawable() const
{
	return *this->drawable;
}

void DrawableLayer::add(DrawableObject* object)
{
	this->layer->push_back(object);
}
template<typename T>
void DrawableLayer::remove_group(const T& type)
{

}
void DrawableLayer::remove(DrawableObject* object)
{
	std::vector<DrawableObject*>::iterator first = this->layer->begin();
	std::vector<DrawableObject*>::iterator last = this->layer->end();
	std::vector<DrawableObject*>::iterator it = std::find(first, last, object);
	if (it != last) this->layer->erase(it);
}
const bool& DrawableLayer::is_contain(DrawableObject* object) const
{
	std::vector<DrawableObject*>::iterator first = this->layer->begin();
	std::vector<DrawableObject*>::iterator last = this->layer->end();
	std::vector<DrawableObject*>::iterator it = std::find(first, last, object);
	return it != last;
}

void DrawableLayer::update(sf::RenderWindow& window)
{
	std::vector<DrawableObject*>::iterator it;
	for (it = this->layer->begin(); it != this->layer->end(); it++)
	{
		DrawableObject* object = dynamic_cast<DrawableObject*>(*it);
		if (object->isDrawable)
		{
			object->update();
			window.draw(*object->get_sprite());
		}
	}
}

std::vector<DrawableObject*>* DrawableLayer::get_layer()
{
	return this->layer;
}

DrawableLayer::~DrawableLayer()
{
	delete this->drawable;

	std::vector<DrawableObject*>::iterator it;
	for (it = this->layer->begin(); it != this->layer->end(); it++) delete* it;
	delete this->layer;	
}