#pragma once
#include <vector>
#include "Animation.h"
#include "DrawableObject.h"

class Animator final
{
private:
	std::map<const std::string, Animation*>* animations =
		new std::map<const std::string, Animation*>;	

	bool* isPaused = new bool(false);
	bool* _isPlaying = new bool(false);

	DrawableObject* parent = nullptr;
public:
	Animation* currentAnimation = nullptr;

	explicit Animator(DrawableObject* parent);
	explicit Animator(Animation* animations, const unsigned int& size, DrawableObject* parent);
	explicit Animator(const std::vector<Animation*> animations, DrawableObject* parent);
	
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
	const DrawableObject* get_parent();
	const bool& isPlaying() const;

	~Animator();
};