#ifndef MATRIX_INL
#define MATRIX_INL

#include <gamelib/Matrix.hpp>

template <typename T, unsigned m>
T &Column<T, m>::operator[](const int &row) {
	return col[row];
}

template <typename T, unsigned m>
const T &Column<T, m>::operator[](const int &row) const {
	return col[row];
}

template <typename T, unsigned m>
T &Column<T, m>::x() {
	return col[0];
}

template <typename T, unsigned m>
T &Column<T, m>::y() {
	return col[1];
}

template <typename T, unsigned m>
T &Column<T, m>::z() {
	return col[2];
}

template <typename T, unsigned m>
T &Column<T, m>::w() {
	return col[3];
}

template <typename T, unsigned m, unsigned n>
Matrix<T, m, n>::Matrix() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			mat[i][j] = 0.0;
		}
	}
}

template <typename T, unsigned m, unsigned n>
Matrix<T, m, n>::Matrix(float diag) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			mat[i][j] = (i == j) ? diag : 0.0;
		}
	}
}

template <typename T, unsigned m, unsigned n>
Matrix<T, m, n>::Matrix(const Matrix<T, n, m> &copy) {
	memcpy(mat, copy.mat, m * n * sizeof(T));
}

template <typename T, unsigned m, unsigned n>
Matrix<T, m, n> &Matrix<T, m, n>::operator=(const Matrix<T, m, n> &copy) {
	memcpy(mat, copy.mat, m * n * sizeof(T));
	return *this;
}

template <typename T, unsigned m, unsigned n>
Column<T, m> &Matrix<T, m, n>::operator[](const int &col) {
	return mat[col];
}

template <typename T, unsigned m, unsigned n>
const Column<T, m> &Matrix<T, m, n>::operator[](const int &col) const {
	return mat[col];
}

template <typename T, unsigned m, unsigned n>
Matrix<T, m, n> Matrix<T, m, n>::operator+(const Matrix<T, m, n> &add) const {
	Matrix<T, m, n> ret;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ret.mat[i][j] = mat[i][j] + add.mat[i][j];
		}
	}

	return ret;
}

template <typename T, unsigned m, unsigned n>
Matrix<T, m, n> &Matrix<T, m, n>::operator+=(const Matrix<T, m, n> &add) {
	*this = *this + add;
	return *this;
}

template <typename T, unsigned m, unsigned n>
template <unsigned o>
Matrix<T, m, o> Matrix<T, m, n>::operator*(const Matrix<T, n, o> &mult) const {
	Matrix<T, m, o> ret;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < o; ++j) {
			ret[j][i] = 0;
			for (int k = 0; k < n; ++k) {
				ret[j][i] += mat[k][i] * mult[j][k];
			}
		}
	}

	return ret;
}

template <typename T, unsigned m, unsigned n>
Matrix<T, m, n> Matrix<T, m, n>::operator*(const T &mult) const {
	Matrix<T, m, n> ret;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ret[i][j] = mat[i][j] * mult;
		}
	}

	return ret;
}

template <typename T, unsigned m, unsigned n>
Matrix<T, m, n> &Matrix<T, m, n>::operator*(const T &mult) {
	*this = *this * mult;
	return *this;
}

template <typename T, unsigned m, unsigned n>
const T *Matrix<T, m, n>::GetData() const {
	return reinterpret_cast<const T*>(mat);
}

template <>
void Matrix4::Translate(const Vector3 &trans) {
	Matrix4 mult(1.0);

	mult[3].x() = trans.x;
	mult[3].y() = trans.y;
	mult[3].z() = trans.z;

	*this = mult * *this;
}

template <>
void Matrix4::Scale(const Vector3 &scale) {
	Matrix4 mult(1.0);

	mat[0][0] = scale.x;
	mat[1][1] = scale.y;
	mat[2][2] = scale.z;

	*this = mult * *this;
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

	*this = mult * *this;
}

#endif /* MATRIX_INL */

