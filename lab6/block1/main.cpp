// Написати програму, яка зчитує текст англійською мовою з файлу і
// виводить на екран слова, що починаються з голосних букв.


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <list>
using namespace std;

int main()
{
	string line, text;
	ifstream file("file.txt");
	while (getline(file, line)) // read from file to text
		text += line;
	file.close();

	// separate text to words
	char *s = new char[text.size() + 1];
	strcpy(s, text.c_str());
	char *p = strtok(s, ",.!?; ");

	list<string> words;
	while(p != NULL)
	{
		string el(p);
		words.push_back(el);
		p = strtok(NULL, ",.!?; ");
	}

	// words selection by first letter  A, E, I, O, U, Y
	list<string> selectedWords;
	for(string word : words)
		if(toupper(word[0]) == 'A' || toupper(word[0]) == 'E' || toupper(word[0]) == 'I'
		 || toupper(word[0]) == 'O' || toupper(word[0]) == 'U' || toupper(word[0]) == 'Y')
			selectedWords.push_back(word);
	
	// print selected words
	for(string word : selectedWords)
		cout << word << " ";
	cout << endl;

	delete[] s;
	return 0;
}