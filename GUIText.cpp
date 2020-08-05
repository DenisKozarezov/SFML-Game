#include "GUIText.h"
#include "DrawableContainer.h"

void GUIText::initialize()
{
	this->gui_text = new sf::Text;
	this->color = new sf::Color(sf::Color::White);
	this->gui_text->setFillColor(sf::Color::White);
	sf::Font font;
	font.loadFromFile(Fonts::Consola);
	this->gui_text->setFont(font);
	DrawableObject::initialize(this, "GUI-dynamic");
}

GUIText::GUIText(const Vector2& position, const std::string& text)
{
	initialize();
	this->text = new std::string(text);
	set_screen_position(position);
	this->gui_text->setString(text);
	this->gui_text->setPosition(position.x, position.y);

}
GUIText::GUIText(const float& x, const float& y, const std::string& text)
{
	initialize();
	this->text = new std::string(text);
	set_screen_position(x, y);
	this->gui_text->setString(text);
	this->gui_text->setPosition(x, y);
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

void GUIText::update(sf::RenderWindow& window)
{
	
}

sf::Drawable* GUIText::get_drawable_object()
{
	return this->gui_text;
}

GUIText::~GUIText()
{
	delete this->gui_text;
	delete this->color;
}