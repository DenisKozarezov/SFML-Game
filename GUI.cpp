#include "GUI.h"
#include "DrawableContainer.h"

GUI* GUI::instance = 0;

GUI::GUI()
{
	this->hidden = new bool(0);
	gui_layer = DrawableContainer::get_GUI();
}
GUI* GUI::get_instance()
{
	if (!instance) instance = new GUI;
	return instance;
}

const bool& GUI::IsHidden() const
{
	return *this->hidden;
}

void GUI::show(const bool& status)
{
	*this->hidden = status;
}
