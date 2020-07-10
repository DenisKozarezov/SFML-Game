#pragma once
#include <vector>
#include "Animation.h"
#include "Drawable.h"

class Animator final
{
private:
	std::map<const std::string, Animation*>* animations =
		new std::map<const std::string, Animation*>;	

	bool* isPaused = new bool(false);
	bool* isPlaying = new bool(false);

	DrawableObject* parent = nullptr;
public:
	Animation* currentAnimation = nullptr;

	explicit Animator(DrawableObject* parent);
	explicit Animator(Animation* animations, const unsigned int& size, DrawableObject* parent);
	explicit Animator(const std::vector<Animation*>& animations, DrawableObject* parent);
	
	void add(Animation* animation);
	void add(const std::string& name, Animation* animation);
	void remove(const std::string& name);
	void remove(const unsigned int& index);
	void set_main_animation(Animation* animation);
	void set_main_animation(const std::string& name);

	void play(Animation* animation);
	void play(const int& index);
	void play(const std::string& name);
	void stop();

	Animation* get_animation(const int& index) const;
	Animation* get_animation(const std::string& name) const;
	const DrawableObject* get_parent();

	~Animator();
};