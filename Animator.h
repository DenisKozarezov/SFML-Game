#pragma once
#include <vector>
#include "Animation.h"
#include "GameObject.h"

class Animator final
{
private:
	std::map<const std::string, Animation*>* animations =
		new std::map<const std::string, Animation*>;	

	bool* isPaused = new bool(false);
	bool* isPlaying = new bool(false);

	GameObject* parent = nullptr;
public:
	Animation* currentAnimation = nullptr;

	explicit Animator(GameObject* parent);
	explicit Animator(Animation* animations, const unsigned int& size, GameObject* parent);
	explicit Animator(const std::vector<Animation*> animations, GameObject* parent);
	
	/// <summary>
	/// ���������� �������� � ������ ���������.
	/// </summary>
	/// <param name="*animation - ��������� �� ������ ��������."></param>
	void add(Animation* animation);

	/// <summary>
	/// ���������� �������� � ��������� ��������� � ������ ���������.
	/// </summary>
	/// <param name="*animation - ��������� �� ������ ��������."></param>
	void add(const std::string& name, Animation* animation);

	/// <summary>
	/// �������� �������� �� ������ ��������� �� � ��������.
	/// </summary>
	/// <param name="name - ������ ��������."></param>
	void remove(const std::string& name);

	/// <summary>
	/// �������� �������� �� ������ ��������� �� � �������.
	/// </summary>
	/// <param name="index - ����� ��������."></param>
	void remove(const unsigned int& index);
	void set_main_animation(Animation* animation);
	void set_main_animation(const std::string& name);

	/// <summary>
	/// ������������ ��������� ��������.
	/// </summary>
	/// <param name="*animation - ��������� �� ������ ��������."></param>
	void play(Animation* animation);

	/// <summary>
	/// ������������ ��������� �������� �� �������.
	/// </summary>
	/// <param name="index - ����� ��������."></param>
	void play(const int& index);


	/// <summary>
	/// ������������ ��������� �������� �� ��������.
	/// </summary>
	/// <param name="name - ������ ��������."></param>
	void play(const std::string& name);

	/// ��������� ��������� � ������� ��������.
	void stop();

	Animation* get_animation(const int& index) const;
	Animation* get_animation(const std::string& name) const;
	const GameObject* get_parent();
	const bool& IsPlaying() const;

	~Animator();
};