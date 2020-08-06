#pragma once
#include "SFML/Graphics.hpp"

class GUIElement
{
private:
	sf::Drawable* drawable_object;
public:
	GUIElement() = default;

	virtual void update() = 0;

	virtual ~GUIElement() = 0;
};

