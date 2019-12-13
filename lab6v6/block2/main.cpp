// За допомогою текстового редактора створити файл, що містить текст,
// довжина якого не перевищує 1000 символів. Текст має складатися з трьох
// пропозицій (довжина рядка тексту не повинна перевищувати 70 символів). Назва
// файлу повинна мати розширення DAT. Написати програму, яка:
// □ виводить текст на екран дисплея;
// □ після натискання довільної клавіші по черзі виділяє кожне слово тексту, що починається на голосну букву;
// □ визначає кількість слів у тексті, що починаються на голосну букву.

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
	// string sentences[3] = {};
	list<string> words;
	ifstream file("file.dat");

	// read from file to text
	while (getline(file, line))
		text += line;
	file.close();

	// separate text by words
	char *s = new char[text.size() + 1];
	strcpy(s, text.c_str());
	char *p = strtok(s, " .,!?");
	for(int i = 0; p != NULL; i++)
	{
		string el(p);
		words.push_back(el);
		p = strtok(NULL, " .,!?");
	}

	// print words
	for(string word : words)
		cout << word << " ";
	cout << endl;

	// counting words
	list<string> aeiouy_list;
	for(string word : words)
		if(toupper(word[0]) == 'A' || toupper(word[0]) == 'E' || toupper(word[0]) == 'I'
		 || toupper(word[0]) == 'O' || toupper(word[0]) == 'U' || toupper(word[0]) == 'Y')
			aeiouy_list.push_back(word);
	cout << "Number of words: " << aeiouy_list.size() << endl;

	// list to array
	string aeiouy_arr[aeiouy_list.size()];
	int cntr = 0;
	for(string word : aeiouy_list)
	{
		aeiouy_arr[cntr] =  word;
		cntr++;
	}

	cntr = 0;
	char c;

	while(c != '.')
	{
		if(cntr == aeiouy_list.size())
			cntr = 0;

		cin >> c;
		system("clear");

		for(string word : words)
			if(word == aeiouy_arr[cntr])
				cout << "(" << word << ") ";
			else
				cout << word << " ";
		cout << endl;
		cntr++;
	}

	return 0;
}