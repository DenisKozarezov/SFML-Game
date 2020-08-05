#include "DrawableLayer.h"

DrawableLayer::DrawableLayer()
{
	this->hidden = new bool(0);
	this->updatable = new bool(1);
	this->layer = new std::vector<DrawableObject*>;
}

const bool& DrawableLayer::IsHidden() const
{
	return *this->hidden;
}

const bool& DrawableLayer::IsUpdatable() const
{
	return *this->updatable;
}

void DrawableLayer::hide(const bool& status)
{
	*this->hidden = status;
}

void DrawableLayer::make_unupdatable()
{
	*this->updatable = false;
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
		if (!object->IsHidden())
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
	delete this->hidden;

	std::vector<DrawableObject*>::iterator it;
	for (it = this->layer->begin(); it != this->layer->end(); it++) delete* it;
	delete this->layer;	
}