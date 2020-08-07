#include "IClickable.h"

IClickable::IClickable()
{
	this->OnDisabled = new Delegate;
	this->OnClick = new Delegate;
	this->OnHover = new Delegate;
	this->OnActive = new Delegate;
	this->OnPointerEnter = new Delegate;
	this->OnPointerExit = new Delegate;
	this->OnMouseDown = new Delegate;
	this->OnMouseUp = new Delegate;
}

const bool& IClickable::IsHover(const Rect& rectangle, const Vector2& mousePosition)
{
	float min_x = rectangle.x;
	float max_x = rectangle.x + rectangle.width;
	float min_y = rectangle.y;
	float max_y = rectangle.y + rectangle.height;
	return mousePosition.x >= min_x && mousePosition.x <= max_x && mousePosition.y >= min_y && mousePosition.y <= max_y;
}

IClickable::~IClickable()
{
	delete this->OnDisabled;
	delete this->OnClick;
	delete this->OnHover;
	delete this->OnActive;
	delete this->OnPointerEnter;
	delete this->OnPointerExit;
	delete this->OnMouseDown;
	delete this->OnMouseUp;
}
