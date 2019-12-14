// Зчитати шість чисел типу int в матрицю Мatrix <int, 2> m (2,3) і виведіть їх
// на екран.
 
#include <iostream>
#include "Matrix.h"
using namespace Numeric_lib;
using namespace std;

int main()
{	
	Matrix<int, 2> matrix(2, 3);

	// init
	for (int i = 0; i < matrix.dim1(); ++ i)
		for (int j = 0; j < matrix.dim2(); ++ j)
		{
			cout << "Enter " << i << "/"<< j << ": "; cin >> matrix(i, j);
		}

	// print
	for (int i = 0; i < matrix.dim1(); ++ i)
	{
		for (int j = 0; j < matrix.dim2(); ++ j)
			cout << matrix(i, j) << '\t';
		cout << '\n';
	}

	return 0;
}