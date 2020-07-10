#include "Animation.h"
#include <iostream>
#include "Game.h"

Animation::Animation(DrawableObject* target)
{
	this->target = target;
}
Animation::Animation(sf::Texture* sprites, const unsigned int& size, DrawableObject* target)
{
	this->target = target;
	for (unsigned int i = 0; i < size; i++) frames->push_back(&sprites[i]);
}
Animation::Animation(std::vector<sf::Texture*>* sprites, DrawableObject* target)
{
	this->target = target;
	this->frames = sprites;
}
Animation::Animation(const std::string& name, DrawableObject* target)
{
	this->target = target;
	*this->name = name;
}

Animation::~Animation()
{
	std::vector<sf::Texture*>::iterator it;
	for (it = frames->begin(); it != frames->end(); it++) delete *it;
	delete frames;

	delete currentFrame;
	delete name;
	delete speed;
	delete isPaused;
	delete isPlaying;
	delete isLoop;
}

const std::string& Animation::get_name()
{
	return *this->name;
}

void Animation::set_name(const std::string& name)
{
	*this->name = name;
}
void Animation::set_speed(const unsigned int& value)
{
	*this->speed = value;
}
sf::Texture* Animation::get_frame(const unsigned int& index) const
{
	std::vector<sf::Texture*>::iterator it = this->frames->begin();
	std::advance(it, index);
	return *it;
}

void Animation::play()
{
	this->clock->restart();
	if (this->clock->getElapsedTime().asMilliseconds() > * this->speed)
	{
		target->get_sprite()->setTexture(*get_frame(*this->currentFrame));
		std::cout << "Playing animation\n";
	}
	if (*this->currentFrame >= this->frames->size() - 1) *this->currentFrame = 0;
	else *this->currentFrame += 1;
	this->clock->restart();
}
void Animation::stop()
{
	*isPlaying = false;
	*isPaused = false;
	*currentFrame = 0;
}