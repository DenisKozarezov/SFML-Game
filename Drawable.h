#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ProjectPath.h"

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
	unsigned int* layer = new unsigned int(0);
public:
	bool* isDrawable = new bool(true);	

	/// <summary>
	/// Перенос графического объекта на указанный слой.
	/// </summary>
	/// <param name="layer - номер слоя."></param>
	void set_layer(const unsigned int& layer);

	const unsigned int& get_layer();

	/// <summary>
	/// Полное уничтожение игрового объекта и освобождение всех занятых им ресурсов.
	/// Вдобавок, уничтоженный объект будет удалён из контейнера GameDrawableContainer
	/// и больше не будет отрисовываться на экране.
	/// </summary>
	/// <param name="*object - указаель на графический объект."></param>
	static void destroy(DrawableObject* object);
	virtual sf::Sprite* get_sprite() const = 0;

	virtual ~DrawableObject();
protected:
	/// <summary>
	/// Инициализация игрового объекта для последующей отрисовки и добавление его в
	/// контейнер GameDrawableContainer.
	/// </summary>
	/// <param name="*object - указаель на графический объект."></param>
	static void initialize(DrawableObject* object);		

	/// <summary>
	/// Инициализация игрового объекта для последующей отрисовки и добавление его в
	/// контейнер GameDrawableContainer с заданным значением isDrawable.
	/// </summary>
	/// <param name="*object - указаель на графический объект."></param>
	static void initialize(DrawableObject* object, const bool& isDrawable);

	/// <summary>
	/// Инициализация игрового объекта для последующей отрисовки и добавление его на
	/// указанный слой.
	/// </summary>
	/// <param name="*object - указаель на графический объект."></param>
	static void initialize(DrawableObject* object, unsigned int& layer);
};

/////////////////////////////////////////////////////////////////////
/// \brief Класс-контейнер, в котором по слоям содержатся графические
/// объекты типа DrawableObject. Отрисовка осуществляется при помощи
/// многопоточности и в строгом порядке, начиная с нулевого слоя.
/// В случае, если во время исполнения метода отрисовки объект был
/// помечен булевой переменной isDrawable = false, то данный объект
/// не будет отрисован на экране.
/////////////////////////////////////////////////////////////////////
class GameDrawableContainer final
{
private:
	static std::map<unsigned int, std::vector<DrawableObject*>*>* layers;
public:
	/// <summary>
	/// Инициализация графического контейнера и всех графических слоёв.
	/// </summary>
	static void initialize();
	/// <summary>
	/// Удаление целой группы из контейнера по определённому признаку.
	/// </summary>
	template<typename T>
	static void remove_group(const T& type);
	/// <summary>
	/// Удаление целой группы из конкретного слоя по определённому признаку.
	/// </summary>
	template<typename T>
	static void remove_group(const unsigned int& layer, const T& type);
	/// <summary>
	/// Поиск графического объекта во всех слоях и последующее его удаление с исключением
	/// из процесса отрисовки.
	/// </summary>
	static void remove(const DrawableObject* object);
	/// <summary>
	/// Удаление графического объекта из указанного слоя с последующим исключением его из 
	/// процесса отрисовки.
	/// </summary>
	static void remove(const unsigned int& layer, DrawableObject* object);
	/// <summary>
	/// Удаление графического объекта по указанному итератору с последующим исключением объекта из 
	/// процесса отрисовки.
	/// </summary>
	static void remove(std::map<unsigned int, std::vector<DrawableObject*>*>::iterator it, DrawableObject* object);
	/// <summary>
	/// Проверка указанного слоя на содержание конкретного объекта.
	/// </summary>
	static bool is_layer_contains(const unsigned int& layer, const DrawableObject* object);
	/// <summary>
	/// Очистка всех графических слоёв. Процедура не затрагивает данные
	/// графических объектов очищенного слоя.
	/// </summary>
	static void clear();
	/// <summary>
	/// Полное удаление (освобождение занятых ресурсов) всех графических объектов,
	/// а также графических слоёв. Завершение работы контейнера.
	/// </summary>
	static void terminate();
	static std::vector<DrawableObject*>* get_layer(const unsigned int& layer);
	
	/// <summary>
	/// Последовательная отрисовка всех графических объектов на каждом слое, начиная с нулевого.
	/// </summary>
	/// <param name="window - ссылка на объект окна."></param>
	static void render(sf::RenderWindow& window);	
};