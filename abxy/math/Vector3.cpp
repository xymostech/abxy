#include "Vector3.hpp"

#include <cmath>

Vector3::Vector3()
: x(0), y(0), z(0)
{

}

Vector3::Vector3(float x, float y, float z)
: x(x), y(y), z(z)
{

}

Vector3::Vector3(const Vector3 &copy)
: x(copy.x), y(copy.y), z(copy.y)
{

}

Vector3 &Vector3::operator=(const Vector3 &set)
{
	x = set.x;
	y = set.y;
	z = set.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3 &add) const {
	return Vector3(x + add.x, y + add.y, z + add.z);
}

Vector3 &Vector3::operator+=(const Vector3 &add) {
	*this = *this + add;
	return *this;
}

Vector3 Vector3::operator-(const Vector3 &sub) const {
	return Vector3(x - sub.x, y - sub.y, z - sub.z);
}

Vector3 &Vector3::operator-=(const Vector3 &sub) {
	*this = *this - sub;
	return *this;
}

Vector3 Vector3::operator*(const float &mult) const {
	return Vector3(x * mult, y * mult, z * mult);
}

Vector3 &Vector3::operator*=(const float &mult) {
	*this = *this * mult;
	return *this;
}

Vector3 Vector3::operator/(const float &div) const {
	return Vector3(x / div, y / div, z / div);
}

Vector3 &Vector3::operator/=(const float &div) {
	*this = *this / div;
	return *this;
}

float Vector3::Dot(const Vector3 &dot) const {
	return x * dot.x + y * dot.y + z * dot.z;
}

Vector3 Vector3::Cross(const Vector3 &dot) const {
	return Vector3(
		y * dot.z - z * dot.y,
		z * dot.x - x * dot.z,
		x * dot.y - y * dot.z
	);
}

float Vector3::SqNorm() const {
	return x * x + y * y + z * z;
}

float Vector3::Norm() const {
	return sqrt(SqNorm());
}

Vector3 &Vector3::Normalize() {
	*this /= Norm();
	return *this;
}

