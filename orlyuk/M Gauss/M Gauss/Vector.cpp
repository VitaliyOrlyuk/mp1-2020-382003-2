#include "Vector.h"
#include <memory>

Vector::Vector(int n)
{
	len = n;
	Vec = new double[len];
	for (int i = 0; i < n; i++)
	{
		Vec[i] = (double)(rand() % 8);
	}
}

Vector::Vector(const Vector& V) : len(V.len)
{
	len = V.len;
	Vec = new double[len];
	for (int i = 0; i < len; i++)
	{
		Vec[i] = V.Vec[i];
	}
}

Vector::~Vector()
{
	delete[] Vec;
}

std::ostream& operator<<(std::ostream& os, const Vector& c)
{
	for (int i = 0; i < c.len; i++)
		os << c.Vec[i] << "\n";
	os << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, const Vector& c)
{
	for (int i = 0; i << c.len; i++)
	{
		std::cout << "" << std::endl;
		is >> c.Vec[i];
	}
	return is;
}

Vector Vector::operator+(const Vector& V) const
{
	if (len == V.len)
	{
		Vector res(len);

		for (int i = 0; i < len; i++)
			res.Vec[i] = Vec[i] + V.Vec[i];

		return res;
	}
}

Vector Vector::operator-(const Vector& V) const
{
	if (len == V.len)
	{
		Vector res(len);

		for (int i = 0; i < len; i++)
			res.Vec[i] = Vec[i] + V.Vec[i];

		return res;
	}
}

Vector& Vector::operator=(const Vector& V)
{
	if (this == &V)
	{
		return *this;
	}
	else
		if (len != V.len)
		{
			delete[] Vec;

			len = V.len;
			Vec = new double[len];
			for (int i = 0; i < len; i++)
				Vec[i] = V.Vec[i];
			return *this;
		}
	for (int i = 0; i < len; i++)
		Vec[i] = V.Vec[i];
	return *this;
}

Vector& Vector::operator+=(const Vector& V)
{
	if (len = V.len)
	{
		for (int i = 0; i < len; i++)
			Vec[i] += V.Vec[i];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& V)
{
	if (len = V.len)
	{
		for (int i = 0; i < len; i++)
			Vec[i] -= V.Vec[i];
	}
	return *this;
}

double& Vector::operator[](int i)
{
	if ((i >= 0) && (i < len))
		return Vec[i];
	else
		return Vec[0];
}

const double& Vector::operator[](int i)const
{
	if ((i >= 0) && (i < len))
		return Vec[i];
	else
		return Vec[0];
}


Vector operator*(const Matrix& m2, const Vector& V)
{
	Vector res(V.len);
	for (int i = 0; i < res.len; i++)
	{
		res[i] = 0.0;
		for (int j = 0; j < res.len; j++)
		{
			res[i] += m2[i][j] * V[j];
		}
	}
	return res;
}