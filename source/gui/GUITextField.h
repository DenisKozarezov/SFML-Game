#ifndef _GUITEXTFIELD_H_
#define _GUITEXTFIELD_H_
#include "GUIElement.h"
#include "GUI.h"
#include "GUIText.h"
#include "../components/delegate/Delegate.h"
#include "../components/sprite/Sprite.h"
#include "../Game.h"
#include "../math/Rect.h"

class GUITextField final : public GUIElement
{
private:
	bool* hover;
	bool* interactable;
	bool* selected;
	bool* isMultiline;
	bool* isReadOnly;

	GUIText* text;	
	struct Background;
	Background* background;

	unsigned short* characters_limit;

	Vector2* size;
	Sprite* current;

	sf::Clock* clock;
	bool* textEntered;

	void initialize();
	void input_update(sf::Event& event) override;
public:
	Delegate<void>* OnDisabled;
	Delegate<void>* OnClick;
	Delegate<void>* OnPointerEnter;
	Delegate<void>* OnPointerExit;
	Delegate<void>* OnValueChanged;

	struct Background
	{
	private:
		sf::Texture* hover_texture;
		sf::Texture* selected_texture;
		sf::Texture* passive_texture;
	public:
		Background();
		Sprite* hover;
		Sprite* selected;
		Sprite* passive;
		~Background();
	};

	GUITextField(const Rect& rectangle);
	GUITextField(const Rect& rectangle, const std::string& text);

	void set_interactable(const bool& status);
	void set_multiline(const bool& status);
	void set_readonly(const bool& status);
	void set_position(const Vector2& position) override;
	void set_position(const float& x, const float& y);
	void set_size(const Vector2& size);
	void set_size(const float& width, const float& height);
	void set_characters_limit(const unsigned short& value);

	const bool& IsInteractable() const;
	const bool& IsSelected() const;
	const bool& IsMultiline() const;
	const bool& IsReadOnly() const;
	const Vector2& get_size() const;
	const std::string& get_text() const;
	const unsigned short& get_characters_limit() const;

	~GUITextField();
};
#endif