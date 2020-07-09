#pragma once
#include <vector>
#include "Animation.h"
#include "Drawable.h"

class Animator final
{
private:
	std::map<const std::string, Animation*>* animations =
		new std::map<const std::string, Animation*>;
	Animation* currentAnimation = nullptr;

	bool* isPaused = new bool(false);
	bool* isPlaying = new bool(false);

	DrawableObject* parent = nullptr;
public:
	explicit Animator(DrawableObject* parent);
	explicit Animator(Animation* animations, const unsigned int& size, DrawableObject* parent);
	explicit Animator(const std::vector<Animation*>& animations, DrawableObject* parent);
	
	void add(Animation* animation);
	void add(const std::string& name, Animation* animation);
	void remove(const std::string& name);
	void remove(const unsigned int& index);

	void play(Animation* animation);
	void play(const int& index);
	void play(const std::string& name);
	void stop();

	Animation* get_animation(const int& index);
	DrawableObject* get_parent() const;
	~Animator();
};