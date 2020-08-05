#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "Resources.cpp"
#include "DrawableObject.h"

class GUIText final : DrawableObject
{
private:
	sf::Text* gui_text;

	std::string* text;
	sf::Color* color;
	DrawableObject* object;

	void initialize();
public:
	GUIText(const Vector2& position, const std::string& text);
	GUIText(const float& x, const float& y, const std::string& text);

	void set_color(const sf::Color& color);
	void set_color(const float& r, const float& g, const float& b, const float& a);
	void set_scale(const float& factor_x, const float& factor_y);
	void set_font(const sf::Font& font);
	
	void attach_to(DrawableObject* object);

	const sf::Color& get_color() const;
	const Vector2& get_scale() const;
	const sf::Font& get_font() const;

	void update(sf::RenderWindow& window) override;
	sf::Drawable* get_drawable_object() override;

	~GUIText();
};

