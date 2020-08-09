#ifndef _GUITOOGLEL_H_
#define _GUITOOGLE_H_
#include "GUIElement.h"
#include "Vector2.h"
#include "Rect.h"

class GUIToogle : public GUIElement
{
private:
	bool* interactable;

	Vector2* size;
public:
	GUIToogle(const Rect& rectangle, const bool& value);
	
	void set_value(const bool& status);
	void set_interactable(const bool& status);
	void set_position(const Vector2& position) override;
	void set_position(const float& x, const float& y);

	const bool& get_value() const;
	const bool& IsInteractable() const;
};
#endif