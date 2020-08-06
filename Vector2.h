#pragma once
#include <math.h>
#include <string>
#include "Math.h"

class Vector2 final
{
public:
	float x;
	float y;

	const static Vector2 zero;
	const static Vector2 left;
	const static Vector2 right;
	const static Vector2 up;
	const static Vector2 down;
	const static Vector2 one;
	const static Vector2 positive_infinity;
	const static Vector2 negative_infinity;

	Vector2();
	Vector2(const float& x, const float& y);

	/// Return of the same vector with length 1.
	/// \return length
	Vector2 normalize();

	/// Return of the vector's length.
	float& magnitude() const;

	/// Sets new coordinates for the vector.
	void set(const float& x, const float& y);

	/// Returns the record with coordinates of the vector. Example: (1, 2);
	const std::string& to_string() const;

	/// Returns the dot product of two vectors.
	const static float& scalar(const Vector2& vector1, const Vector2& vector2);

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
