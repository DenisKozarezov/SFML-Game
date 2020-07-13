#include "Math.h"

const float& Math::length(const sf::Vector2f& vector)
{
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}

const float& Math::distance(const sf::Vector2f& vector1, const sf::Vector2f& vector2)
{
	return sqrt(pow(vector1.x - vector2.x, 2) + pow(vector1.y - vector2.y, 2));
}

const float& Math::angle(const sf::Vector2f& vector1, const sf::Vector2f& vector2)
{
	const float& scalar = Math::scalar(vector1, vector2);
	return scalar / (length(vector1) * length(vector2));
}

const float& Math::get_factor(const float& factor)
{
	float _factor = factor;
	if (factor < 0) _factor = 0;
	if (factor > 1) _factor = 1;
	return _factor;
}
const float& Math::scalar(const sf::Vector2f& vector1, const sf::Vector2f& vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y;
}
const float& Math::lerp(const float& value1, const float& value2, const float& factor)
{
	return (value2 - value1) * get_factor(factor);
}
const sf::Vector2f& Math::lerp(const sf::Vector2f& vector1, const sf::Vector2f& vector2, const float& factor)
{
	const float& _factor = get_factor(factor);
	const float& lerp_x = vector2.x - vector1.x;
	const float& lerp_y = vector2.y - vector1.y;
	return sf::Vector2f(lerp_x * _factor, lerp_y * _factor);
}
const sf::Color& Math::lerp(const sf::Color& color1, const sf::Color& color2, const float& factor)
{
	const float& _factor = get_factor(factor);
	const float& color_r = color2.r - color1.r;
	const float& color_g = color2.g - color1.g;
	const float& color_b = color2.b - color1.b;
	const float& color_a = color2.a - color1.a;
	return sf::Color(
		  color_r * _factor,
		  color_g * _factor,
		  color_b * _factor,
		  color_a * _factor
	);
}

const float& Math::percent_of(const float& factor, const float& value)
{
	return factor * value;
}