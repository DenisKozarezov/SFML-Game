#include "Animation.h"
#include "Game.h"

Animation::Animation(DrawableObject* target)
{
	this->target = target;
}
Animation::Animation(const sf::Texture& sprite_sheet, const unsigned int& size, DrawableObject* target)
{
	this->target = target;
	*this->deltaX = sprite_sheet.getSize().x / size;
	*this->_size = size;
	*this->currentRect = sf::IntRect(0, 0, *this->deltaX, sprite_sheet.getSize().y);
}
Animation::Animation(const std::string& name, DrawableObject* target)
{
	this->target = target;
	*this->name = name;
}

Animation::~Animation()
{
	delete this->currentRect;
	delete this->_size;
	delete this->deltaX;
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
const unsigned int& Animation::size() const
{
	return *this->_size;
}
const float& Animation::get_interval() const
{
	return *this->interval_speed;
}

void Animation::set_name(const std::string& name)
{
	*this->name = name;
}
void Animation::set_interval(const float& value)
{
	*this->interval_speed = value;
}

void Animation::play()
{
	if (!*this->isStopped && *this->interval_speed != 0)
	{
		*this->_isPlaying = true;
		if (this->clock->getElapsedTime().asMilliseconds() >= *this->interval_speed)
		{		
			target->get_sprite()->setTextureRect(*this->currentRect);
			if (*this->currentFrame >= *this->_size - 1)
			{
				*this->currentFrame = 0;
				if (!*this->isLoop) stop();
			}
			else *this->currentFrame += 1;

			this->currentRect->left = *this->deltaX * *this->currentFrame;
			this->clock->restart();			
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
void Animation::reset()
{
	*this->isStopped = false;
}