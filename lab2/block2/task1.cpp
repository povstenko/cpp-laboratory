// Дана цілочислена прямокутна матриця. Визначити:
// 1) добуток елементів в тих рядках, які не містять від’ємних елементів;

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	const unsigned int DIM1 = 3;
	const unsigned int DIM2 = 5;

	int matrix[DIM1][DIM2] = {
		{ 1, 2, 3, 4, 5 }, // <-
		{ 0, 0, -6, 8, 10 },
		{ 3, 5, -9, 0, -1 }
	};

	// Show elements
	for (int i = 0; i < DIM1; i++)
	{
        for (int j = 0; j < DIM2; j++)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }

	cout << "=======================" << endl;

	int mul;
	bool isPositive;

	for (int i = 0; i < DIM1; i++)
    {
		mul = 1;
		isPositive = true;

        for (int j = 0; j < DIM2; j++)
			if (matrix[i][j] < 0)
				isPositive = false;
			else
				mul *= matrix[i][j];

        if (isPositive)
            cout << mul << endl;
        else
            cout << "x" << endl;
    }

	return 0;
}