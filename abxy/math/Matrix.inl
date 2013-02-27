#ifndef MATRIX_INL
#define MATRIX_INL

#include "Matrix.hpp"

template <typename T, unsigned m>
T &Column<T, m>::operator[](int row) {
	return col[row];
}

template <typename T, unsigned m>
const T &Column<T, m>::operator[](int row) const {
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
	for (unsigned int i = 0; i < n; ++i) {
		for (unsigned int j = 0; j < m; ++j) {
			mat[i][j] = 0.0;
		}
	}
}

template <typename T, unsigned m, unsigned n>
Matrix<T, m, n>::Matrix(float diag) {
	for (unsigned int i = 0; i < n; ++i) {
		for (unsigned int j = 0; j < m; ++j) {
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
Column<T, m> &Matrix<T, m, n>::operator[](int col) {
	return mat[col];
}

template <typename T, unsigned m, unsigned n>
const Column<T, m> &Matrix<T, m, n>::operator[](int col) const {
	return mat[col];
}

template <typename T, unsigned m, unsigned n>
Matrix<T, m, n> Matrix<T, m, n>::operator+(const Matrix<T, m, n> &add) const {
	Matrix<T, m, n> ret;

	for (unsigned int i = 0; i < n; ++i) {
		for (unsigned int j = 0; j < m; ++j) {
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

	for (unsigned int i = 0; i < m; ++i) {
		for (unsigned int j = 0; j < o; ++j) {
			ret[j][i] = 0;
			for (unsigned int k = 0; k < n; ++k) {
				ret[j][i] += mat[k][i] * mult[j][k];
			}
		}
	}

	return ret;
}

template <typename T, unsigned m, unsigned n>
Matrix<T, m, n> Matrix<T, m, n>::operator*(const T &mult) const {
	Matrix<T, m, n> ret;

	for (unsigned int i = 0; i < n; ++i) {
		for (unsigned int j = 0; j < m; ++j) {
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

#endif /* MATRIX_INL */

