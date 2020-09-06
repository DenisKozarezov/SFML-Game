#include "GUITextField.h"

void GUITextField::initialize()
{
	this->hover = new bool(0);
	this->interactable = new bool(1);
	this->selected = new bool(0);
	this->isMultiline = new bool(0);
	this->isReadOnly = new bool(0);

	this->background = new Background;
	this->characters_limit = new unsigned short(0);
	this->size = new Vector2;
	this->current = this->background->passive;

	this->clock = new sf::Clock;
	this->textEntered = new bool(0);

	this->OnClick = new Delegate<void>;
	this->OnDisabled = new Delegate<void>;
	this->OnPointerEnter = new Delegate<void>;
	this->OnPointerExit = new Delegate<void>;
	this->OnValueChanged = new Delegate<void>;
}

GUITextField::GUITextField(const Rect& rectangle)
{
	initialize();
	set_size(rectangle.width, rectangle.height);
	set_position(rectangle.x, rectangle.y);
	this->current->setPosition(rectangle.x, rectangle.y);
	this->drawable_object = this->current;
	GUI::add(this);
	this->text = new GUIText(rectangle.x, rectangle.y, "");
	set_characters_limit(rectangle.width / this->text->get_minimum_width());
}
GUITextField::GUITextField(const Rect& rectangle, const std::string& text)
{
	initialize();
	set_size(rectangle.width, rectangle.height);
	set_position(rectangle.x, rectangle.y);
	this->current->setPosition(rectangle.x, rectangle.y);
	this->drawable_object = this->current;
	GUI::add(this);
	this->text = new GUIText(rectangle.x, rectangle.y, text);
	set_characters_limit(rectangle.width / this->text->get_minimum_width());
}

void GUITextField::set_interactable(const bool& status)
{
	*this->interactable = status;
}
void GUITextField::set_multiline(const bool& status)
{
	*this->isMultiline = status;
}
void GUITextField::set_readonly(const bool& status)
{
	*this->isReadOnly = status;
}
void GUITextField::set_position(const Vector2& position)
{
	*this->position = position;
	this->current->setPosition(position.x, position.y);
	if (this->text) this->text->set_position(position);
}
void GUITextField::set_position(const float& x, const float& y)
{
	set_position(Vector2(x, y));
}
void GUITextField::set_size(const Vector2& size)
{
	*this->size = size;
	float factor_x = size.x / this->current->getTexture()->getSize().x;
	float factor_y = size.y / this->current->getTexture()->getSize().y;
	this->current->setScale(factor_x, factor_y);
}
void GUITextField::set_size(const float& width, const float& height)
{
	set_size(Vector2(width, height));
}
void GUITextField::set_characters_limit(const unsigned short& value)
{
	*this->characters_limit = value;
}

const bool& GUITextField::IsInteractable() const
{
	return *this->interactable;
}
const bool& GUITextField::IsSelected() const
{
	return *this->selected;
}
const bool& GUITextField::IsMultiline() const
{
	return *this->isMultiline;
}
const bool& GUITextField::IsReadOnly() const
{
	return *this->isReadOnly;
}
const Vector2& GUITextField::get_size() const
{
	return *this->size;
}
const std::string& GUITextField::get_text() const
{
	return this->text->get_text();
}
const unsigned short& GUITextField::get_characters_limit() const
{
	return *this->characters_limit;
}

void GUITextField::input_update(sf::Event& event)
{
    Vector2 mousePosition(sf::Mouse::getPosition(*Game::window).x, sf::Mouse::getPosition(*Game::window).y);
	if (Rect::contains(Rect(*this->position, *this->size), mousePosition) && *this->interactable && IsEnabled() && !IsHidden())
	{
		if (!*this->hover)
		{
			*this->hover = true;
			this->OnPointerEnter->invoke();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			*this->selected = true;
			GUI::focus(true);
		}
		else
		{
			if (*this->selected) this->OnClick->invoke();
		}
	}
	else
	{
		if (*this->hover)
		{
			*this->hover = false;
			this->OnPointerExit->invoke();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			*this->selected = false;
			GUI::focus(false);
		}
	}

	if (*this->selected && *this->interactable && IsEnabled() && !IsHidden())
	{
		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode == 8 && this->clock->getElapsedTime().asMilliseconds() >= 100)
			{
				this->clock->restart();
				this->text->set_text(this->text->get_text().substr(0, this->text->get_text().length() - 1));
				this->OnValueChanged->invoke();
				this->clock->restart();
			}
			else if (event.text.unicode != 8 && this->text->get_text().length() < *this->characters_limit && !*this->textEntered)
			{
				*this->textEntered = true;
				this->text->set_text(this->text->get_text() + static_cast<char>(event.text.unicode));
				this->OnValueChanged->invoke();	
			}
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			*this->textEntered = false;
		}
	}
}

GUITextField::~GUITextField()
{
	delete this->hover;
	delete this->interactable;
	delete this->selected;
	delete this->isMultiline;
	delete this->isReadOnly;

	delete this->text;
	delete this->background;
	delete this->characters_limit;
	delete this->size;

	delete this->clock;
	delete this->textEntered;

	delete this->OnClick;
	delete this->OnDisabled;
	delete this->OnPointerEnter;
	delete this->OnPointerExit;
	delete this->OnValueChanged;
}

GUITextField::Background::Background()
{
	this->selected = new Sprite;
	this->hover = new Sprite;
	this->passive = new Sprite;

	this->hover_texture = new sf::Texture;
	this->selected_texture = new sf::Texture;
	this->passive_texture = new sf::Texture;

	this->passive_texture->loadFromFile(GUIButtonStyle::Default);
	this->passive->setTexture(*this->passive_texture);
}

GUITextField::Background::~Background()
{
	delete this->hover;
	delete this->selected;
	delete this->passive;
	delete this->hover_texture;
	delete this->selected_texture;
	delete this->passive_texture;
}