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
	delete this->interval_speed;
	delete this->_isPlaying;
	delete this->isStopped;
	delete this->isLoop;

	delete this->clock;
}

const bool& Animation::isPlaying() const
{
	return *this->_isPlaying;
}
const std::string& Animation::get_name() const
{
	return *this->name;
}
const float& Animation::get_interval() const
{
	return *this->interval_speed;
}

void Animation::set_name(const std::string& name)
{
	*this->name = name;
}
void Animation::set_interval(const unsigned int& value)
{
	*this->interval_speed = value;
}
sf::Texture* Animation::get_frame(const unsigned int& index) const
{
	std::vector<sf::Texture*>::iterator it = this->frames->begin();
	std::advance(it, index);
	return *it;
}

void Animation::play()
{
	if (!*this->isStopped && *this->interval_speed != 0)
	{
		*this->_isPlaying = true;
		if (this->clock->getElapsedTime().asMilliseconds() >= *this->interval_speed)
		{			
			target->set_texture(*get_frame(*this->currentFrame));
			if (*this->currentFrame >= this->frames->size() - 1) *this->currentFrame = 0;
			else *this->currentFrame += 1;
			this->clock->restart();

			if (!*this->isLoop) stop();
		}
	}
}
void Animation::stop()
{
	*this->_isPlaying = false;
	*this->isStopped = true;
	*this->currentFrame = 0;
	this->clock->restart();
}