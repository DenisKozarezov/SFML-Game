#include "GUIButton.h"

void GUIButton::initialize()
{
    this->hover = new bool(0);
    this->active = new bool(0);
    this->interactable = new bool(0);
    this->background = new Background();
    this->background->hover = new sf::Texture;
    this->background->active = new sf::Texture;
    this->background->passive = new sf::Texture;
    this->current = new Sprite;
}

GUIButton::GUIButton(const Rect& rectangle)
{
    initialize();
    this->text = new GUIText(rectangle.x, rectangle.y, "");
    this->position = new Vector2(rectangle.x, rectangle.y);
    this->size = new Vector2(rectangle.width, rectangle.height);
    sf::Texture texture;
    texture.create(rectangle.width, rectangle.height);
    this->current->setTexture(texture);
    this->current->setColor(sf::Color::White);
    this->current->setPosition(rectangle.x, rectangle.y);
    this->drawable_object = this->current;
    GUI::add(this);
}
GUIButton::GUIButton(const Rect& rectangle, const std::string& text)
{
    initialize();
    this->text = new GUIText(rectangle.x, rectangle.y, text);
    this->position = new Vector2(rectangle.x, rectangle.y);
    sf::Texture texture;
    texture.create(rectangle.width, rectangle.height);
    this->current->setTexture(texture);
    this->current->setColor(sf::Color::White);
    this->size = new Vector2(rectangle.width, rectangle.height);
    this->current->setPosition(rectangle.x, rectangle.y);
    this->drawable_object = this->current;
    GUI::add(this);
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
void GUIButton::set_action(Action action)
{
    this->action = action;
}
template<typename... Args>
void GUIButton::invoke(Args... args)
{
    if (this->action) this->action(args...);
}

const bool& GUIButton::IsHover() const
{
    sf::FloatRect rect(sf::Vector2f(this->position->x, this->position->y), sf::Vector2f(this->size->x, this->size->y));
    return rect.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}
const bool& GUIButton::IsActive() const
{
    return *this->active;
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
    return Vector2(this->current->getPosition().x, this->current->getPosition().y);
}
const Vector2& GUIButton::get_size()
{
    return Vector2(this->current->getTexture()->getSize().x, this->current->getTexture()->getSize().y);
}

GUIButton::~GUIButton()
{
    delete this->interactable;
    delete this->text;
    delete this->position;
    delete this->size;
    delete this->current;
    delete this->background;
}

void GUIButton::input_update(sf::Event& event)
{
    if (this->IsHover())
    {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
        {
            if (this->action) invoke();
        }
    }
}

GUIButton::Background::~Background()
{
    delete this->hover;
    delete this->active;
    delete this->passive;
}
