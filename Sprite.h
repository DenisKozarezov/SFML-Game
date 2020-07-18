#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"

class Sprite : public sf::Sprite
{
private:
	bool* swappedX = new bool(false);
	bool* swappedY = new bool(false);

	unsigned int* frames = new unsigned int(0);
public:
	explicit Sprite();

	void swapX(const bool& status);
	void swapY(const bool& status);

	void set_frames_count(const unsigned int& count);

	const bool& IsSwappedX() const;
	const bool& IsSwappedY() const;
	const unsigned int& get_frames_count() const;

	bool* isMultiple = new bool(false);

	~Sprite();
};

