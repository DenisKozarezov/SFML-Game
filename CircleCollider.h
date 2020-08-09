#ifndef _CIRCLECOLLIDER_H_
#define _CIRCLECOLLIDER_H_
#include "Collision.h"
#include "Vector2.h"

class CircleCollider : public Collision
{
private:
	float* radius;

	void initialize();
public:
	CircleCollider();
	CircleCollider(const Vector2& position, const float& radius);

	void set_radius(const float& radius);
	void set_position(const Vector2& position) override;
	void set_position(const float& x, const float& y);

	const float& get_radius() const;

	const bool& intersects(Collision* collider) const override;

	const bool& contains(const Vector2& point) const override;

	~CircleCollider();
};
#endif