#pragma once
#include "SFML/Graphics.hpp"

class Math
{
public:
	const static float& get_factor(const float& factor);

	const static float& limit(const float& value, const float& limit);

	const static float& lerp(const float& value1, const float& value2, const float& factor);
	const static sf::Color& lerp(const sf::Color& color1, const sf::Color& color2, const float& factor);

	const static float& percent_of(const float& factor, const float& value);
};

