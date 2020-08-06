#ifndef _GUIBUTTON_H_
#define _GUIBUTTON_H_
#include "GUI.h"
#include "struct.h"

class GUIButton final
{
private:
	bool* hover;
	bool* active;
	bool* interactive;

	struct Background
	{
	public:
		Sprite* hover;
		Sprite* active;
		Sprite* interactive;
	};
	Background* background;
public:
	GUIButton(const Rect& rectangle);

	void select();
	void set_interactive(const bool& status);
	void set_text(const std::string& text);

	const bool& IsHover() const;
	const bool& IsActive() const;
	const bool& IsInteractive() const;
	const Background* get_background();

	~GUIButton();
};
#endif