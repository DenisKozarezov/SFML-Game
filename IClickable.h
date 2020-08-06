#ifndef _ICLICKABLE_H_
#define _ICLICKABLE_H_
#include "SFML/Graphics.hpp"
#include "Delegate.h"
#include "struct.h"

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

	virtual ~IClickable();
protected:
	const static bool& IsHover(const Rect& rectangle, const Vector2& mousePosition);
};
#endif