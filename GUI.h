#pragma once
#include "DrawableLayer.h"
#include <vector>

class GUI final
{
private:
	static bool _hidden;
	static DrawableLayer* gui_layer;
public:
	GUI();

	const bool& IsHidden() const;

	static void show(const bool& status);
};

