#pragma once
#include <math.h>
#include <string>
#include "Math.h"

class Vector2 final
{
private:
	float length;

	const static float& scalar(const Vector2& vector1, const Vector2& vector2);
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

	explicit Vector2();
	explicit Vector2(const float& x, const float& y);

	const Vector2 normalize();
	const float& magnitude();
	void set(const float& x, const float& y);
	const std::string& to_string() const;

	const static float& angle(const Vector2& vector1, const Vector2& vector2);
	const static float& distance(const Vector2& vector1, const Vector2& vector2);	
	const static Vector2 lerp(const Vector2& vector1, const Vector2& vector2, const float& factor);

	const Vector2& operator=(const Vector2& vector);

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

const Vector2 operator+(const Vector2 vector1, const Vector2 vector2);
const Vector2 operator-(const Vector2 vector1, const Vector2 vector2);
const Vector2 operator*(const Vector2 vector, const float& factor);
const Vector2 operator/(const Vector2 vector, const float& factor);

const bool& operator==(const Vector2& vector1, const Vector2& vector2);
const bool& operator!=(const Vector2& vector1, const Vector2& vector2);