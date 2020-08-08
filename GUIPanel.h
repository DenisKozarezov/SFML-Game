#ifndef _GUIPANEL_H_
#define _GUIPANEL_H_
#include <vector>
#include "GUIElement.h"

class GUIPanel : public GUIElement
{
private:
	std::vector<GUIElement*> items;
public:
	void add(GUIElement* element);
	void remove(GUIElement* element);
	void remove(const unsigned short& index);
	void open();
	void close();
};
#endif