#ifndef _COLLISION_H_
#define _COLLISION_H_
#include "Vector2.h"
#include "GameObject.h"
#include "Delegate.h"
#include <vector>

class Collision
{
private:
	friend class GUI;
	friend class Game;
	bool* isTrigger;
	bool* enabled;
	bool* showOutline;
	bool* collided;

	GameObject* object;	

	static std::vector<Collision*>* colliders;

	static void check_collision();
	virtual void set_outline_color(const sf::Color& color) = 0;
public:
	Collision();

	Delegate* OnCollisionEnter;
	Delegate* OnCollisionExit;
	Delegate* OnTriggerEnter;
	Delegate* OnTriggerExit;

	void set_trigger(const bool& status);
	void set_enabled(const bool& status);
	virtual void set_position(const Vector2& position);
	void set_object(GameObject* object);
	void show_outline(const bool& status);

	const bool& IsTrigger() const;
	const bool& IsEnabled() const;
	const bool& IsCollided() const;
	const Vector2& get_position() const;
	GameObject* get_object() const;

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