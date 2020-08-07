#include "GUIButton.h"
#include <iostream>

void GUIButton::initialize()
{
    this->active = new bool(0);
    this->hover = new bool(0);
    this->enabled = new bool(1);
    this->interactable = new bool(1);
    this->position = new Vector2;
    this->size = new Vector2;
    this->background = new Background();
    this->current = this->background->passive;
    this->current->setColor(sf::Color::White);

}

GUIButton::GUIButton(const Rect& rectangle)
{
    initialize();
    set_size(rectangle.width, rectangle.height);
    set_position(rectangle.x, rectangle.y);
    this->drawable_object = this->current;
    GUI::add(this);
    this->text = new GUIText;
    this->text->set_text("");
    this->text->set_position(rectangle.x + rectangle.width / 2 - this->text->get_size().x / 2, rectangle.y);
}
GUIButton::GUIButton(const Rect& rectangle, const std::string& text)
{
    initialize();
    set_size(rectangle.width, rectangle.height);
    set_position(rectangle.x, rectangle.y);
    this->current->setPosition(rectangle.x, rectangle.y);
    this->drawable_object = this->current;
    GUI::add(this);
    this->text = new GUIText;
    this->text->set_text(text);
    this->text->set_position(rectangle.x + rectangle.width / 2 - this->text->get_size().x / 2, rectangle.y);
}

void GUIButton::select()
{
}
void GUIButton::set_interactable(const bool& status)
{
    *this->interactable = status;
}
void GUIButton::set_text(const std::string& text)
{
    this->text->set_text(text);
    this->text->set_position(this->position->x + this->size->x / 2 - this->text->get_size().x / 2, this->position->y);
}
void GUIButton::set_image(const sf::Texture& texture)
{
    this->current->setTexture(texture);
}
void GUIButton::set_background(Background* background)
{
    this->background = background;
}
void GUIButton::set_position(const Vector2& position)
{
    *this->position = position;
    this->current->setPosition(position.x, position.y);
    if (this->text) this->text->set_position(position);
}
void GUIButton::set_position(const float& x, const float& y)
{
    set_position(Vector2(x, y));
}
void GUIButton::set_size(const Vector2& size)
{
    *this->size = size;
    float factor_x = this->current->getTexture()->getSize().x / size.x;
    float factor_y = this->current->getTexture()->getSize().y / size.y;
    this->current->setScale(factor_x, factor_y);

}
void GUIButton::set_size(const float& width, const float& height)
{
    set_size(Vector2(width, height));
}
void GUIButton::set_color(const sf::Color& color)
{
    this->background->active->setColor(color);
    this->background->hover->setColor(color);
    this->background->passive->setColor(color);
}
void GUIButton::set_color(const float& r, const float& g, const float& b, const float& a)
{
    set_color(sf::Color(r, g, b, a));
}

const bool& GUIButton::IsHover() const
{
    return *this->hover;
}
const bool& GUIButton::IsEnabled() const
{
    return *this->enabled;
}
const bool& GUIButton::IsInteractable() const
{
    return *this->interactable;
}
const std::string& GUIButton::get_text() const
{
    return this->text->get_text();
}
const GUIButton::Background* GUIButton::get_background()
{
    return this->background;
}
const Vector2& GUIButton::get_position()
{
    return *this->position;
}
const Vector2& GUIButton::get_size()
{
    return *this->size;
}
const sf::Color& GUIButton::get_color() const
{
    return this->current->getColor();
}

void GUIButton::input_update(sf::Event& event)
{
    Vector2 mousePosition(sf::Mouse::getPosition(*Game::window).x, sf::Mouse::getPosition(*Game::window).y);

    if (IClickable::IsHover(Rect(*this->position, *this->size), mousePosition) && *this->interactable && *this->enabled)
    {
        if (!*this->hover)
        {
            *this->hover = true;
            if (!this->OnPointerEnter->IsNull()) this->OnPointerEnter->invoke();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            *this->active = true;
            if (!this->OnActive->IsNull()) this->OnActive->invoke();
        }
        else
        {
            if (*this->active)
            {
                *this->active = false;
                if (!this->OnClick->IsNull()) this->OnClick->invoke();
                if (!this->OnMouseUp->IsNull()) this->OnMouseUp->invoke();
            }
        }
    }
    else
    {
        if (*this->hover)
        {
            *this->hover = false;
            if (!this->OnPointerExit->IsNull()) this->OnPointerExit->invoke();
        }
    }
    
    if (!*this->enabled)
    {
        if (!this->OnDisabled->IsNull()) this->OnDisabled->invoke();
    }
}

GUIButton::~GUIButton()
{
    delete this->active;
    delete this->interactable;
    delete this->enabled;
    delete this->text;
    delete this->position;
    delete this->size;
    delete this->current;
    delete this->background;
}

GUIButton::Background::Background()
{
    this->active = new Sprite;
    this->hover = new Sprite;
    this->passive = new Sprite;

    sf::Texture* passive = new sf::Texture;
    passive->loadFromFile(GUIButtonStyle::Default);
    this->passive->setTexture(*passive);
}

GUIButton::Background::~Background()
{
    delete this->hover;
    delete this->active;
    delete this->passive;
}
