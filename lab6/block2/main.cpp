// За допомогою текстового редактора створити файл, що містить текст,
// довжина якого не перевищує 1000 символів. Текст має складатися з трьох
// пропозицій (довжина рядка тексту не повинна перевищувати 70 символів). Назва
// файлу повинна мати розширення DAT. Написати програму, яка:
// □ виводить текст на екран дисплея;
// □ після натискання довільної клавіші по черзі виділяє кожне речення
// тексту в послідовності 2, 1, 3.

#include <iostream>
#include <string.h>
#include <fstream>
#include <list>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
using namespace std;

int main()
{
	string line, text;
	string sentences[3] = {};
	ifstream file("file.dat");

	// read from file to text
	while (getline(file, line))
		text += line;
	file.close();

	// separate text by sentences
	char *s = new char[text.size() + 1];
	strcpy(s, text.c_str());
	char *p = strtok(s, ".");
	for(int i = 0; p != NULL; i++)
	{
		string el(p);
		sentences[i] = el;
		p = strtok(NULL, ".");
	}

	// print sentences
	for(string sentence : sentences)
		cout << sentence << endl;

	char c;
	unsigned short int cntr = 2; // containes 2, 1, 3

	short order[] = {2, 1, 3};
	short order_index = 0;

	while(c != '.')
	{
		cin >> c;
		system("clear");

		order_index++;

		if(order_index > 2) order_index = 0;

		short selected_index = order[order_index] - 1;
		for(int i = 0; i < 3; i++){
			if(i == selected_index)
				cout << ">";
			cout << sentences[i] << endl;
		}

	}

	return 0;
}