#include "Animator.h"

Animator::Animator(DrawableObject* parent)
{
	this->parent = parent;
}
Animator::Animator(Animation* animations, const unsigned int& size, DrawableObject* parent)
{
	this->parent = parent;
	for (unsigned int i = 0; i < size; i++)
	{
		this->animations->insert(std::pair<const std::string, Animation*>(animations[i].get_name(), &animations[i]));
	}
}
Animator::Animator(const std::vector<Animation*>& animations, DrawableObject* parent)
{
	this->parent = parent;
	for (int i = 0; i < animations.size(); i++)
	{
		this->animations->insert(std::pair<const std::string, Animation*>(animations[i]->get_name(), animations[i]));
	}
}

Animator::~Animator()
{
	std::map<std::string, Animation*>::iterator it = animations->begin();
	for (it = animations->begin(); it != animations->end(); it++) delete it->second;
	delete animations;

	delete isPlaying;
	delete isPaused;
}

void Animator::add(Animation* animation)
{
	animations->insert(std::pair<const std::string, Animation*>(animation->get_name(), animation));
}
void Animator::add(const std::string& name, Animation* animation)
{
	animation->set_name(name);
	animations->insert(std::pair<const std::string, Animation*>(name, animation));
}
void Animator::remove(const std::string& name)
{
	animations->erase(animations->find(name));
}
void Animator::remove(const unsigned int& index)
{
	std::map<std::string, Animation*>::iterator it = animations->begin();
	std::advance(it, index);
	animations->erase(it);
}

void Animator::play(Animation* animation)
{
	*isPlaying = true;
	currentAnimation = animation;
	currentAnimation->play();
}
void Animator::play(const int& index)
{
	*isPlaying = true;
	currentAnimation = get_animation(index);
	currentAnimation->play();
}
void Animator::play(const std::string& name)
{
	animations->find(name)->second->play();
}
void Animator::stop()
{
	currentAnimation->stop();
	currentAnimation = nullptr;
}
Animation* Animator::get_animation(const int& index)
{
	std::map<std::string, Animation*>::iterator it = animations->begin();
	std::advance(it, index);
	return it->second;
}
DrawableObject* Animator::get_parent() const
{
	return parent;
}