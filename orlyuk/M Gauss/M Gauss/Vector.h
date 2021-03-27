#pragma once

#include "Matrix.h"
#include <iostream>

class Vector
{
	double* Vec;
	int len;

public:
	Vector(int n = 5);
	Vector(const Vector& V);
	~Vector();
	friend std::ostream& operator<<(std::ostream& os, const Vector& c);
	friend std::istream& operator >> (std::istream& is, const Vector& c);
	Vector operator+(const Vector& V)const;
	Vector operator-(const Vector& V)const;
	Vector& operator=(const Vector& V);
	Vector& operator+=(const Vector& V);
	Vector& operator-=(const Vector& V);
	double& operator[](int i);
	const double& operator[](int i)const;
	friend Vector operator*(const Matrix& m2, const Vector& V);
	//friend class Matrix;
};