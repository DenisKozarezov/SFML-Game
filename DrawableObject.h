////////////////////////////////////////////////////////////////////
//				 ������ �� ���������� �����������				  //
// DrawableContainer.h -> DrawableObject.h -> DrawableContainer.h //
////////////////////////////////////////////////////////////////////
#ifndef _DRAWABLEOBJECT_H_
#define _DRAWABLEOBJECT_H_
#include "Sprite.h"
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
	friend class DrawableLayer;

	unsigned int* layer;

	Vector2* screen_position;
	Vector2* world_position;

	Sprite* sprite;
public:
	DrawableObject();

	/// ����, �������� �������� ����� ��������� ������������ �������.
	bool* isDrawable;

	const Vector2& get_screen_position() const;
	const Vector2& get_world_position() const;

	/// <summary>
	/// ������� ������������ ������� �� ��������� ����.
	/// </summary>
	/// <param name="layer - ����� ����."></param>
	void set_layer(const unsigned short& layer);

	/// ���������� ����� �������� ����, �� ������� ��������� ����������� ������.
	/// \return ����� ����.
	const unsigned short& get_layer() const;

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
	/// ������������� �������� ������� ��� ����������� ��������� � ���������� ��� ��
	/// ��������� ����.
	/// </summary>
	/// <param name="*object - �������� �� ����������� ������."></param>
	static void initialize(DrawableObject* object, const unsigned short& layer);

	virtual void update() = 0;
};
#endif