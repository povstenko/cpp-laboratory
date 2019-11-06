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
	list<string> sentences;
	ifstream file("file.dat");

	// read from file to text
	while (getline(file, line))
		text += line;
	file.close();

	// separate text by sentences
	char *s = new char[text.size() + 1];
	strcpy(s, text.c_str());
	char *p = strtok(s, ".");
	while(p != NULL)
	{
		string el(p);
		sentences.push_back(el);
		p = strtok(NULL, ".");
	}

	// print sentences
	for(string sentence : sentences)
		cout << sentence << endl;

	char c;

	for(int i = 0; c != '.'; i++)
	{
		cin >> c;
		system("clear");
	
		if(i%1 == 0){cout << ">";}
		cout  << next(sentences.begin, 0) << endl;

		if(i%2 == 0){cout << ">";}
		cout  << next(sentences.begin, 1) << endl;

		if(i%3 == 0){cout << ">";}
		cout  << next(sentences.begin, 2) << endl;
	}
	



	return 0;
}