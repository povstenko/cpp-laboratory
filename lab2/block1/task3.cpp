// 3. Стиснути масив, видаливши з нього всі елементи, модуль яких не
// перевищує 1. Вивільнені в кінці масиву елементи заповнити нулями.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int arr[] = {1, -1, 1, 2, 0, -10, 1, 3};
	int size = sizeof(arr)/sizeof(*arr);

	// Copying elements to new array
	int buf[size] = {};
	int cntr = 0;
	for (int i = 0; i < size; i++)
		if(abs(arr[i]) > 1)
		{
			buf[cntr] = arr[i];
			cntr++;
		}

	// Show all elements
	for(int i : buf)
		cout << i << endl;

	return 0;
}