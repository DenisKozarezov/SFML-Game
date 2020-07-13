#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ProjectPath.h"
#include "Vector2.h"

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

	Vector2* position = new Vector2(0.f, 0.f);

	sf::Texture* texture = new sf::Texture;
	sf::Image* image = new sf::Image;
	sf::Sprite* sprite = new sf::Sprite;
public:
	/// ����, �������� �������� ����� ��������� ������������ �������.
	bool* isDrawable = new bool(true);

	const Vector2& get_position() const;

	/// <summary>
	/// ������� ������������ ������� �� ��������� ����.
	/// </summary>
	/// <param name="layer - ����� ����."></param>
	void set_layer(const unsigned int& layer);

	/// ���������� ����� �������� ����, �� ������� ��������� ����������� ������.
	/// \return ����� ����.
	const unsigned int& get_layer() const;

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

	sf::Sprite* get_sprite() const;
	sf::Texture* get_texture() const;
	sf::Image* get_image() const;

	void set_texture(const sf::Texture& texture);
	void set_image(const sf::Image& image);
	void set_sprite(const sf::Sprite& sprite);

	void set_position(const Vector2& point);
	void set_position(const float& x, const float& y);

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