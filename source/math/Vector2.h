#pragma once
#include <math.h>
#include <string>
#include "Math.h"

class Vector2 final
{
public:
	float x;
	float y;

	/// A vector with coordinates (0, 0).
	const static Vector2 zero;
	/// A vector with coordinates (-1, 0).
	const static Vector2 left;
	/// A vector with coordinates (1, 0).
	const static Vector2 right;
	/// A vector with coordinates (0, 1).
	const static Vector2 up;
	/// A vector with coordinates (0, -1).
	const static Vector2 down;
	/// A vector with coordinates (1, 1).
	const static Vector2 one;
	/// A vector with coordinates (+inf, +inf).
	const static Vector2 positive_infinity;
	/// A vector with coordinates (-inf, -inf).
	const static Vector2 negative_infinity;

	Vector2();
	Vector2(const float& x, const float& y);

	/// Returns the normal vector.
	const Vector2 normalize() const;

	/// Returns the unit vector.
	const Vector2 unit() const;

	/// Return of the vector's length.
	const float& magnitude() const;

	/// Returns the perpendicular, released from the point to the line.
	const Vector2 perpendicular(const Vector2& vector1, const Vector2& vector2) const;

	/// Sets new coordinates for the vector.
	void set(const float& x, const float& y);

	/// Returns the record with coordinates of the vector. Example: (1, 2);
	const std::string to_string() const;

	/// Returns the dot product of two vectors.
	const static float& dot(const Vector2& vector1, const Vector2& vector2);

	/// Returns the angle between two vectors.
	const static float& angle(const Vector2& vector1, const Vector2& vector2);

	/// Returns the distance between two vectors.
	const static float& distance(const Vector2& vector1, const Vector2& vector2);	

	/// Return of interpolation between two vectors with specified factor.
	const static Vector2 lerp(const Vector2& vector1, const Vector2& vector2, const float& factor);

	const Vector2& operator=(const Vector2& vector);
	const Vector2& operator=(std::initializer_list<Vector2> vectors);
	const Vector2& operator=(Vector2 vectors[]);
	const Vector2& operator=(std::vector<Vector2>& vectors);

	const Vector2& operator+(const Vector2& vector);
	const Vector2& operator-(const Vector2& vector);
	const Vector2& operator*(const float& factor);
	const Vector2& operator/(const float& factor);

	const Vector2& operator+=(const Vector2& vector);
	const Vector2& operator-=(const Vector2& vector);
	const Vector2& operator*=(const float& factor);
	const Vector2& operator/=(const float& factor);
};
const Vector2& operator-(const Vector2& vector);

const Vector2 operator+(const Vector2& vector1, const Vector2& vector2);
const Vector2 operator-(const Vector2& vector1, const Vector2& vector2);
const Vector2 operator*(const Vector2& vector, const float& factor);
const Vector2 operator/(const Vector2& vector, const float& factor);

const bool& operator==(const Vector2& vector1, const Vector2& vector2);
const bool& operator!=(const Vector2& vector1, const Vector2& vector2);
