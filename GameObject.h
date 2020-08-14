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
class GameObject
{
private:
	friend class DrawableLayer;

	std::string* name;
	std::string* tag;
	unsigned int* layer;
	Vector2* position;
	Vector2* velocity;
	float* gravity;
	Sprite* sprite;

	bool* hidden;
public:
	GameObject();

	virtual void move(const Vector2& position) = 0;

	/// <summary>
	/// Sets the name of this object.
	/// </summary>
	void set_name(const std::string& name);

	/// <summary>
	/// Sets the tag of this object.
	/// </summary>
	void set_tag(const std::string& name);

	/// <summary>
	/// Sets the position of this object.
	/// </summary>
	void set_position(const Vector2& position);

	/// <summary>
	/// Sets the position of this object.
	/// </summary>
	void set_position(const float& x, const float& y);

	/// <summary>
	/// Sets the velocity of this object.
	/// </summary>
	void set_velocity(const Vector2& velocity);

	/// <summary>
	/// Sets the velocity of this object.
	/// </summary>
	void set_velocity(const float& x_vector, const float& y_vector);

	void set_gravity(const float& scale);

	/// <summary>
	/// Switch to an other layer with specified number.
	/// </summary>
	/// <param name="layer - a number of specified layer"></param>
	void set_layer(const unsigned short& layer);

	/// <summary>
	/// Swap the sprite relative to the horizontal axis.
	/// </summary>
	void swapX(const bool& status);

	/// <summary>
	/// Swap the sprite relative to the vertical axis.
	/// </summary>
	void swapY(const bool& status);

	/// <summary>
	/// Sets the object unseen for drawing process.
	/// </summary>
	void hide(const bool& status);

	/// <summary>
	/// Deallocation of object's resources and excluding it from drawing
	/// process on screen.
	/// </summary>
	/// <param name="*object - pointer to object"></param>
	static void destroy(GameObject* object);

	/// <summary>
	/// Return of the object's name.
	/// </summary>
	const std::string& get_name() const;

	/// <summary>
	/// Return of the object's tag.
	/// </summary>
	const std::string& get_tag() const;

	/// Return of the object's current layer. 
	const unsigned short& get_layer() const;

	/// <summary>
	/// Return of the object's current position.
	/// </summary>
	const Vector2& get_position() const;

	/// <summary>
	/// Return of the object's current velocity.
	/// </summary>
	const Vector2& get_velocity() const;

	const float& get_gravity() const;

	const bool& IsSwappedX() const;
	const bool& IsSwappedY() const;

	/// <summary>
	/// Return the drawing state of this object.
	/// </summary>
	const bool& IsHidden() const;
	virtual ~GameObject();
protected:
	friend class Animation;
	friend class Camera;

	void set_texture(const sf::Texture& texture);
	void set_sprite(const Sprite& sprite);

	void offset_sprite(const Vector2& offset);

	/// <summary>
	/// Initialization of graphic object and adding it in drawing container on zero layer.
	/// </summary>
	/// <param name="*object - pointer to object"></param>
	static void initialize(GameObject* object);

	/// <summary>
	/// Initialization of graphic object and adding it in drawing container on specified layer.
	/// </summary>
	/// <param name="layer - number of specified layer"></param>
	static void initialize(GameObject* object, const unsigned short& layer);

	/// <summary>
	/// Initialization of graphic object and adding it in drawing container on specified layer.
	/// </summary>
	/// <param name="layer - specified layer"></param>
	static void initialize(GameObject* object, const std::string& layer);

	Sprite* get_sprite() const;

	virtual void update() = 0;
};
#endif