// Дана цілочислена прямокутна матриця. Визначити:
// 2) максимум серед сум елементів діагоналей, паралельних головній
// діагоналі матриці.

#include <iostream>
#include <stdlib.h>
#include <time.h>то тобі не коники з гівна ліпити
using namespace std;

int main()
{
	const unsigned int DIM1 = 6;
	const unsigned int DIM2 = 6;
    int arr[DIM1][DIM2];

	// Random values
    srand(time(NULL));
    for(int i = 0; i < DIM1; i++)
        for(int j = 0; j < DIM2; j++)
            arr[i][j] = rand() % 10;
	
    for(int i = 0; i < DIM1; i++)
    {
        for(int j = 0; j < DIM2; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    int i = 0, j = 0, n = 1;
	int max = 0, temp = 0;

    do
    {
        temp += arr[i][j];
        
        if((j == 5) || (i == 0))
        {
            cout << "\nDiagonal - " << n << " = " << temp;
            if(temp > max)
                max = temp;
            temp = 0;
            n++;
        }
        if((i == 0) && (j < 5))
        {
            i = ++j;
            j = 0;
        }
        else if(j == 5)
		{
			j = ++i;
			i = 5;
		}
        else
		{
			i--;
			j++;
		}

    } while((i < DIM1) && (j < DIM2));

    cout << "\n" << max << endl;
	return 0;
}