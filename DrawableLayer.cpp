#include "DrawableLayer.h"

DrawableLayer::DrawableLayer()
{
	this->hidden = new bool(0);
	this->updatable = new bool(1);
	this->layer = new std::vector<GameObject*>;
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
	std::vector<GameObject*>::iterator first = this->layer->begin();
	std::vector<GameObject*>::iterator last = this->layer->end();
	std::vector<GameObject*>::iterator it = std::find(first, last, object);
	if (it != last) this->layer->erase(it);
}
const bool& DrawableLayer::is_contain(GameObject* object) const
{
	std::vector<GameObject*>::iterator first = this->layer->begin();
	std::vector<GameObject*>::iterator last = this->layer->end();
	std::vector<GameObject*>::iterator it = std::find(first, last, object);
	return it != last;
}

void DrawableLayer::update(sf::RenderWindow& window)
{
	std::vector<GameObject*>::iterator it;
	for (it = this->layer->begin(); it != this->layer->end(); it++)
	{
		GameObject* object = dynamic_cast<GameObject*>(*it);
		if (!object->IsHidden())
		{
			object->update();
			window.draw(*object->get_sprite());
		}
	}
}

std::vector<GameObject*>* DrawableLayer::get_layer()
{
	return this->layer;
}

DrawableLayer::~DrawableLayer()
{
	delete this->hidden;

	std::vector<GameObject*>::iterator it;
	for (it = this->layer->begin(); it != this->layer->end(); it++) delete* it;
	delete this->layer;	
}