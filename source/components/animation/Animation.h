#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../game object/GameObject.h"

class Animation final
{
private:
	std::shared_ptr<sf::Texture> source;
	sf::IntRect* currentRect = new sf::IntRect;
	unsigned int* currentFrame = new unsigned int(0);
	unsigned int* deltaX = new unsigned int(0);
	unsigned int* _size = new unsigned int(0);

	std::string* name = new std::string("Empty");
	float* interval = new float(1000); // »нтервал между кадрами в миллисекундах
	
	bool* _isPlaying = new bool(false);
	bool* isStopped = new bool(false);

	GameObject* target;
	sf::Clock* clock = new sf::Clock;
public:
	/// ‘лаг, значение которого задаЄт зацикленность текущей анимации.
	bool* isLoop = new bool(true);

	const bool& isPlaying() const;

	explicit Animation(GameObject* target);
	explicit Animation(const sf::Texture& sprite_sheet, const unsigned int& frames, GameObject* target);
	explicit Animation(const std::string& name, GameObject* target);

	/// ¬озвращает название текущей анимации.	
	/// \return —трока названи€.
	const std::string& get_name() const;

	/// ¬озвращает количество кадров в анимации.	
	/// \return ѕоложительное целое число.
	const unsigned int& size() const;

	/// ¬озвращает значение интервала между кадрами анимации.	
	/// \return ¬ременной период в миллисекундах.
	const float& get_interval() const;		

	/// ѕроигрывание анимации с текущим значением интервала между
	/// кадрами.
	void play();

	/// ќстановка текущей анимации, а также полный сброс кадров.
	void stop();

	void pause();

	void reset();

	/// <summary>
	/// »зменение названи€ анимации.
	/// <param name = "name - строка нового названи€."></param>
	/// </summary>
	void set_name(const std::string& name);

	/// <summary>
	/// «адание интервала между кадрами анимации.
	/// <param name = "value - временной период в миллисекундах."></param>
	/// </summary>
	void set_interval(const float& value);	

	~Animation();
};

