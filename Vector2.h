#pragma once
#include <math.h>

class Vector2
{
private:
	float* x = new float(0);
	float* y = new float(0);
	float* _length = new float(0);
	Vector2* normal;
public:
	Vector2(const float& x, const float& y);

	const Vector2& left = Vector2(-1, 0);
	const Vector2& right = Vector2(1, 0);
	const Vector2& up = Vector2(0, 1);
	const Vector2& down = Vector2(0, -1);

	const static float& length(const Vector2& vector);
	const static float& distance(const Vector2& vector1, const Vector2& vector2);
	const static Vector2& normalize(const Vector2& vector);
	const static Vector2& magnitude(const Vector2& vector, const float& length);
	const static float& angle(const Vector2& vector1, const Vector2& vector2);
	const static float& scalar(const Vector2& vector1, const Vector2& vector2);

	const Vector2& operator=(const Vector2& vector);
	const Vector2& operator+=(const Vector2& vector);
	const Vector2& operator-=(const Vector2& vector);
	const Vector2& operator*=(const Vector2& vector);
	const Vector2& operator*=(const float& factor);
	const Vector2& operator/=(const Vector2& vector);
	const Vector2& operator/=(const float& factor);
};
const bool& operator==(const Vector2& vector1, const Vector2& vector2);
const bool& operator!=(const Vector2& vector1, const Vector2& vector2);

