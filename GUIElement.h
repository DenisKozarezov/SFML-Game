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

	virtual void show(const bool& status);
	virtual void set_position(const Vector2& position) = 0;
	void set_enabled(const bool& status);

	const bool& IsHidden() const;
	const bool& IsEnabled() const;
	const Vector2& get_position() const;

	virtual ~GUIElement();
protected:
	sf::Drawable* drawable_object;
	Vector2* position;

	virtual void input_update(sf::Event& event) = 0;	
};
#endif