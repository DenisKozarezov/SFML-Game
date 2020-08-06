#pragma once
#include "Delegate.h"

class IClickable
{
protected:
	IClickable();

	Delegate* OnDisabled;
	Delegate* OnClick;
	Delegate* OnHover;
	Delegate* OnActive;
	Delegate* OnPointerEnter;
	Delegate* OnPointerExit;
	Delegate* OnPointerDown;
	Delegate* OnPointerUp;

	virtual ~IClickable();
};