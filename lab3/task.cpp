// Описати структуру з ім'ям KYIVAVIA, що містить наступні поля: назва
// пункту призначення рейсу; номер рейсу; тип літака.
// Написати програму, що виконує наступні дії:
// • введення з клавіатури даних в масив, що складається з семи
// елементів типу KYIVAVIA; записи повинні бути впорядковані за
// зростанням номера рейсу;
// • виведення на екран номерів рейсів і типів літаків, що вилітають в
// пункт призначення, назва якого співпало з назвою, введеним з
// клавіатури;
// • якщо таких рейсів немає, видати на дисплей відповідне
// повідомлення.

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct KyivAvia
{
	string destination;
	int flightNumber;
	string planeType;
};

bool comp(KyivAvia a, KyivAvia b) {
	return a.flightNumber < b.flightNumber;
}

void ShowAvia(KyivAvia var)
{
	cout << "Numb: " << var.flightNumber << endl;
	cout << "Dest: " << var.destination << endl;
	cout << "Type: " << var.planeType << endl;
}

int main()
{	
	const int SIZE = 7;	KyivAvia avias[SIZE] = {};
	
	// Enter values
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << endl;
		cout << "Enter destination: "; cin >> avias[i].destination;
		cout << "Enter flight number: "; cin >> avias[i].flightNumber;
		cout << "Enter airplane type: "; cin >> avias[i].planeType;
	}

	// Sort tickets
	sort(avias, avias + SIZE, comp);

	// Show all tickets
	for(KyivAvia var: avias)
	{
		cout << "-------------------\n";
		ShowAvia(var);
	}
	cout << "-------------------\n\n";

	string key;
	while (true)
	{
		cout << "Search tickets by destination.\nEnter destination: "; cin >> key;

		// Counting searches
		int n = 0;
		for(KyivAvia i: avias)
			if(i.destination == key)
				n++;
		
		if(n != 0)
		{
			KyivAvia results[n];
			int cntr = 0;

			// Copying results
			for(KyivAvia i: avias)
				if(i.destination == key)
				{
					results[cntr] = i;
					cntr++;
				}

			cout << "Search results:\n";

			// Show all results
			for(KyivAvia var: results)
			{
				cout << "-------------------\n";
				ShowAvia(var);
			}
			cout << "-------------------\n\n";
		}
		else
			cout << "No results for " + key + ".\n";

		char answer;
		cout << "Do you want to search again (y/n)? "; cin >> answer;
		if(answer != 'y')
			return 0;
	}
}