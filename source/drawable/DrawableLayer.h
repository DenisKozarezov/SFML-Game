////////////////////////////////////////////////////////////////////
//				 GUARD FROM MULTIPLE INCLUDING		              //
// DrawableContainer.h -> DrawableLayer.h -> DrawableContainer.h  //
////////////////////////////////////////////////////////////////////
#ifndef _DRAWABLELAYER_H_
#define _DRAWABLELAYER_H_
#include "../components/game object/GameObject.h"
#include <list>

class DrawableLayer final
{
private:
	bool* hidden;
	bool* updatable;

	std::list<GameObject*>* layer;
public:
	DrawableLayer();

	const bool& IsHidden() const;
	const bool& IsUpdatable() const;

	void hide(const bool& status);
	void make_unupdatable();

	void add(GameObject* object);

	/// Remove the group of objects by classified attribute.
	/// \param type - classified attribute.
	template<typename T>
	void remove_group(const T& type);

	/// Remove the object from drawing process WITHOUT deallocation.
	/// \param *object - pointer to object
	void remove(GameObject* object);

	/// Return the result of finding object in layer.
	/// \param *object - pointer to object
	const bool& contains(GameObject* object) const;

	void update(sf::RenderWindow& window);

	std::list<GameObject*>* get_layer();

	~DrawableLayer();
};
#endif