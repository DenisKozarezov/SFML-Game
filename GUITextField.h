#ifndef _GUITEXTFIELD_H_
#define _GUITEXTFIELD_H_
#include "GUIElement.h"
#include "GUIImage.h"
#include "IClickable.h"
#include "GUI.h"

class GUITextField final : GUIElement, IClickable 
{
private:
	bool* interactable;
	bool* selected;
	bool* focused;

	GUIText* text;	
	Sprite* background;

	void initialize();
public:
	GUITextField(const Rect& rectangle);
	GUITextField(const Rect& rectangle, const std::string& text);

	void set_interactable(const bool& status);
	void set_position(const Vector2& position);
	void set_position(const float& x, const float& y);
	void set_text(const std::string& text);

	const bool& IsInteractable() const;
	const bool& IsSelected() const;
	const Vector2& get_position() const;
	const std::string& get_text() const;

	void GUIElement::input_update(sf::Event& event) override;

	~GUITextField();
};
#endif