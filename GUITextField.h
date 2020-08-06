#pragma once
#include "GUIElement.h"
#include "GUIImage.h"

class GUITextField final : public GUIElement
{
private:
	bool* interactable;
	bool* focused;

	//ValueChanged
	//OnEditing
	//OnClick
	//

	std::string* text;
	GUIImage* background;

public:
	GUITextField(const Rect& rectangle);

	~GUITextField();
};

