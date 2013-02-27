#ifndef VECTOR3_HPP
#define VECTOR3_HPP

class Vector3 {
public:
	float x, y, z;

	Vector3();
	Vector3(float x, float y, float z);
	Vector3(const Vector3 &copy);
	Vector3 &operator=(const Vector3 &set);

	Vector3 operator+(const Vector3 &add) const;
	Vector3 &operator+=(const Vector3 &add);
	Vector3 operator-(const Vector3 &sub) const;
	Vector3 &operator-=(const Vector3 &sub);
	Vector3 operator*(const float &mult) const;
	Vector3 &operator*=(const float &mult);
	Vector3 operator/(const float &div) const;
	Vector3 &operator/=(const float &div);

	float Dot(const Vector3 &dot) const;
	Vector3 Cross(const Vector3 &dot) const;

	float SqNorm() const;
	float Norm() const;
	Vector3 &Normalize();
};

#endif /* VECTOR3_HPP */

