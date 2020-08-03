///////////////////////////////////////////////////////////////////
//				 ЗАЩИТА ОТ ПОВТОРНОГО ПОДКЛЮЧЕНИЯ				 //
// DrawableContainer.h -> DrawableLayer.h -> DrawableContainer.h //
///////////////////////////////////////////////////////////////////
#ifndef _DRAWABLELAYER_H_
#define _DRAWABLELAYER_H_
#include "DrawableObject.h"
#include <vector>

class DrawableLayer final
{
private:
	bool* drawable;
	std::vector<DrawableObject*>* layer;
public:
	DrawableLayer();

	const bool& IsDrawable() const;

	void add(DrawableObject* object);

	/// Удаление группы графических объектов по указанному признаку.
	/// \param type - классифицируемый признак.
	template<typename T>
	void remove_group(const T& type);

	/// Удаление графического объекта с последующим исключением его из 
	/// процесса отрисовки.
	/// \param object - графический объект
	void remove(DrawableObject* object);

	/// Проверка, содержит ли слой указанный объект.
	/// \param object - графический объект
	/// \return bool - флаг
	const bool& is_contain(DrawableObject* object) const;

	void update(sf::RenderWindow& window);

	std::vector<DrawableObject*>* get_layer();

	~DrawableLayer();
};
#endif