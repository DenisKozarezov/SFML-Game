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
	std::map<std::string, Animation*>::iterator it = this->animations->begin();
	for (it = animations->begin(); it != this->animations->end(); it++) delete it->second;
	delete this->animations;

	delete this->isPlaying;
	delete this->isPaused;
}

void Animator::add(Animation* animation)
{
	this->animations->insert(std::pair<const std::string, Animation*>(animation->get_name(), animation));
}
void Animator::add(const std::string& name, Animation* animation)
{
	animation->set_name(name);
	this->animations->insert(std::pair<const std::string, Animation*>(name, animation));
}
void Animator::remove(const std::string& name)
{
	this->animations->erase(animations->find(name));
}
void Animator::remove(const unsigned int& index)
{
	std::map<std::string, Animation*>::iterator it = animations->begin();
	std::advance(it, index);
	this->animations->erase(it);
}
void Animator::set_main_animation(Animation* animation)
{
	//this->mainAnimation = animation;
}
void Animator::set_main_animation(const std::string& name)
{
	//this->mainAnimation = this->animations->find(name)->second;
}
void Animator::play(Animation* animation)
{
	if (this->currentAnimation != nullptr) this->currentAnimation->stop();
	*this->isPlaying = true;
	this->currentAnimation = animation;
	this->currentAnimation->play();
}
void Animator::play(const int& index)
{
	if (this->currentAnimation != nullptr) this->currentAnimation->stop();
	*this->isPlaying = true;
	this->currentAnimation = get_animation(index);
	this->currentAnimation->play();
}
void Animator::play(const std::string& name)
{
	if (this->currentAnimation != nullptr) this->currentAnimation->stop();
	*this->isPlaying = true;
	Animation* animation = this->animations->find(name)->second;
	this->currentAnimation = animation;
	this->currentAnimation->play();
}
void Animator::stop()
{
	*this->isPlaying = false;
	this->currentAnimation->stop();
}
Animation* Animator::get_animation(const int& index) const
{
	std::map<std::string, Animation*>::iterator it = this->animations->begin();
	std::advance(it, index);
	return it->second;
}
Animation* Animator::get_animation(const std::string& name) const
{
	return animations->find(name)->second;
}
const DrawableObject* Animator::get_parent()
{
	return this->parent;
}