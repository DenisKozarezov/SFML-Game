#include "GUIPanel.h"

void GUIPanel::add(GUIElement* element)
{
	this->items->push_back(element);
}
void GUIPanel::remove(GUIElement* element)
{
	std::list<GUIElement*>::iterator first = this->items->begin();
	std::list<GUIElement*>::iterator last = this->items->end();
	std::list<GUIElement*>::iterator find = std::find(first, last, element);
	if (find != last) this->items->erase(find);
}
void GUIPanel::remove(const unsigned short& index)
{
	std::list<GUIElement*>::iterator it = this->items->begin();
	std::advance(it, index);
	this->items->erase(it);
}
void GUIPanel::show(const bool& status)
{
	GUIElement::show(status);
	for (auto item : *this->items) item->show(status);
}

void GUIPanel::set_position(const Vector2& position)
{
	*this->position = position;
	for (auto item : *this->items)
	{
		Vector2 position(position - item->get_position());
		item->set_position(item->get_position() + position);
	}
}
void GUIPanel::set_position(const float& x, const float& y)
{
	set_position(Vector2(x, y));
}
