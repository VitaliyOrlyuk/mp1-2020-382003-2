#pragma once

#include <iostream>
//#include "Vector.h"

class Matrix
{
	double** Val;
	int nR;    // число строк
	int nC;    //число столбцов
public:
	Matrix(int nR = 5, int nC = 5);
	Matrix(const Matrix& m2);
	~Matrix();
	Matrix operator+(const Matrix& m2) const;
	Matrix& operator=(const Matrix& m2);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& d);
	friend std::istream& operator >> (std::istream& is, const Matrix& d);
	Matrix operator-(const Matrix& m2) const;
	Matrix& operator+=(const Matrix& m2);
	Matrix& operator-=(const Matrix& m2);
	friend Matrix operator*(const Matrix& m2, double c);

	double* operator[](int i);
	const double* operator[](int i)const;

};