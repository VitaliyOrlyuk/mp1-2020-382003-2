#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main()
{
	Matrix A(5, 5);
	Matrix B(5, 5);
	Vector b(5);
	cout << "Matrix A:\n" << A << endl;
	cout << "Matrix B:\n" << B << endl;
	cout << "Matrix A+B:\n" << (A + B) << endl;
	cout << "Matrix A-B:\n" << (A - B) << endl;
	cout << "Vector b:\n" << b << endl;
	cout << "Vector A*b\n" << (A*b) << endl;
	return 0;
}