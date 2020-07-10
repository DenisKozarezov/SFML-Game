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
	delete this->frames;

	delete this->currentFrame;
	delete this->name;
	delete this->speed;
	delete this->isPlaying;
	delete this->isStopped;
	delete this->isLoop;

	delete this->clock;
	delete this->target;
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
	if (!*this->isStopped)
	{
		*this->isPlaying = true;
		if (this->clock->getElapsedTime().asMilliseconds() >= *this->speed)
		{			
			target->set_texture(*get_frame(*this->currentFrame));
			std::cout << "Playing animation\n";
			if (*this->currentFrame >= this->frames->size() - 1) *this->currentFrame = 0;
			else *this->currentFrame += 1;
			this->clock->restart();
		}
	}
}
void Animation::stop()
{
	*this->isPlaying = false;
	*this->isStopped = true;
	*this->currentFrame = 0;
	this->clock->restart();
}