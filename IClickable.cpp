#include "IClickable.h"

IClickable::IClickable()
{
	this->OnDisabled = new Delegate;
	this->OnClick = new Delegate;
	this->OnHover = new Delegate;
	this->OnActive = new Delegate;
	this->OnPointerEnter = new Delegate;
	this->OnPointerExit = new Delegate;
	this->OnPointerDown = new Delegate;
	this->OnPointerUp = new Delegate;
}

IClickable::~IClickable()
{
	delete this->OnDisabled;
	delete this->OnClick;
	delete this->OnHover;
	delete this->OnActive;
	delete this->OnPointerEnter;
	delete this->OnPointerExit;
	delete this->OnPointerDown;
	delete this->OnPointerUp;
}
