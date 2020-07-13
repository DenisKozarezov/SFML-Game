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
	friend class GameDrawableContainer;

	unsigned int* layer = new unsigned int(0);

	sf::Vector2f* position = new sf::Vector2f(0.f, 0.f);

	sf::Texture* texture = new sf::Texture;
	sf::Image* image = new sf::Image;
	sf::Sprite* sprite = new sf::Sprite;
public:
	/// Флаг, значение которого задаёт отрисовку графического объекта.
	bool* isDrawable = new bool(true);

	const sf::Vector2f& get_position() const;

	/// <summary>
	/// Перенос графического объекта на указанный слой.
	/// </summary>
	/// <param name="layer - номер слоя."></param>
	void set_layer(const unsigned int& layer);

	/// Возвращает номер текущего слоя, на котором находится графический объект.
	/// \return Номер слоя.
	const unsigned int& get_layer() const;

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

	sf::Sprite* get_sprite() const;
	sf::Texture* get_texture() const;
	sf::Image* get_image() const;

	void set_texture(const sf::Texture& texture);
	void set_image(const sf::Image& image);
	void set_sprite(const sf::Sprite& sprite);

	void set_position(const sf::Vector2f& point);
	void set_position(const float& x, const float& y);

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

	virtual void update() = 0;
};

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

	static std::map<unsigned int, std::vector<DrawableObject*>*>* layers;

	/// Удаление целой группы из контейнера по определённому признаку.
	template<typename T>
	static void remove_group(const T& type);

	/// Удаление целой группы из конкретного слоя по определённому признаку.
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
public:
	/// Инициализация графического контейнера и всех графических слоёв.
	static void initialize();	

	/// Проверка указанного слоя на содержание конкретного объекта.
	const static bool is_layer_contains(const unsigned int& layer, const DrawableObject* object);

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

	const static unsigned int& get_layers_amount();
	
	/// <summary>
	/// Последовательная отрисовка всех графических объектов на каждом слое, начиная с нулевого.
	/// </summary>
	/// <param name="window - ссылка на объект окна."></param>
	static void update(sf::RenderWindow& window);	
};