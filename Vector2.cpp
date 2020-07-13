#include "Vector2.h"

Vector2::Vector2(const float& x, const float& y)
{
	*this->x = x;
	*this->y = y;
	*this->_length = Vector2::length(*this);
}

const float& Vector2::length(const Vector2& vector)
{
	return sqrt(pow(*vector.x, 2) + pow(*vector.y, 2));
}
const float& Vector2::distance(const Vector2& vector1, const Vector2& vector2)
{
	return sqrt(pow(vector2.x - vector1.x, 2) + pow(vector2.y - vector1.y, 2));
}
const Vector2& Vector2::normalize(const Vector2& vector)
{
	return Vector2::magnitude(vector, 1);
}
const Vector2& Vector2::magnitude(const Vector2& vector, const float& length)
{
	Vector2 result = vector;
	*result._length = length;
	return result;
}
const float& Vector2::angle(const Vector2& vector1, const Vector2& vector2)
{
	return scalar(vector1, vector2) / (*vector1._length * *vector2._length);
}
const float& Vector2::scalar(const Vector2& vector1, const Vector2& vector2)
{
	return *vector1.x * *vector2.x + *vector1.y * *vector2.y;
}

const Vector2& Vector2::operator=(const Vector2& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->_length = vector._length;
	return *this;
}
const Vector2& Vector2::operator+=(const Vector2& vector)
{
	*this->x += *vector.x;
	*this->y += *vector.y;
	*this->_length = Vector2::length(*this);
	return *this;
}
const Vector2& Vector2::operator-=(const Vector2& vector)
{
	*this->x -= *vector.x;
	*this->y -= *vector.y;
	*this->_length = Vector2::length(*this);
	return *this;
}
const Vector2& Vector2::operator*=(const Vector2& vector)
{
	*this->x *= *vector.x;
	*this->y *= *vector.y;
	*this->_length = Vector2::length(*this);
	return *this;
}
const Vector2& Vector2::operator*=(const float& factor)
{
	*this->x *= factor;
	*this->y *= factor;
	*this->_length = Vector2::length(*this);
	return *this;
}
const Vector2& Vector2::operator/=(const Vector2& vector)
{
	*this->x /= *vector.x;
	*this->y *= *vector.y;
	*this->_length = Vector2::length(*this);
	return *this;
}
const Vector2& Vector2::operator/=(const float& factor)
{
	*this->x /= factor;
	*this->y /= factor;
	*this->_length = Vector2::length(*this);
	return *this;
}