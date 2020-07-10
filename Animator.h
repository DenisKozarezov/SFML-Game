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
	bool* _isPlaying = new bool(false);

	DrawableObject* parent = nullptr;
public:
	Animation* currentAnimation = nullptr;

	explicit Animator(DrawableObject* parent);
	explicit Animator(Animation* animations, const unsigned int& size, DrawableObject* parent);
	explicit Animator(const std::vector<Animation*>& animations, DrawableObject* parent);
	
	/// <summary>
	/// Добавление анимации в список аниматора.
	/// </summary>
	/// <param name="*animation - указатель на объект анимации."></param>
	void add(Animation* animation);

	/// <summary>
	/// Добавление анимации с указанным названием в список аниматора.
	/// </summary>
	/// <param name="*animation - указатель на объект анимации."></param>
	void add(const std::string& name, Animation* animation);

	/// <summary>
	/// Удаление анимации из списка аниматора по её названию.
	/// </summary>
	/// <param name="name - строка названия."></param>
	void remove(const std::string& name);

	/// <summary>
	/// Удаление анимации из списка аниматора по её индексу.
	/// </summary>
	/// <param name="index - номер анимации."></param>
	void remove(const unsigned int& index);
	void set_main_animation(Animation* animation);
	void set_main_animation(const std::string& name);

	/// <summary>
	/// Проигрывание указанной анимации.
	/// </summary>
	/// <param name="*animation - указатель на объект анимации."></param>
	void play(Animation* animation);

	/// <summary>
	/// Проигрывание указанной анимации по индексу.
	/// </summary>
	/// <param name="index - номер анимации."></param>
	void play(const int& index);


	/// <summary>
	/// Проигрывание указанной анимации по названию.
	/// </summary>
	/// <param name="name - строка названия."></param>
	void play(const std::string& name);

	/// Остановка аниматора и текущей анимации.
	void stop();

	Animation* get_animation(const int& index) const;
	Animation* get_animation(const std::string& name) const;
	const DrawableObject* get_parent();
	const bool& isPlaying() const;

	~Animator();
};