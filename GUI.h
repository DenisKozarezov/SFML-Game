#ifndef _GUI_H_
#define _GUI_H_
#include <list>
#include "GUIElement.h"
#include "Collision.h"

class GUI final
{
private:
	bool* hidden;
	bool* focused;
	
	std::list<GUIElement*>* elements;
	std::list<Collision*>* colliders;

	static GUI* instance;

	GUI();

	GUI& operator=(const GUI&) = delete;
public:
	static void add(GUIElement* element);
	static void add(Collision* collider);
	static void show(const bool& status);
	static void focus(const bool& status);
	void initialize();

	static GUI* get_instance();

	const static bool& IsHidden();
	const static bool& IsFocused();

	void update(sf::RenderWindow& window, sf::Event& event);
};
#endif