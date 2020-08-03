#ifndef _DRAWABLECONTAINER_H_
#define _DRAWABLECONTAINER_H_
#include <SFML/Graphics.hpp>
#include "DrawableLayer.h"
#include <algorithm>

/////////////////////////////////////////////////////////////////////
/// \brief �����-���������, � ������� �� ����� ���������� �����������
/// ������� ���� DrawableObject. ��������� �������������� � �������
/// �������, ������� � �������� ����. � ������, ���� �� ����� ����������
/// ������ ��������� ������ ��� ������� ������� ���������� isDrawable
/// = false, �� ������ ������ �� ����� ��������� �� ������.
/////////////////////////////////////////////////////////////////////
class GameDrawableContainer final
{
private:
	friend class DrawableObject;

	static std::map<unsigned int, DrawableLayer*>* layers;
public:
	/// ������������� ������������ ���������� � ���� ����������� ����.
	static void initialize(const unsigned short& container_size);	

	/// <summary>
	/// ������ �������� (������������ ������� ��������) ���� ����������� ��������,
	/// � ����� ����������� ����. ���������� ������ ����������.
	/// </summary>
	static void terminate();
	static DrawableLayer* get_layer(const unsigned short& layer);

	const static unsigned short& size();
	
	/// <summary>
	/// ���������������� ��������� ���� ����������� �������� �� ������ ����, ������� � ��������.
	/// </summary>
	/// <param name="window - ������ �� ������ ����."></param>
	static void update(sf::RenderWindow& window);	
};
#endif 