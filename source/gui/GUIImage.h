#ifndef _GUIIMAGE_H_
#define _GUIIMAGE_H_
#include "../math/Vector2.h"
#include "../math/Rect.h"
#include "../components/sprite/Sprite.h"
#include "../math/Math.h"
#include "GUIElement.h"
#include "GUI.h"

class GUIImage final : public GUIElement
{
private:
	Sprite* label;
	sf::Texture* texture;
public:
	GUIImage(const Rect& rectangle, const sf::Texture image);

	void set_width(const float& width);
	void set_height(const float& height);
	void set_size(const Vector2& size);
	void set_size(const float& width, const float& height);
	void set_position(const Vector2& position) override;
	void set_position(const float& x, const float& y);
	void set_texture(const sf::Texture& texture);

	const Vector2& get_size() const;
	const sf::Texture& get_texture() const;

	void input_update(sf::Event& event) override;

	~GUIImage();
};
#endif