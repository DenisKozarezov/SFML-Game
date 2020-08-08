#ifndef _GUIELEMENT_H_
#define _GUIELEMENT_H_
#include "SFML/Graphics.hpp"
#include "Vector2.h"

class GUIElement
{
private:
	friend class GUI;

	bool* hidden;
	bool* enabled;
public:
	GUIElement();

	static void destroy(GUIElement* element);

	void show(const bool& status);
	void set_enabled(const bool& status);

	const bool& IsHidden() const;
	const bool& IsEnabled() const;

	virtual ~GUIElement();
protected:
	sf::Drawable* drawable_object;

	virtual void input_update(sf::Event& event) = 0;	
};
#endif