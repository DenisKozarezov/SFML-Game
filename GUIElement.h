#ifndef _GUIELEMENT_H_
#define _GUIELEMENT_H_
#include "SFML/Graphics.hpp"

class GUIElement
{
private:
	friend class GUI;
public:
	GUIElement();

	static void destroy(GUIElement* element);

	virtual ~GUIElement();
protected:
	sf::Drawable* drawable_object;
	virtual void input_update(sf::Event& event) = 0;
};
#endif