#include "DrawableLayer.h"

DrawableLayer::DrawableLayer()
{
	this->hidden = new bool(0);
	this->updatable = new bool(1);
	this->layer = new std::list<GameObject*>;
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

void DrawableLayer::add(GameObject* object)
{
	this->layer->push_back(object);
}
template<typename T>
void DrawableLayer::remove_group(const T& type)
{

}
void DrawableLayer::remove(GameObject* object)
{
	std::list<GameObject*>::iterator first = this->layer->begin();
	std::list<GameObject*>::iterator last = this->layer->end();
	std::list<GameObject*>::iterator it = std::find(first, last, object);
	if (it != last) this->layer->erase(it);
}
const bool& DrawableLayer::contains(GameObject* object) const
{
	std::list<GameObject*>::iterator first = this->layer->begin();
	std::list<GameObject*>::iterator last = this->layer->end();
	std::list<GameObject*>::iterator it = std::find(first, last, object);
	return it != last;
}

void DrawableLayer::update(sf::RenderWindow& window)
{
	for (auto& object : *this->layer)
	{
		if (!object->IsHidden())
		{
			object->update();
			window.draw(*object->get_sprite());
		}
	}
}

std::list<GameObject*>* DrawableLayer::get_layer()
{
	return this->layer;
}

DrawableLayer::~DrawableLayer()
{
	delete this->hidden;
	delete this->updatable;

	for (auto& object : *this->layer) delete object;
	delete this->layer;	
}