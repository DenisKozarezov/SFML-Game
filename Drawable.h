#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ProjectPath.cpp"
#include "Vector2.h"
#include "Sprite.h"

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
	friend class GameDrawableContainer;

	unsigned int* layer = new unsigned int(0);

	Vector2* screen_position = new Vector2(0.f, 0.f);
	Vector2* world_position = new Vector2(0.f, 0.f);

	Sprite* sprite = new Sprite;
public:
	/// ����, �������� �������� ����� ��������� ������������ �������.
	bool* isDrawable = new bool(true);

	const Vector2& get_screen_position() const;
	const Vector2& get_world_position() const;

	/// <summary>
	/// ������� ������������ ������� �� ��������� ����.
	/// </summary>
	/// <param name="layer - ����� ����."></param>
	void set_layer(const unsigned int& layer);

	/// ���������� ����� �������� ����, �� ������� ��������� ����������� ������.
	/// \return ����� ����.
	const unsigned int& get_layer() const;

	/// <summary>
	/// ��������� ������������� ����������� ������ ������������ �����������.
	/// </summary>
	/// <param name="status - ����."></param>
	void swapX(const bool& status);

	/// <summary>
	/// ��������� ������������� ����������� ������ ������������ ���������.
	/// </summary>
	/// <param name="status - ����."></param>
	void swapY(const bool& status);

	const bool& IsSwappedX() const;
	const bool& IsSwappedY() const;

	/// <summary>
	/// ������ ����������� �������� ������� � ������������ ���� ������� �� ��������.
	/// ��������, ������������ ������ ����� ����� �� ���������� GameDrawableContainer
	/// � ����� �� ����� �������������� �� ������.
	/// </summary>
	/// <param name="*object - �������� �� ����������� ������."></param>
	static void destroy(DrawableObject* object);

	virtual ~DrawableObject();
protected:
	friend class Animation;
	friend class Camera;

	Sprite* get_sprite() const;

	void set_texture(const sf::Texture& texture);
	void set_sprite(const Sprite& sprite);

	void set_screen_position(const Vector2& point);
	void set_screen_position(const float& x, const float& y);

	void set_world_position(const Vector2& point);
	void set_world_position(const float& x, const float& y);

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

	virtual void update() = 0;
};

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

	static std::map<unsigned int, std::vector<DrawableObject*>*>* layers;

	/// �������� ����� ������ �� ���������� �� ������������ ��������.
	template<typename T>
	static void remove_group(const T& type);

	/// �������� ����� ������ �� ����������� ���� �� ������������ ��������.
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
public:
	/// ������������� ������������ ���������� � ���� ����������� ����.
	static void initialize();	

	/// �������� ���������� ���� �� ���������� ����������� �������.
	const static bool is_layer_contains(const unsigned int& layer, const DrawableObject* object);

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

	const static unsigned int& get_layers_amount();
	
	/// <summary>
	/// ���������������� ��������� ���� ����������� �������� �� ������ ����, ������� � ��������.
	/// </summary>
	/// <param name="window - ������ �� ������ ����."></param>
	static void update(sf::RenderWindow& window);	
};