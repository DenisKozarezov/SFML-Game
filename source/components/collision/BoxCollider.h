#ifndef _BOXCOLLIDER_H_
#define _BOXCOLLIDER_H_
#include "Collision.h"
#include "../../math/Rect.h"
#include "../../math/Vector2.h"
#include "../../gui/GUI.h"

class BoxCollider : public Collision
{
private:
	Vector2* size;
	Vector2* points[4];

	void initialize();
	void set_outline_color(const sf::Color& color) override;
public:
	BoxCollider();
	BoxCollider(const Vector2& position, const Vector2& size);

	void set_position(const Vector2& position) override;
	void set_position(const float& x, const float& y);
	void set_size(const Vector2& size);
	void set_size(const float& width, const float& height);

	const Vector2& get_size() const;

	const bool& intersects(Collision* collider) const override;
	const bool& contains(const Vector2& point) const override;

	~BoxCollider();
};
#endif