// Написати програму, яка зчитує текст з файлу і виводить на екран тільки
// речення, які не містять ком.


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

	// separate text to sentences
	char *s = new char[text.size() + 1];
	strcpy(s, text.c_str());
	char *p = strtok(s, ".!?");

	list<string> sentences;
	while(p != NULL)
	{
		string el(p);
		sentences.push_back(el);
		p = strtok(NULL, ".!?");
	}

	// sentences selection by ","
	list<string> selectedSentences;
	for(string sentence : sentences)
	{
		string buf = sentence;
		buf.erase(buf.find(','), 1);
		if(sentence != buf)
			selectedSentences.push_back(sentence);
	}	
	
	// print selected sentences
	for(string sentence : selectedSentences)
		cout << sentence << " ";
	cout << endl;

	delete[] s;
	return 0;
}