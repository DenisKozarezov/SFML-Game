#ifndef _GUIPANEL_H_
#define _GUIPANEL_H_
#include <vector>
#include "GUIElement.h"

class GUIPanel : public GUIElement
{
private:
	std::vector<GUIElement*>* items;
public:
	void add(GUIElement* element);
	void remove(GUIElement* element);
	void remove(const unsigned short& index);
	void show(const bool& status) override;
	void set_position(const Vector2& position) override;
	void set_position(const float& x, const float& y);

	GUIElement* get_item(const unsigned short& index);
};
#endif