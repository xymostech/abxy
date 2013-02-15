#include <abxy/Matrix.hpp>

template <>
void Matrix4::Translate(const Vector3 &trans) {
	Matrix4 mult(1.0);

	mult[3][0] = trans.x;
	mult[3][1] = trans.y;
	mult[3][2] = trans.z;

	*this = *this * mult;
}

template <>
void Matrix4::Scale(const Vector3 &scale) {
	Matrix4 mult(1.0);

	mult[0][0] = scale.x;
	mult[1][1] = scale.y;
	mult[2][2] = scale.z;

	*this = *this * mult;
}

template <>
void Matrix4::Rotate(const Vector3 &axis, float angle) {
	Matrix4 mult(1.0);

	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	float s = sin(angle);
	float c = cos(angle);
	float ic = 1.0 - c;

	mult[0][0] = x*x + (1 - x*x) * c;
	mult[0][1] = ic*x*y + z*s;
	mult[0][2] = ic*x*z - y*s;

	mult[1][0] = ic*x*y - z*s;
	mult[1][1] = y*y + (1 - y*y) * c;
	mult[1][2] = ic*y*z + x*s;

	mult[2][0] = ic*x*z + y*s;
	mult[2][1] = ic*y*z - x*s;
	mult[2][2] = z*z + (1 - z*z) * c;

	*this = *this * mult;
}
