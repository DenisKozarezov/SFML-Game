#pragma once
#include "SFML/Graphics.hpp"
#include "Unit.h"

class Math
{
public:
	const static float& get_factor(const float& factor);

	const static float& scalar(const sf::Vector2f& vector1, const sf::Vector2f& vector2);

	const static float& length(const sf::Vector2f& vector);

	const static float& distance(const sf::Vector2f& vector1, const sf::Vector2f& vector2);

	const static sf::Vector2f& normalize(const sf::Vector2f& vector);
	const static sf::Vector2f& magnitude(const sf::Vector2f& vector, const float& length);

	const static float& angle(const sf::Vector2f& vector1, const sf::Vector2f& vector2);

	const static float& lerp(const float& value1, const float& value2, const float& factor);
	const static sf::Vector2f& lerp(const sf::Vector2f& vector1, const sf::Vector2f& vector2, const float& factor);
	const static sf::Color& lerp(const sf::Color& color1, const sf::Color& color2, const float& factor);

	const static float& percent_of(const float& factor, const float& value);
};

