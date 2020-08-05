#include "GUIImage.h"

GUIImage::GUIImage(const Rect& rectangle, const sf::Texture image)
{
	this->label = new Sprite;
	this->label->setPosition(rectangle.x, rectangle.y);
	this->label->setTexture(image);
	GUI::add(this->label);
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
	this->label->setPosition(position.x, position.y);
}
void GUIImage::set_position(const float& x, const float& y)
{
	this->label->setPosition(x, y);
}
void GUIImage::set_texture(const sf::Texture& texture)
{
	this->label->setTexture(texture);
}

void GUIImage::update()
{

}

const Vector2& GUIImage::get_size() const
{
	return Vector2(this->label->getTexture()->getSize().x, this->label->getTexture()->getSize().y);
}
const Vector2& GUIImage::get_position() const
{
	return Vector2(this->label->getPosition().x, this->label->getPosition().y);
}
const sf::Texture& GUIImage::get_texture() const
{
	return *this->label->getTexture();
}
