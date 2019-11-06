// Виконати варіант завдання з лабораторної роботи 2, п. 2.3.1. Блок завдань
// 1 (стор. 10), оформивши кожен пункт варіанту завдання у вигляді шаблону
// функції. Всі необхідні дані для функцій повинні передаватися їм в якості
// параметрів. Використання глобальних змінних у функціях не допускається.
// Привести приклади програм, що використовують ці шаблони для типів int, float
// і double.

// 1. Знайти суму елементів масиву з непарними номерами.
// 2. Знайти суму елементів масиву, що розташовані між першим і останнім від’ємними елементами.
// 3. Стиснути масив, видаливши з нього всі елементи, модуль яких не
// перевищує 1. Вивільнені в кінці масиву елементи заповнити нулями.

#include <iostream>
#include <array>
using namespace std;

template <class T>
T FindSumWithOddNumbers(T arr[])// find sum with odd numbers
{
	T res = 0;
	for(T i = 0; i < sizeof(arr); i++)
		if(i % 2 != 0)
			res += arr[i];

	return res;
}

template <class T>
T FindSumBetweenNegativeNumbers(T arr[])// find sum between first and last negative numbers
{
	T res = 0;
	int firstIndex, lastIndex;

	// Find first index
	for(int s = sizeof(arr)-1; s >= 0;s--)
		if(arr[s] < 0) firstIndex = s;

	// Find last index
	for(int i = 0; i < sizeof(arr); i++)
		if(arr[i] < 0) lastIndex = i;

	// Find sum
	for(int i = firstIndex+1; i < lastIndex; i++)
		res += arr[i];

	return res;
}

template <class T>
void CompressArray(T* arr)// compress array, deleting elements
{
	// Copying elements to new array
	T* res = new T[sizeof(arr)];

	int cntr = 0;
	for (int i = 0; i < sizeof(arr); i++)
		if(abs(arr[i]) > 1)
		{
			res[cntr] = arr[i];
			cntr++;
		}

	copy(res, res + 8, arr);
}

template <class T>
void ShowArray(T arr[])
{
	for(int i = 0; i < sizeof(arr); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int buf[] = {1, -1, 1, 2, 0, -10, 1, 3};
	int size = sizeof(buf)/sizeof(*buf);
	int* arr = new int[size];

	// copy elements
	for(int i = 0; i < size; i++)
		arr[i] = buf[i];
	
	cout << "Initial array = ";
	ShowArray(arr);
	cout << endl;

	// task 1
	cout << "Sum with odd numbers = " << FindSumWithOddNumbers(arr) << endl;

	// task 2
	cout << "Sum between negative numbers = " << FindSumBetweenNegativeNumbers(arr) << endl;

	// task 3
	cout << "Compressed array = ";
	CompressArray(arr);
	ShowArray(arr);

	return 0;
}