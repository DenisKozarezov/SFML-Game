#ifndef _GUI_H_
#define _GUI_H_
#include <vector>
#include "GUIElement.h"

class GUI final
{
private:
	bool* hidden;
	bool* focused;
	
	std::vector<GUIElement*>* text;

	static GUI* instance;

	void update();

	GUI();

	GUI& operator=(const GUI&) = delete;
public:
	static void add(GUIElement* element);
	static void show(const bool& status);
	static void focus(const bool& status);
	void initialize();

	static GUI* get_instance();

	const static bool& IsHidden();
	const static bool& IsFocused();

	void update(sf::RenderWindow& window, sf::Event& event);
};
#endif