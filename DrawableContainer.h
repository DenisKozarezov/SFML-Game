#ifndef _DRAWABLECONTAINER_H_
#define _DRAWABLECONTAINER_H_
#include <SFML/Graphics.hpp>
#include "DrawableLayer.h"
#include <algorithm>

/////////////////////////////////////////////////////////////////////////////
/// \brief Static class, which contains graphic layers with an associated
/// number. After the last layer was initialized, it will always be another
/// one that is reserved for GUI. All objects and layers have their methods and
/// properties, including boolean IsHidden(), which means if this value is false, 
/// this object or layer is no longer drawable or updatable on screen.
/////////////////////////////////////////////////////////////////////////////
class DrawableContainer final
{
private:
	friend class DrawableObject;
	friend class GUI;
	friend class Camera;

	static std::map<const std::string, DrawableLayer*>* layers;

	static DrawableLayer* get_GUI();

	static void remove(DrawableObject* object);
public:
	/// <summary>
	/// Initialization of graphic layers with specified amount.
	/// </summary>
	/// <param name="container_size - amount of graphic layers"></param>
	static void initialize(const unsigned short& container_size);	

	/// <summary>
	/// Deallocation of all resources in container.
	/// </summary>
	static void terminate();

	/// <summary>
	/// Return a pointer of the layer with specified number.
	/// </summary>
	/// <param name="layer - assosiated number"></param>
	static DrawableLayer* get_layer(const unsigned short& layer);

	/// <summary>
	/// Return a pointer of the specified layer.
	/// </summary>
	/// <param name="layer - specified name"></param>
	static DrawableLayer* get_layer(const std::string& layer);

	/// <summary>
	/// Return the size of graphic container.
	/// </summary>
	const static unsigned short& size();
	
	/// <summary>
	/// Consistent drawing of graphic container from zero
	/// to the last graphic layer. If layer has boolean value 
	/// IsHidden() = true, it won't be drawn regardless of having
	/// the objects within the layer the same state or not.
	/// </summary>
	/// <param name="window - reference to current window"></param>
	static void update(sf::RenderWindow& window);	
};
#endif 