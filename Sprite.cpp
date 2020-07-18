#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::~Sprite()
{
	delete this->isMultiple;
	delete this->swappedX;
	delete this->swappedY;
	delete this->frames;
}

void Sprite::swapX(const bool& status)
{
	*this->swappedX = status;
}
void Sprite::swapY(const bool& status)
{
	*this->swappedY = status;
}
void Sprite::set_frames_count(const unsigned int& count)
{
	*this->frames = count;
}

const bool& Sprite::IsSwappedX() const
{
	return *this->swappedX;
}
const bool& Sprite::IsSwappedY() const
{
	return *this->swappedY;
}
const unsigned int& Sprite::get_frames_count() const
{
	return *this->frames;
}