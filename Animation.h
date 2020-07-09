#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <thread>

class Animation final
{
private:
	std::vector<sf::Sprite*>* frames = new std::vector<sf::Sprite*>;
	sf::Sprite* currentFrame = nullptr;

	std::string* name = new std::string("Empty");
	unsigned int* speed = new unsigned int(1000); // Скорость в миллисекундах
	
	bool* isPaused = new bool(false);
	bool* isPlaying = new bool(false);
public:
	bool* isLoop = new bool(true);

	explicit Animation();
	explicit Animation(sf::Sprite* sprites, const unsigned int& size);
	explicit Animation(std::vector<sf::Sprite*>* _sprites) : frames(_sprites) {}
	explicit Animation(const std::string& name);

	const float& get_speed();
	const std::string& get_name();
	sf::Sprite* get_frame(const unsigned int& index) const;

	void play();
	void stop();
	void pause();
	void reset();
	void set_name(const std::string& name);
	void set_speed(const unsigned int& value);	

	~Animation();
};

