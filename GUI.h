#ifndef _GUI_H_
#define _GUI_H_
#include <vector>
#include "GUIText.h"
#include "GUIElement.h"
#include "GUIImage.h"
#include "GUIButton.h"

class GUI final
{
private:
	friend class GUIText;
	friend class GUIImage;
	friend class GUIButton;

	bool* hidden;
	
	std::vector<GUIElement*>* text;

	static GUI* instance;

	GUIText* hp;
	GUIText* mp;
	GUIText* damage;

	static void add(GUIElement* element);

	GUI();
	GUI& operator=(const GUI&) = delete;
public:
	static GUI* get_instance();

	const bool& IsHidden() const;

	static void show(const bool& status);
	void initialize();

	void graphics_update(sf::RenderWindow& window);
	void update(sf::RenderWindow& window, sf::Event& event);
};
#endif