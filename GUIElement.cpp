#include "GUIElement.h"

GUIElement::GUIElement()
{
	this->hidden = new bool(0);
	this->enabled = new bool(1);
}

void GUIElement::destroy(GUIElement* element)
{
	if (element) delete dynamic_cast<GUIElement*>(element);
	element = 0;
}

void GUIElement::show(const bool& status)
{
	*this->hidden = !status;
}
void GUIElement::set_enabled(const bool& status)
{
	*this->enabled = status;
}

const bool& GUIElement::IsHidden() const
{
	return *this->hidden;
}
const bool& GUIElement::IsEnabled() const
{
	return *this->enabled;
}

GUIElement::~GUIElement()
{
	delete this->drawable_object;
	delete this->hidden;
	delete this->enabled;
}