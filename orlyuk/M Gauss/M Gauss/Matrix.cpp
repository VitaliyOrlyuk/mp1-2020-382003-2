#include "Matrix.h"
#include <memory>


Matrix::Matrix(int nR1, int nC1)
{
	nR = nR1;
	nC = nC1;
	Val = new double*[nR];
	for (int i = 0; i < nR; i++)
		Val[i] = new double[nC];
	for (int i = 0; i < nR; i++)
		for (int j = 0; j < nC; j++)
			Val[i][j] = (double)(rand() % 10);
}

Matrix::Matrix(const Matrix& m2) : nR(m2.nR), nC(m2.nC)
{
	Val = new double*[nR];
	for (int i = 0; i < nR; i++)
		Val[i] = new double[nC];
	for (int i = 0; i < nR; i++)
		for (int j = 0; j < nC; j++)
			Val[i][j] = m2.Val[i][j];
}

Matrix::~Matrix()
{
	for (int i = 0; i < nR; i++)
		delete[] Val[i];
	delete[] Val;
}

Matrix Matrix::operator+(const Matrix& m2) const
{
	if (nR == m2.nR && nC == m2.nC)
	{
		Matrix res(nR, nC);

		for (int i = 0; i < nR; i++)
			for (int j = 0; j < nC; j++)
				res.Val[i][j] = Val[i][j] + m2.Val[i][j];

		return res;
	}
}

Matrix Matrix::operator-(const Matrix& m2) const
{
	if (nR == m2.nR && nC == m2.nC)
	{
		Matrix res(nR, nC);

		for (int i = 0; i < nR; i++)
			for (int j = 0; j < nC; j++)
				res.Val[i][j] = Val[i][j] - m2.Val[i][j];

		return res;
	}
}

Matrix& Matrix::operator=(const Matrix& m2)
{
	if (&m2 == this)
		return *this;
	else
	{
		if ((nR != m2.nR) && (nC != m2.nC))
		{
			for (int i = 0; i < nR; i++)
				delete[] Val[i];
			delete[] Val;
			nR = m2.nR;
			nC = m2.nC;
			Val = new double*[nR];
			for (int i = 0; i < nR; i++)
				Val[i] = new double[nC];
		}
		for (int i = 0; i < nR; i++)
			for (int j = 0; j < nC; j++)
				Val[i][j] = m2.Val[i][j];
		return *this;
	}
}

std::ostream& operator<<(std::ostream& os, const Matrix& d)
{
	for (int i = 0; i < d.nR; i++)
	{
		for (int j = 0; j < d.nC; j++)
		{
			os << d.Val[i][j] << "\t";
		}
		os << std::endl;
	}
	os << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, const Matrix& d)
{
	std::cout << "¬ведите число строк в матрице" << std::endl;
	is >> d.nR;
	std::cout << "¬ведите число столбцов в матрице" << std::endl;
	is >> d.nC;
	return is;
}

Matrix& Matrix::operator+=(const Matrix& m2)
{
	if (nR == m2.nR && nC == m2.nC)
	{
		for (int i = 0; i < nR; i++)
			for (int j = 0; j < nC; j++)
				Val[i][j] += m2.Val[i][j];

	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m2)
{
	if (nR == m2.nR && nC == m2.nC)
	{
		for (int i = 0; i < nR; i++)
			for (int j = 0; j < nC; j++)
				Val[i][j] -= m2.Val[i][j];

	}
	return *this;
}

Matrix operator*(const Matrix& m2, double c)
{
	Matrix res(m2.nR, m2.nC);
	for (int i = 0; i < m2.nR; i++)
		for (int j = 0; j < m2.nC; j++)
			res.Val[i][j] = c * m2.Val[i][j];
	return res;
}



double* Matrix::operator[](int i)
{
	if ((i >= 0) && (i < nC))
		return Val[i];
	else
		return Val[0];
}

const double* Matrix::operator[](int i) const
{
	if ((i >= 0) && (i < nR))
		return Val[i];
	else
		return Val[0];
}