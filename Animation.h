#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "Drawable.h"

class Animation final
{
private:
	std::vector<sf::Texture>* frames = new std::vector<sf::Texture>;
	unsigned int* currentFrame = new unsigned int(0);

	std::string* name = new std::string("Empty");
	float* interval_speed = new float(1000); // »нтервал между кадрами в миллисекундах
	
	bool* _isPlaying = new bool(false);
	bool* isStopped = new bool(false);

	DrawableObject* target;
	sf::Clock* clock = new sf::Clock;

	const sf::Texture* get_frame(const unsigned int& index) const;
public:
	/// ‘лаг, значение которого задаЄт зацикленность текущей анимации.
	bool* isLoop = new bool(true);

	const bool& isPlaying() const;

	explicit Animation(DrawableObject* target);
	explicit Animation(sf::Texture* frames, const unsigned int& size, DrawableObject* target);
	explicit Animation(std::vector<sf::Texture*>* frames, DrawableObject* target);
	explicit Animation(const std::string& name, DrawableObject* target);

	/// ¬озвращает название текущей анимации.	
	/// \return —трока названи€.
	const std::string& get_name() const;

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
	void set_interval(const unsigned int& value);	

	~Animation();
};

