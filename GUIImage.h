#pragma once
#include "Vector2.h"
#include "GUIText.h"
#include "struct.h"

class GUIImage final
{
private:
	Sprite* label;
public:
	GUIImage(const Rect& rectangle, const sf::Texture& image);

	void set_width(const float& width);
	void set_height(const float& height);
	void set_size(const Vector2& size);
	void set_size(const float& width, const float& height);
	void set_position(const Vector2& position);
	void set_position(const float& x, const float& y);
	void set_texture(const sf::Texture& texture);

	const Vector2& get_size() const;
	const Vector2& get_position() const;
	const sf::Texture& get_texture() const;

	~GUIImage();
};

