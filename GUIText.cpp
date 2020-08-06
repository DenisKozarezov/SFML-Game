#include "GUIText.h"
#include "DrawableContainer.h"
#include "GUI.h"

void GUIText::initialize()
{
	this->gui_text = new sf::Text;
	this->gui_text->setFillColor(sf::Color::White);
	this->gui_text->setCharacterSize(24);
	this->gui_text->setStyle(sf::Text::Bold);
	
	font = new sf::Font;
	font->loadFromFile(Fonts::Consola);
	this->gui_text->setFont(*font);
}

GUIText::GUIText(const Vector2& position, const std::string& text)
{
	initialize();
	this->gui_text->setString(text);
	this->gui_text->setPosition(position.x, position.y);
	this->drawable_object = this->gui_text;
	GUI::add(this);
}
GUIText::GUIText(const float& x, const float& y, const std::string& text)
{
	initialize();
	this->gui_text->setString(text);
	this->gui_text->setPosition(x, y);
	GUI::add(this);
}

void GUIText::set_color(const sf::Color& color)
{
	this->gui_text->setFillColor(color);
}
void GUIText::set_color(const float& r, const float& g, const float& b, const float& a)
{
	this->gui_text->setFillColor(sf::Color(r, g, b, a));
}
void GUIText::set_scale(const float& factor_x, const float& factor_y)
{
	this->gui_text->setScale(factor_x, factor_y);
}
void GUIText::set_font(const sf::Font& font)
{
	this->gui_text->setFont(font);
}
void GUIText::set_style(const sf::Text::Style& style)
{
	this->gui_text->setStyle(style);
}
void GUIText::set_text(const std::string& text)
{
	this->gui_text->setString(text);
}
void GUIText::set_size(const unsigned short& size)
{
	this->gui_text->setCharacterSize(size);
}

void GUIText::attach_to(DrawableObject* object)
{
	this->object = object;
}

const sf::Color& GUIText::get_color() const
{
	return this->gui_text->getFillColor();
}
const Vector2& GUIText::get_scale() const
{
	return Vector2(this->gui_text->getScale().x, this->gui_text->getScale().y);
}
const sf::Font& GUIText::get_font() const
{
	return *this->gui_text->getFont();
}
const sf::Uint32& GUIText::get_style() const
{
	return this->gui_text->getStyle();
}
const std::string& GUIText::get_text() const
{
	return this->gui_text->getString();
}
const unsigned short& GUIText::get_size() const
{
	return this->gui_text->getCharacterSize();
}

void GUIText::input_update(sf::Event& event)
{
}

GUIText::~GUIText()
{
	delete this->gui_text;
	delete this->font;
}