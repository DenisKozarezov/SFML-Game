#ifndef _DRAWABLECONTAINER_H_
#define _DRAWABLECONTAINER_H_
#include <SFML/Graphics.hpp>
#include "DrawableLayer.h"
#include <algorithm>

/////////////////////////////////////////////////////////////////////
/// \brief Класс-контейнер, в котором по слоям содержатся графические
/// объекты типа DrawableObject. Отрисовка осуществляется в строгом
/// порядке, начиная с нулевого слоя. В случае, если во время исполнения
/// метода отрисовки объект был помечен булевой переменной isDrawable
/// = false, то данный объект не будет отрисован на экране.
/////////////////////////////////////////////////////////////////////
class GameDrawableContainer final
{
private:
	friend class DrawableObject;

	static std::map<unsigned int, DrawableLayer*>* layers;
public:
	/// Инициализация графического контейнера и всех графических слоёв.
	static void initialize(const unsigned short& container_size);	

	/// <summary>
	/// Полное удаление (освобождение занятых ресурсов) всех графических объектов,
	/// а также графических слоёв. Завершение работы контейнера.
	/// </summary>
	static void terminate();
	static DrawableLayer* get_layer(const unsigned short& layer);

	const static unsigned short& size();
	
	/// <summary>
	/// Последовательная отрисовка всех графических объектов на каждом слое, начиная с нулевого.
	/// </summary>
	/// <param name="window - ссылка на объект окна."></param>
	static void update(sf::RenderWindow& window);	
};
#endif 