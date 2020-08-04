#pragma once
#include "DrawableLayer.h"
#include <vector>

class GUI final
{
private:
	bool* hidden;
	DrawableLayer* gui_layer;

	static GUI* instance;

	GUI();
	GUI& operator=(const GUI&) = delete;
public:
	static GUI* get_instance();

	const bool& IsHidden() const;

	void show(const bool& status);
};

