#ifndef _GUI_H_
#define _GUI_H_
#include <vector>
#include "DrawableLayer.h"
#include "GUIText.h"
#include "GUIImage.h"

class GUI final
{
private:
	friend class GUIText;
	friend class GUIImage;

	bool* hidden;
	
	std::vector<sf::Drawable*>* text;

	static GUI* instance;

	GUIText* hp;
	GUIText* mp;
	GUIText* damage;

	static void add(sf::Drawable* object);

	GUI();
	GUI& operator=(const GUI&) = delete;
public:
	static GUI* get_instance();

	const bool& IsHidden() const;

	static void show(const bool& status);
	void initialize();

	void update(sf::RenderWindow& window);
};
#endif