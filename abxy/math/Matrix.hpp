#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstring>

#include <abxy/math/Vector3.hpp>

template <typename T, unsigned m>
class Column {
	T col[m];
public:
	T &operator[](int row);
	const T &operator[](int row) const;

	T &x();
	T &y();
	T &z();
	T &w();
};

template <typename T, unsigned m, unsigned n>
class Matrix {
	Column<T, m> mat[n];
public:
	Matrix();
	Matrix(float diag);
	Matrix(const Matrix<T, n, m> &copy);

	Matrix<T, m, n> &operator=(const Matrix<T, m, n> &copy);

	Column<T, m> &operator[](int col);
	const Column<T, m> &operator[](int col) const;

	Matrix<T, m, n> operator+(const Matrix<T, m, n> &add) const;
	Matrix<T, m, n> &operator+=(const Matrix<T, m, n> &add);

	template <unsigned o>
	Matrix<T, m, o> operator*(const Matrix<T, n, o> &mult) const;

	Matrix<T, m, n> operator*(const T &mult) const;
	Matrix<T, m, n> &operator*(const T &mult);

	// Functions only defined for 4x4s:
	Matrix<T, m, n> &Translate(const Vector3 &trans);
	Matrix<T, m, n> &Scale(const Vector3 &scale);
	Matrix<T, m, n> &Rotate(const Vector3 &axis, float angle);

	const T *GetData() const;
};

typedef Matrix<float, 4, 4> Matrix4;

#include "Matrix.inl"

#endif /* MATRIX_HPP */

