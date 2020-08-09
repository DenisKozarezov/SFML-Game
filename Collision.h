#ifndef _COLLISION_H_
#define _COLLISION_H_
#include "Vector2.h"
#include "DrawableObject.h"
#include <vector>

class Collision
{
private:
	friend class GUI;
	bool* isTrigger;
	bool* enabled;
	bool* showOutline;

	DrawableObject* object;	
	static std::vector<Collision*>* colliders;
public:
	Collision();

	void set_trigger(const bool& status);
	void set_enabled(const bool& status);
	virtual void set_position(const Vector2& position);
	void show_outline(const bool& status);

	const bool& IsTrigger() const;
	const bool& IsEnabled() const;
	const Vector2& get_position() const;
	DrawableObject* get_object();

	const virtual bool& IsCollided() const;

	const virtual bool& intersects(Collision* collider) const = 0;
	const virtual bool& contains(const Vector2& point) const = 0;

	virtual ~Collision();
protected:
	Vector2* position;
	sf::Drawable* outline;
};
const bool& operator==(const Collision& collision1, const Collision& collision2);
const bool& operator!=(const Collision& collision1, const Collision& collision2);
#endif