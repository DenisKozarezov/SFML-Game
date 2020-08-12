#ifndef _GUIBUTTON_H_
#define _GUIBUTTON_H_
#include "GUIText.h"
#include "GUI.h"
#include "Sprite.h"
#include "Delegate.h"
#include "Game.h"
#include "Rect.h"

class GUIButton final : public GUIElement
{
private:
	bool* active;
	bool* hover;
	bool* interactable;

	GUIText* text;
	Vector2* size;
	Sprite* current;

	struct Background;
	Background* background;

	void initialize();	
	void input_update(sf::Event& event) override;
public:
	Delegate<void>* OnDisabled;
	Delegate<void>* OnClick;
	Delegate<void>* OnHover;
	Delegate<void>* OnActive;
	Delegate<void>* OnPointerEnter;
	Delegate<void>* OnPointerExit;
	Delegate<void>* OnMouseDown;
	Delegate<void>* OnMouseUp;

	struct Background
	{
	private:
		sf::Texture* hover_texture;
		sf::Texture* active_texture;
		sf::Texture* passive_texture;
	public:
		Background();
		Sprite* hover;
		Sprite* active;
		Sprite* passive;
		~Background();
	};

	GUIButton(const Rect& rectangle);
	GUIButton(const Rect& rectangle, const std::string& text);

	void select();

	/// <summary>
	/// Make the button unable to being clicked.
	/// </summary>
	/// <param name="status - flag"></param>
	void set_interactable(const bool& status);

	/// <summary>
	/// Set the text of this button.
	/// </summary>
	/// <param name="text - string"></param>
	void set_text(const std::string& text);

	void set_image(const sf::Texture& texture);

	/// <summary>
	/// Set a new pack of button states' sprites.
	/// </summary>
	/// <param name="background - pointer to struct"></param>
	void set_background(Background* background);

	/// <summary>
	/// Set the position of the button.
	/// </summary>
	/// <param name="position"></param>
	void set_position(const Vector2& position) override;

	/// <summary>
	/// Set the position of the button.	
	/// </summary>
	/// <param name="x - float value"></param>
	/// <param name="y - float value"></param>
	void set_position(const float& x, const float& y);

	/// <summary>
	/// Set a new size of the button's dimenstions.
	/// </summary>
	/// <param name="size - 2d-vector"></param>
	void set_size(const Vector2& size);

	/// <summary>
	/// Set a new size of the button's dimenstions.
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height"></param>
	void set_size(const float& width, const float& height);

	/// <summary>
	/// Set a new color of the button.
	/// </summary>
	/// <param name="color"></param>
	void set_color(const sf::Color& color);

	/// <summary>
	/// Set a new color of the button.
	/// </summary>
	/// <param name="r - red color's factor"></param>
	/// <param name="g - green color's factor"></param>
	/// <param name="b - blue color's factor"></param>
	/// <param name="a - alpha channel's factor"></param>
	void set_color(const float& r, const float& g, const float& b, const float& a);

	const bool& IsHover() const;

	/// <summary>
	/// Return the interactive state of the button.
	/// </summary>
	/// <returns></returns>
	const bool& IsInteractable() const;

	/// <summary>
	/// Return the text of this button.
	/// </summary>
	/// <returns></returns>
	const std::string& get_text() const;

	/// <summary>
	/// Return of struct with button's states pack.
	/// </summary>
	/// <returns></returns>
	const Background* get_background();

	/// <summary>
	/// Return the size of this button.
	/// </summary>
	/// <returns></returns>
	const Vector2& get_size();

	/// <summary>
	/// Return the color of this button.
	/// </summary>
	/// <returns></returns>
	const sf::Color& get_color() const;

	~GUIButton();
};
#endif
