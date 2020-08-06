#include "GUITextField.h"

void GUITextField::initialize()
{
	this->interactable = new bool(1);
	this->selected = new bool(0);
	this->focused = new bool(0);
	this->background = new Sprite;
	this->background->setColor(sf::Color::White);
}

GUITextField::GUITextField(const Rect& rectangle)
{
	initialize();
	this->text = new GUIText(rectangle.x, rectangle.y, "");
	this->background->setPosition(rectangle.x, rectangle.y);
	sf::Texture texture;
	texture.create(rectangle.width, rectangle.height);
	this->background->setTexture(texture);
	this->drawable_object = this->background;
	GUI::add(this);
}

GUITextField::GUITextField(const Rect& rectangle, const std::string& text)
{
	initialize();
	this->text = new GUIText(rectangle.x, rectangle.y, text);
	this->background->setPosition(rectangle.x, rectangle.y);
	sf::Texture texture;
	texture.create(rectangle.width, rectangle.height);
	this->background->setTexture(texture);
	this->drawable_object = this->background;
	GUI::add(this);
}

void GUITextField::set_interactable(const bool& status)
{
	*this->interactable = status;
}
void GUITextField::set_position(const Vector2& position)
{
	this->text->set_position(position);
	this->background->setPosition(position.x, position.y);
}
void GUITextField::set_position(const float& x, const float& y)
{
	set_position(Vector2(x, y));
}
void GUITextField::set_text(const std::string& text)
{
	this->text->set_text(text);
}

const bool& GUITextField::IsInteractable() const
{
	return *this->interactable;
}
const bool& GUITextField::IsSelected() const
{
	return *this->selected;
}
const Vector2& GUITextField::get_position() const
{
	return this->text->get_position();
}
const std::string& GUITextField::get_text() const
{
	return this->text->get_text();
}

GUITextField::~GUITextField()
{
	delete this->interactable;
	delete this->selected;
	delete this->focused;
	delete this->text;
	delete this->background;
}
