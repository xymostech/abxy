#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 {
public:
	float x, y;

	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2 &copy);
	Vector2 &operator=(const Vector2 &set);

	Vector2 operator+(const Vector2 &add) const;
	Vector2 &operator+=(const Vector2 &add);
	Vector2 operator-(const Vector2 &sub) const;
	Vector2 &operator-=(const Vector2 &sub);
	Vector2 operator*(const float &mult) const;
	Vector2 &operator*=(const float &mult);
	Vector2 operator/(const float &div) const;
	Vector2 &operator/=(const float &div);

	float Dot(const Vector2 &dot) const;
	float Cross(const Vector2 &dot) const;

	float SqNorm() const;
	float Norm() const;
	Vector2 &Normalize();
};

#endif /* VECTOR2_HPP */

