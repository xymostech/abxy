#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>

class Vector2 {
public:
	float x, y;
	Vector2()
	: x(0)
	, y(0)
	{
		
	}

	Vector2(float x, float y)
	: x(x)
	, y(y)
	{
		
	}

	Vector2(const Vector2 &copy)
	: x(copy.x)
	, y(copy.y)
	{
		
	}

	Vector2 &operator=(const Vector2 &add) {
		x = add.x;
		y = add.y;
		return *this;
	}

	Vector2 operator+(const Vector2 &add) const {
		return Vector2(x + add.x, y + add.y);
	}

	Vector2 &operator+=(const Vector2 &add) {
		*this = *this + add;
		return *this;
	}

	Vector2 operator-(const Vector2 &sub) const {
		return Vector2(x - sub.x, y - sub.y);
	}

	Vector2 &operator-=(const Vector2 &sub) {
		*this = *this - sub;
		return *this;
	}

	Vector2 operator*(const float &mult) const {
		return Vector2(x * mult, y * mult);
	}

	Vector2 &operator*=(const float &mult) {
		*this = *this * mult;
		return *this;
	}

	Vector2 operator/(const float &div) const {
		return Vector2(x / div, y / div);
	}

	Vector2 &operator/=(const float &div) {
		*this = *this / div;
		return *this;
	}

	float Dot(const Vector2 &dot) const {
		return x * dot.x + y * dot.y;
	}

	float Cross(const Vector2 &dot) const {
		return x * dot.y - y * dot.x;
	}

	float SqNorm() const {
		return x * x + y * y;
	}

	float Norm() const {
		return sqrt(x * x + y * y);
	}

	Vector2 &Normalize() {
		*this /= Norm();
		return *this;
	}
};

class Vector3 {
public:
	float x, y, z;
	Vector3(float x, float y, float z)
	: x(x)
	, y(y)
	, z(z)
	{
		
	}
};

class Vector4 {
public:
	float x, y, z, w;
	Vector4(float x, float y, float z, float w)
	: x(x)
	, y(y)
	, z(z)
	, w(w)
	{
		
	}
};

#endif /* VECTOR2_HPP */

