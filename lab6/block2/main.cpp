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

	while(c != '.')
	{
		cin >> c;
		system("clear");

		if(cntr == 1)
		{
			cout << ">" << sentences[0] << endl;
			cout << sentences[1] << endl;
			cout << sentences[2] << endl;

			cntr = 3;
		}
		else if(cntr == 2)
		{
			cout << sentences[0] << endl;
			cout << ">" << sentences[1] << endl;
			cout << sentences[2] << endl;

			cntr = 1;
		}
		else if(cntr == 3)
		{
			cout << sentences[0] << endl;
			cout << sentences[1] << endl;
			cout << ">" << sentences[2] << endl;

			cntr = 2;
		}
	}

	return 0;
}