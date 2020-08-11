#include "Vector2.h"

const Vector2 Vector2::zero = Vector2(0, 0);
const Vector2 Vector2::left = Vector2(-1, 0);
const Vector2 Vector2::right = Vector2(1, 0);
const Vector2 Vector2::up = Vector2(0, 1);
const Vector2 Vector2::down = Vector2(0, -1);
const Vector2 Vector2::one = Vector2(1, 1);
const Vector2 Vector2::positive_infinity = Vector2(INFINITY, INFINITY);
const Vector2 Vector2::negative_infinity = Vector2(-INFINITY, -INFINITY);

Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}
Vector2::Vector2(const float& x, const float& y)
{
	this->x = x;
	this->y = y;
}

const Vector2 Vector2::normalize() const
{	
	return Vector2(this->x / magnitude(), this->y / magnitude());
}
const Vector2 Vector2::unit() const
{
	float x = this->x != 0 ? this->x / this->x : 0;
	float y = this->y != 0 ? this->y / this->y : 0;
	return Vector2(x, y);
}
const float& Vector2::magnitude() const
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2));
}
const Vector2 Vector2::perpendicular(const Vector2& vector1, const Vector2& vector2) const
{
	float b1 = (vector2.x * vector1.y - vector1.x * vector2.y) / (vector2.x - vector1.x);
	float k = (vector2.y - vector1.y) / (vector2.x - vector1.x);
	float b2 = this->y + (1 / k) * this->x;
	float x = (b2 - b1) / (k + (1 / k));
	float y = (-1 / k) * x + b2;
	return Vector2(x, y);
}
void Vector2::set(const float& x, const float& y)
{
	this->x = x;
	this->y = y;
}
const std::string Vector2::to_string() const
{
	std::string result = "(" + std::to_string(x);
	result += "; " + std::to_string(y);
	result += ")";
	return result;
}

const float& Vector2::dot(const Vector2& vector1, const Vector2& vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y;
}
const float& Vector2::angle(const Vector2& vector1, const Vector2& vector2)
{
	return dot(vector1, vector2) / (vector1.magnitude() * vector2.magnitude());
}
const float& Vector2::distance(const Vector2& vector1, const Vector2& vector2)
{
	return sqrt(pow(vector2.x - vector1.x, 2) + pow(vector2.y - vector1.y, 2));
}
const Vector2 Vector2::lerp(const Vector2& vector1, const Vector2& vector2, const float& factor)
{
	const float& _factor = Math::get_factor(factor);
	const double& lerp_x = vector2.x - vector1.x;
	const double& lerp_y = vector2.y - vector1.y;
	return Vector2(lerp_x * _factor, lerp_y * _factor);
}

const Vector2& Vector2::operator=(const Vector2& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	return *this;
}
const Vector2& Vector2::operator=(std::initializer_list<Vector2> vectors)
{
	Vector2* ptr = this;
	std::initializer_list<Vector2>::iterator it;
	for (it = vectors.begin(); it != vectors.end(); it++, ptr++)
	{
		*ptr = *it;
	}
	return *this;
}
const Vector2& Vector2::operator=(std::vector<Vector2>& vectors)
{
	Vector2* ptr = this;
	std::vector<Vector2>::iterator it;
	for (it = vectors.begin(); it != vectors.end(); it++, ptr++)
	{
		*ptr = *it;
	}
	return *this;
}

const Vector2& Vector2::operator+(const Vector2& vector)
{
	Vector2 result = *this;
	return result += vector;
}
const Vector2& Vector2::operator-(const Vector2& vector)
{
	Vector2 result = *this;
	return result -= vector;
}
const Vector2& Vector2::operator*(const float& factor)
{
	Vector2 result = *this;
	return result *= factor;
}
const Vector2& Vector2::operator/(const float& factor)
{
	Vector2 result = *this;
	return result /= factor;
}

const Vector2& Vector2::operator+=(const Vector2& vector)
{
	this->x += vector.x;
	this->y += vector.y;
	return *this;
}
const Vector2& Vector2::operator-=(const Vector2& vector)
{
	this->x -= vector.x;
	this->y -= vector.y;
	return *this;
}
const Vector2& Vector2::operator*=(const float& factor)
{
	this->x *= factor;
	this->y *= factor;
	return *this;
}
const Vector2& Vector2::operator/=(const float& factor)
{
	this->x /= factor;
	this->y /= factor;
	return *this;
}

const Vector2& operator-(const Vector2& vector)
{
	Vector2 result = vector;
	result.x *= -1;
	result.y *= -1;
	return result;
}

const Vector2 operator+(const Vector2& vector1, const Vector2& vector2)
{
	Vector2 result = vector1;
	result += vector2;
	return result;
}
const Vector2 operator-(const Vector2& vector1, const Vector2& vector2)
{
	Vector2 result = vector1;
	result -= vector2;
	return result;
}
const Vector2 operator*(const Vector2& vector, const float& factor)
{
	Vector2 result = vector;
	result *= factor;
	return result;
}
const Vector2 operator/(const Vector2& vector, const float& factor)
{
	Vector2 result = vector;
	result /= factor;
	return result;
}

const bool& operator==(const Vector2& vector1, const Vector2& vector2)
{
	if (vector1.x != vector2.x) return false;
	if (vector1.y != vector2.y) return false;
	return true;
}
const bool& operator!=(const Vector2& vector1, const Vector2& vector2)
{
	return !(vector1 == vector2);
}