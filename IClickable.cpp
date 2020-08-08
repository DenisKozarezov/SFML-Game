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
	this->OnValueChanged = new Delegate;
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
	delete this->OnValueChanged;
}
