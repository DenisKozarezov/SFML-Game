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
	float* interval_speed = new float(1000); // �������� ����� ������� � �������������
	
	bool* _isPlaying = new bool(false);
	bool* isStopped = new bool(false);

	DrawableObject* target;
	sf::Clock* clock = new sf::Clock;

	const sf::Texture* get_frame(const unsigned int& index) const;
public:
	/// ����, �������� �������� ����� ������������� ������� ��������.
	bool* isLoop = new bool(true);

	const bool& isPlaying() const;

	explicit Animation(DrawableObject* target);
	explicit Animation(sf::Texture* frames, const unsigned int& size, DrawableObject* target);
	explicit Animation(std::vector<sf::Texture*>* frames, DrawableObject* target);
	explicit Animation(const std::string& name, DrawableObject* target);

	/// ���������� �������� ������� ��������.	
	/// \return ������ ��������.
	const std::string& get_name() const;

	/// ���������� �������� ��������� ����� ������� ��������.	
	/// \return ��������� ������ � �������������.
	const float& get_interval() const;		

	/// ������������ �������� � ������� ��������� ��������� �����
	/// �������.
	void play();

	/// ��������� ������� ��������, � ����� ������ ����� ������.
	void stop();

	void pause();

	void reset();

	/// <summary>
	/// ��������� �������� ��������.
	/// <param name = "name - ������ ������ ��������."></param>
	/// </summary>
	void set_name(const std::string& name);

	/// <summary>
	/// ������� ��������� ����� ������� ��������.
	/// <param name = "value - ��������� ������ � �������������."></param>
	/// </summary>
	void set_interval(const unsigned int& value);	

	~Animation();
};

