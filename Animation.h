#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "Drawable.h"

class Animation final
{
private:
	//std::vector<sf::Texture>* frames = new std::vector<sf::Texture>;
	sf::IntRect* currentRect = new sf::IntRect;
	unsigned int* currentFrame = new unsigned int(0);
	unsigned int* deltaX = new unsigned int(0);
	unsigned int* _size = new unsigned int(0);

	std::string* name = new std::string("Empty");
	float* interval_speed = new float(1000); // �������� ����� ������� � �������������
	
	bool* _isPlaying = new bool(false);
	bool* isStopped = new bool(false);

	DrawableObject* target;
	sf::Clock* clock = new sf::Clock;
public:
	/// ����, �������� �������� ����� ������������� ������� ��������.
	bool* isLoop = new bool(true);

	const bool& isPlaying() const;

	explicit Animation(DrawableObject* target);
	explicit Animation(const sf::Texture& sprite_sheet, const unsigned int& frames, DrawableObject* target);
	explicit Animation(const std::string& name, DrawableObject* target);

	/// ���������� �������� ������� ��������.	
	/// \return ������ ��������.
	const std::string& get_name() const;

	/// ���������� ���������� ������ � ��������.	
	/// \return ������������� ����� �����.
	const unsigned int& size() const;

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
	void set_interval(const float& value);	

	~Animation();
};

