#include "GUIElement.h"

GUIElement::GUIElement()
{
}

void GUIElement::destroy(GUIElement* element)
{
	if (element) delete dynamic_cast<GUIElement*>(element);
	element = 0;
}

GUIElement::~GUIElement()
{
	delete this->drawable_object;
}


