#ifndef _ICLICKABLE_H_
#define _ICLICKABLE_H_
#include "SFML/Graphics.hpp"
#include "Delegate.h"
#include "Rect.h"

class IClickable
{
public:
	IClickable();

	Delegate* OnDisabled;
	Delegate* OnClick;
	Delegate* OnHover;
	Delegate* OnActive;
	Delegate* OnPointerEnter;
	Delegate* OnPointerExit;
	Delegate* OnMouseDown;
	Delegate* OnMouseUp;	
	Delegate* OnValueChanged;

	virtual ~IClickable();
};
#endif