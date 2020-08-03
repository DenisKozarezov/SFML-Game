////////////////////////////////////////////////////////////////////
//				 ЗАЩИТА ОТ ПОВТОРНОГО ПОДКЛЮЧЕНИЯ				  //
// DrawableContainer.h -> DrawableObject.h -> DrawableContainer.h //
////////////////////////////////////////////////////////////////////
#ifndef _DRAWABLEOBJECT_H_
#define _DRAWABLEOBJECT_H_
#include "Sprite.h"
#include "Vector2.h"

/////////////////////////////////////////////////////////////////////
/// \brief Универсальный класс, от которого наследуются все элементы
/// игры, подлежащие отрисовке на экране. Спрайт каждого наследника
/// класса хранится в классе-контейнере GameDrawableContainer. При
/// уничтожении объекта или его удалении из графического слоя он
/// освобождается из глобального контейнера и более не входит в процесс
/// отрисовки.
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

	/// Флаг, значение которого задаёт отрисовку графического объекта.
	bool* isDrawable;

	const Vector2& get_screen_position() const;
	const Vector2& get_world_position() const;

	/// <summary>
	/// Перенос графического объекта на указанный слой.
	/// </summary>
	/// <param name="layer - номер слоя."></param>
	void set_layer(const unsigned short& layer);

	/// Возвращает номер текущего слоя, на котором находится графический объект.
	/// \return Номер слоя.
	const unsigned short& get_layer() const;

	/// <summary>
	/// Полностью отзеркаливает графический объект относительно горизонтали.
	/// </summary>
	/// <param name="status - флаг."></param>
	void swapX(const bool& status);

	/// <summary>
	/// Полностью отзеркаливает графический объект относительно вертикали.
	/// </summary>
	/// <param name="status - флаг."></param>
	void swapY(const bool& status);

	const bool& IsSwappedX() const;
	const bool& IsSwappedY() const;

	/// <summary>
	/// Полное уничтожение игрового объекта и освобождение всех занятых им ресурсов.
	/// Вдобавок, уничтоженный объект будет удалён из контейнера GameDrawableContainer
	/// и более не будет отрисовываться на экране.
	/// </summary>
	/// <param name="*object - указаель на графический объект."></param>
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
	/// Инициализация игрового объекта для последующей отрисовки и добавление его в
	/// контейнер GameDrawableContainer.
	/// </summary>
	/// <param name="*object - указаель на графический объект."></param>
	static void initialize(DrawableObject* object);

	/// <summary>
	/// Инициализация игрового объекта для последующей отрисовки и добавление его на
	/// указанный слой.
	/// </summary>
	/// <param name="*object - указаель на графический объект."></param>
	static void initialize(DrawableObject* object, const unsigned short& layer);

	virtual void update() = 0;
};
#endif