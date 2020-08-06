#ifndef _GUIBUTTON_H_
#define _GUIBUTTON_H_
#include "GUI.h"
#include "struct.h"
#include <stdarg.h>

class GUIButton final : GUIElement
{
private:
	bool* hover;
	bool* active;
	bool* interactable;

	GUIText* text;
	Vector2* position;
	Vector2* size;
	Sprite* current;

	typedef void(*function)();
	function action;

	struct Background
	{
	public:
		Background() = default;
		sf::Texture* hover;
		sf::Texture* active;
		sf::Texture* passive;
		~Background();
	};
	Background* background;

	void initialize();
public:
	GUIButton(const Rect& rectangle);
	GUIButton(const Rect& rectangle, const std::string& text);

	void select();
	void set_interactable(const bool& status);
	void set_text(const std::string& text);
	void set_image(const sf::Texture& texture);
	void set_background(Background* background);
	void set_position(const Vector2& position);
	void set_position(const float& x, const float& y);
	void set_size(const Vector2& size);
	void set_size(const float& width, const float& height);

	void set_action(function action);
	void invoke();
	
	void input_update(sf::Event& event) override;

	const bool& IsHover() const;
	const bool& IsActive() const;
	const bool& IsInteractable() const;
	const std::string& get_text() const;
	const Background* get_background();
	const Vector2& get_position();
	const Vector2& get_size();

	~GUIButton();
};
#endif
