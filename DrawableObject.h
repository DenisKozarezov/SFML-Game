////////////////////////////////////////////////////////////////////
//				 GUARD FROM MULTIPLE INCLUDING		              //
// DrawableContainer.h -> DrawableObject.h -> DrawableContainer.h //
////////////////////////////////////////////////////////////////////
#ifndef _DRAWABLEOBJECT_H_
#define _DRAWABLEOBJECT_H_
#include "Sprite.h"
#include "Vector2.h"

/////////////////////////////////////////////////////////////////////
/// \brief Class, from which all graphic objects on the screen are
/// inherited. It stores information about world/screen coordinates,
/// layer's number, and, naturally, sprite. When the object is destroyed,
/// it deallocates its resources from the graphic container and be removed
/// from the drawing process.
/////////////////////////////////////////////////////////////////////
class DrawableObject
{
private:
	friend class DrawableLayer;

	unsigned int* layer;
	Vector2* position;
	Vector2* velocity;
	Sprite* sprite;

	bool* hidden;
public:
	DrawableObject();

	/// <summary>
	/// Return the drawing state of this object.
	/// </summary>
	const bool& IsHidden() const;

	void hide(const bool& status);

	virtual void move(const Vector2& position) = 0;

	void set_velocity(const Vector2& velocity);
	void set_velocity(const float& x_vector, const float& y_vector);
	const Vector2& get_velocity() const;

	void set_position(const Vector2& position);
	void set_position(const float& x, const float& y);
	const Vector2& get_position() const;

	/// <summary>
	/// Switch to an other layer with specified number.
	/// </summary>
	/// <param name="layer - a number of specified layer"></param>
	void set_layer(const unsigned short& layer);

	/// Return of this object's current layer. 
	const unsigned short& get_layer() const;

	/// <summary>
	/// Swap the sprite relative to the horizontal axis.
	/// </summary>
	void swapX(const bool& status);

	/// <summary>
	/// Swap the sprite relative to the vertical axis.
	/// </summary>
	void swapY(const bool& status);

	const bool& IsSwappedX() const;
	const bool& IsSwappedY() const;

	/// <summary>
	/// Deallocation of object's resources and excluding it from drawing
	/// process on screen.
	/// </summary>
	/// <param name="*object - pointer to object"></param>
	static void destroy(DrawableObject* object);

	virtual ~DrawableObject();
protected:
	friend class Animation;
	friend class Camera;

	Sprite* get_sprite() const;

	void set_texture(const sf::Texture& texture);
	void set_sprite(const Sprite& sprite);

	void offset_sprite(const Vector2& offset);

	/// <summary>
	/// Initialization of graphic object and adding it in drawing container on zero layer.
	/// </summary>
	/// <param name="*object - pointer to object"></param>
	static void initialize(DrawableObject* object);

	/// <summary>
	/// Initialization of graphic object and adding it in drawing container on specified layer.
	/// </summary>
	/// <param name="layer - number of specified layer"></param>
	static void initialize(DrawableObject* object, const unsigned short& layer);

	/// <summary>
	/// Initialization of graphic object and adding it in drawing container on specified layer.
	/// </summary>
	/// <param name="layer - specified layer"></param>
	static void initialize(DrawableObject* object, const std::string& layer);

	virtual void update() = 0;
};
#endif