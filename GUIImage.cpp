#include "GUIImage.h"

GUIImage::GUIImage(const Rect& rectangle, const sf::Texture image)
{
	*this->position = Vector2(rectangle.x, rectangle.y);
	this->label = new Sprite;
	this->texture = new sf::Texture;
	*this->texture = image;
	this->label->setPosition(rectangle.x, rectangle.y);
	this->label->setTexture(image);
	set_width(rectangle.width);
	set_height(rectangle.height);
	this->drawable_object = this->label;
	GUI::add(this);
}

void GUIImage::set_width(const float& width)
{
	float factor = width / this->label->getTexture()->getSize().x;
	this->label->setScale(factor, this->label->getScale().y);
}
void GUIImage::set_height(const float& height)
{
	float factor = height / this->label->getTexture()->getSize().y;
	this->label->setScale(this->label->getScale().x, factor);
}
void GUIImage::set_size(const Vector2& size)
{
	set_width(size.x);
	set_height(size.y);
}
void GUIImage::set_size(const float& width, const float& height)
{
	set_size(Vector2(width, height));
}
void GUIImage::set_position(const Vector2& position)
{
	*this->position = position;
	this->label->setPosition(position.x, position.y);
}
void GUIImage::set_position(const float& x, const float& y)
{
	this->label->setPosition(x, y);
}
void GUIImage::set_texture(const sf::Texture& texture)
{
	*this->texture = texture;
	this->label->setTexture(texture);
}

const Vector2& GUIImage::get_size() const
{
	return Vector2(this->label->getTexture()->getSize().x, this->label->getTexture()->getSize().y);
}
const sf::Texture& GUIImage::get_texture() const
{
	return *this->label->getTexture();
}

void GUIImage::input_update(sf::Event& event)
{
}

GUIImage::~GUIImage()
{
	delete this->label;
	delete this->texture;
}
