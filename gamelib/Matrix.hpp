#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstring>
#include <cmath>

#include <gamelib/Vector.hpp>

template <typename T, unsigned m>
class Column {
	T col[m];
public:
	T &operator[](const int &row) {
		return col[row];
	}

	const T &operator[](const int &row) const {
		return col[row];
	}

	T &x() {
		return col[0];
	}

	T &y() {
		return col[1];
	}

	T &z() {
		return col[2];
	}

	T &w() {
		return col[3];
	}
};

template <typename T, unsigned m, unsigned n>
class Matrix {
	Column<T, m> mat[n];
public:
	Matrix() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				mat[i][j] = 0.0;
			}
		}
	}

	Matrix(float diag) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				mat[i][j] = (i == j) ? diag : 0.0;
			}
		}
	}

	Matrix(const Matrix<T, n, m> &copy) {
		memcpy(mat, copy.mat, m * n * sizeof(T));
	}

	Matrix<T, m, n> &operator=(const Matrix<T, m, n> &copy) {
		memcpy(mat, copy.mat, m * n * sizeof(T));
		return *this;
	}

	Column<T, m> &operator[](const int &col) {
		return mat[col];
	}

	const Column<T, m> &operator[](const int &col) const {
		return mat[col];
	}

	Matrix<T, m, n> operator+(const Matrix<T, m, n> &add) const {
		Matrix<T, m, n> ret;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ret.mat[i][j] = mat[i][j] + add.mat[i][j];
			}
		}

		return ret;
	}

	Matrix<T, m, n> &operator+=(const Matrix<T, m, n> &add) {
		*this = *this + add;
		return *this;
	}

	template <unsigned o>
	Matrix<T, m, o> operator*(const Matrix<T, n, o> &mult) const {
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

	Matrix<T, m, n> operator*(const T &mult) const {
		Matrix<T, m, n> ret;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ret[i][j] = mat[i][j] * mult;
			}
		}

		return ret;
	}

	Matrix<T, m, n> &operator*(const T &mult) {
		*this = *this * mult;
		return *this;
	}

	const T *GetData() {
		return reinterpret_cast<T*>(mat);
	}

	// Functions only defined for 4x4s:
	void Translate(const Vector3 &trans);
	void Scale(const Vector3 &scale);
	void Rotate(const Vector3 &axis, float angle);
};

typedef Matrix<float, 4, 4> Matrix4;

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

#endif /* MATRIX_HPP */

