#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ProjectPath.h"

/////////////////////////////////////////////////////////////////////
/// \brief ������������� �����, �� �������� ����������� ��� ��������
/// ����, ���������� ��������� �� ������. ������ ������� ����������
/// ������ �������� � ������-���������� GameDrawableContainer. ���
/// ����������� ������� ��� ��� �������� �� ������������ ���� ��
/// ������������� �� ����������� ���������� � ����� �� ������ � �������
/// ���������.
/////////////////////////////////////////////////////////////////////
class DrawableObject
{
private:
	unsigned int* layer = new unsigned int(0);
public:
	bool* isDrawable = new bool(true);	

	/// <summary>
	/// ������� ������������ ������� �� ��������� ����.
	/// </summary>
	/// <param name="layer - ����� ����."></param>
	void set_layer(const unsigned int& layer);

	const unsigned int& get_layer();

	/// <summary>
	/// ������ ����������� �������� ������� � ������������ ���� ������� �� ��������.
	/// ��������, ������������ ������ ����� ����� �� ���������� GameDrawableContainer
	/// � ������ �� ����� �������������� �� ������.
	/// </summary>
	/// <param name="*object - �������� �� ����������� ������."></param>
	static void destroy(DrawableObject* object);

	virtual void update() = 0;
	virtual sf::Sprite* get_sprite() = 0;

	virtual ~DrawableObject();
protected:
	/// <summary>
	/// ������������� �������� ������� ��� ����������� ��������� � ���������� ��� �
	/// ��������� GameDrawableContainer.
	/// </summary>
	/// <param name="*object - �������� �� ����������� ������."></param>
	static void initialize(DrawableObject* object);		

	/// <summary>
	/// ������������� �������� ������� ��� ����������� ��������� � ���������� ��� �
	/// ��������� GameDrawableContainer � �������� ��������� isDrawable.
	/// </summary>
	/// <param name="*object - �������� �� ����������� ������."></param>
	static void initialize(DrawableObject* object, const bool& isDrawable);

	/// <summary>
	/// ������������� �������� ������� ��� ����������� ��������� � ���������� ��� ��
	/// ��������� ����.
	/// </summary>
	/// <param name="*object - �������� �� ����������� ������."></param>
	static void initialize(DrawableObject* object, unsigned int& layer);
};

/////////////////////////////////////////////////////////////////////
/// \brief �����-���������, � ������� �� ����� ���������� �����������
/// ������� ���� DrawableObject. ��������� �������������� ��� ������
/// ��������������� � � ������� �������, ������� � �������� ����.
/// � ������, ���� �� ����� ���������� ������ ��������� ������ ���
/// ������� ������� ���������� isDrawable = false, �� ������ ������
/// �� ����� ��������� �� ������.
/////////////////////////////////////////////////////////////////////
class GameDrawableContainer final
{
private:
	static std::map<unsigned int, std::vector<DrawableObject*>*>* layers;
public:
	/// <summary>
	/// ������������� ������������ ���������� � ���� ����������� ����.
	/// </summary>
	static void initialize();
	/// <summary>
	/// �������� ����� ������ �� ���������� �� ������������ ��������.
	/// </summary>
	template<typename T>
	static void remove_group(const T& type);
	/// <summary>
	/// �������� ����� ������ �� ����������� ���� �� ������������ ��������.
	/// </summary>
	template<typename T>
	static void remove_group(const unsigned int& layer, const T& type);
	/// <summary>
	/// ����� ������������ ������� �� ���� ����� � ����������� ��� �������� � �����������
	/// �� �������� ���������.
	/// </summary>
	static void remove(const DrawableObject* object);
	/// <summary>
	/// �������� ������������ ������� �� ���������� ���� � ����������� ����������� ��� �� 
	/// �������� ���������.
	/// </summary>
	static void remove(const unsigned int& layer, DrawableObject* object);
	/// <summary>
	/// �������� ������������ ������� �� ���������� ��������� � ����������� ����������� ������� �� 
	/// �������� ���������.
	/// </summary>
	static void remove(std::map<unsigned int, std::vector<DrawableObject*>*>::iterator it, DrawableObject* object);
	/// <summary>
	/// �������� ���������� ���� �� ���������� ����������� �������.
	/// </summary>
	static bool is_layer_contains(const unsigned int& layer, const DrawableObject* object);
	/// <summary>
	/// ������� ���� ����������� ����. ��������� �� ����������� ������
	/// ����������� �������� ���������� ����.
	/// </summary>
	static void clear();
	/// <summary>
	/// ������ �������� (������������ ������� ��������) ���� ����������� ��������,
	/// � ����� ����������� ����. ���������� ������ ����������.
	/// </summary>
	static void terminate();
	static std::vector<DrawableObject*>* get_layer(const unsigned int& layer);
	
	/// <summary>
	/// ���������������� ��������� ���� ����������� �������� �� ������ ����, ������� � ��������.
	/// </summary>
	/// <param name="window - ������ �� ������ ����."></param>
	static void update(sf::RenderWindow& window);	
};