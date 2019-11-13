// Вважайте десять чисел з плаваючою точкою з потоку введення і запишіть
// їх у матрицю Мatrix<double>. Клас Мatrix не має функції push_back (), тому
// будьте обережні і передбачте реакцію на спробу ввести невірне кількість чисел
// типу double. Виведіть цю матрицю на екран.
 
#include <iostream>
#include "Matrix.h"
using namespace Numeric_lib;
using namespace std;

int main()
{	
	int i, j;
	cout << "Enter i, j: "; cin >> i >> j;
	Matrix<double, 2> matrix(i, j);

	// init
	for (int i = 0; i < matrix.dim1(); ++ i)
		for (int j = 0; j < matrix.dim2(); ++ j)
		{
			cout << "Enter " << i << "/"<< j << ": "; cin >> matrix(i, j);
		}
			//matrix(i, j) = 10 * i + j;

	// print
	for (int i = 0; i < matrix.dim1(); ++ i)
	{
		for (int j = 0; j < matrix.dim2(); ++ j)
			cout << matrix(i, j) << '\t';
		cout << '\n';
	}

	return 0;
}