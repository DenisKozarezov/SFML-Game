#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "Drawable.h"

class Animation final
{
private:
	std::vector<sf::Texture*>* frames = new std::vector<sf::Texture*>;
	unsigned int* currentFrame = new unsigned int(0);

	std::string* name = new std::string("Empty");
	float* speed = new float(1000); // Скорость в миллисекундах
	
	bool* isPaused = new bool(false);
	bool* isPlaying = new bool(false);

	DrawableObject* target;
	sf::Clock* clock;
public:
	bool* isLoop = new bool(true);

	explicit Animation(DrawableObject* target);
	explicit Animation(sf::Texture* sprites, const unsigned int& size, DrawableObject* target);
	explicit Animation(std::vector<sf::Texture*>* _sprites, DrawableObject* target);
	explicit Animation(const std::string& name, DrawableObject* target);

	const float& get_speed();
	const std::string& get_name();
	sf::Texture* get_frame(const unsigned int& index) const;

	void play();
	void stop();
	void pause();
	void reset();
	void set_name(const std::string& name);
	void set_speed(const unsigned int& value);	

	~Animation();
};

