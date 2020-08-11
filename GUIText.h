#ifndef _GUITEXT_H_
#define _GUITEXT_H_
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "Vector2.h"
#include "Resources.cpp"
#include "GUIElement.h"

class GUIText final : public GUIElement
{
private:
	sf::Text* gui_text;

	std::string* text;
	sf::Font* font;

	void initialize();	
	void input_update(sf::Event& event) override;
public:
	GUIText();
	GUIText(const Vector2& position, const std::string& text);
	GUIText(const float& x, const float& y, const std::string& text);

	void set_position(const Vector2& position) override;
	void set_position(const float& x, const float& y);
	void set_color(const sf::Color& color);
	void set_color(const float& r, const float& g, const float& b, const float& a);
	void set_scale(const float& factor_x, const float& factor_y);
	void set_font(const sf::Font& font);
	void set_style(const sf::Text::Style& style);
	void set_text(const std::string& text);
	void set_font_size(const unsigned short& size);

	void attach_to(GameObject* object);

	const sf::Color& get_color() const;
	const Vector2& get_scale() const;
	const sf::Font& get_font() const;
	const sf::Uint32& get_style() const;
	const std::string& get_text() const;
	const unsigned short& get_font_size() const;
	const Vector2& get_size() const;
	const float& get_minimum_width() const;

	~GUIText();
};
#endif