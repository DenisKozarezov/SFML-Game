#include "Animation.h"

Animation::Animation()
{

}
Animation::Animation(sf::Sprite* sprites, const unsigned int& size)
{
	for (unsigned int i = 0; i < size; i++) frames->push_back(&sprites[i]);
}
Animation::Animation(const std::string& name)
{
	*this->name = name;
}

Animation::~Animation()
{
	std::vector<sf::Sprite*>::iterator it;
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
sf::Sprite* Animation::get_frame(const unsigned int& index) const
{
	std::vector<sf::Sprite*>::iterator it = this->frames->begin();
	std::advance(it, index);
	return *it;
}

void Animation::play()
{
	if (frames->size() > 0)
	{
		*isPlaying = true;
		if (*isLoop) while (*isPlaying)
		{
			for (int i = 0; i < frames->size(); i++)
			{				
				currentFrame = get_frame(i);
				sf::sleep(sf::milliseconds(*speed));
			}
		}
		else
		{
			for (int i = 0; i < frames->size(); i++)
			{
				currentFrame = get_frame(i);
				std::this_thread::sleep_for(std::chrono::milliseconds(*speed));
			}
		}
	}
}
void Animation::stop()
{
	*isPlaying = false;
	*isPaused = false;
	currentFrame = nullptr;
}
void Animation::reset()
{
	stop();
	play();
}