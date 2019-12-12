// Для зберігання даних про планшетні сканери описа
// struct scan_info {
// char model [25]; // найменування моделі
// int price; // ціна
// double x_size; // горизонтальний розмір областdouble y_size; // вертикальний розмір області int optr; // оптична роздільна здатність
// int grey; // число градацій сірого

// Написати функцію, яка динамічно виділяє пам'ять під масив структур (не
// менш шести елементів), заповнює його даними в режимі діалогу і записує масив
// в бінарний файл. Структура файлу: в перших двох байтах розміщує значення
// типу int, що визначає кількість зроблених в файл записів; далі без пропусків
// розміщуються записи про сканерах.
//
// Написати функцію, яка запитує дані про сканер в режимі діалогу і заміщає
// записи в бінарному файлі по заданому номеру. Обов'язковий параметр - номер
// замещаемой записи. Функція повинна повертати нульове значення, якщо запис
// пройшла успішно, і -1 в іншому випадку.

// Привести приклад програми, що створює файл з даними про сканери (дані
// вводяться з клавіатури) з не менше восьми записами і здійснює виведення на
// дисплей даних про необхідної записи.
// Всі необхідні дані для функцій повинні передаватися їм в якості
// параметрів. Використання глобальних змінних у функціях не допускається.


#include <iostream>
#include <fstream>
using namespace std;

struct scan_info {
	string model; // найменування моделі
	int price; // ціна
	double x_size; // горизонтальний розмір област
	double y_size; // вертикальний розмір області
	int optr; // оптична роздільна здатність
	int grey; // число градацій сірого
};

scan_info* AddScans(scan_info* obj, const int amount)
{
	if(amount == 0)
		obj = new scan_info[amount+1];
	else
	{
		scan_info* tmp = new scan_info[amount+1];
		for(int i = 0; i < amount; i++)
			tmp[i] = obj[i]; // copy to tmp

		delete[] obj;
		obj = tmp;
	}
}

void SetScans(scan_info* obj, const int amount)
{
	cout << "Model: "; cin >> obj[amount].model;
	cout << "Price: "; cin >> obj[amount].price;
	cout << "X size: "; cin >> obj[amount].x_size;
	cout << "Y size: "; cin >> obj[amount].y_size;
	cout << "Grey: "; cin >> obj[amount].grey;
	cout << endl;
}

void ShowScans(scan_info* obj, const int amount)
{
	cout << "№  Model\tPrice\tX/Ysize\tGrey\t" << endl;
	cout << "========================================" << endl;
	for (int i = 0; i < amount; i++)
		cout << i + 1 << "  " << obj[i].model << '\t' << obj[i].price << '\t' << obj[i].x_size << '/' << obj[i].y_size << '\t'<< obj[i].grey << endl;
}

void WriteScans(scan_info* obj, const int amount)
{
	ofstream ofs("test.txt");

	ofs.write((char*) &amount, sizeof(int));
	ofs << endl;

	for (int i = 0; i < amount; i++)
	{
		ofs << (string)obj[i].model << endl;
		ofs << obj[i].price << endl;
		ofs << obj[i].x_size << endl;
		ofs << obj[i].y_size << endl;
		ofs << obj[i].grey << endl;
	}

	ofs.close();
}

int ReadScanById(int id)
{
	try
	{
		scan_info* obj;
		int amount;
		fstream ifs;

		ifs.open("test.txt", ios::in);
		ifs.read((char*) &amount, sizeof(int));
		obj = new scan_info[amount];
		ifs.ignore();
		
		if(ifs)
		{
			for(int i = 0; i < amount; i++)
			{
				string model = "", price = "", x = "", y = "", grey = "";

				getline(ifs, model);
				getline(ifs, price);
				getline(ifs, x);
				getline(ifs, y);
				getline(ifs, grey);

                obj[i].model = model;
				obj[i].price = stoi(price, nullptr, 10);
				obj[i].x_size = stod(x);
				obj[i].y_size = stod(y);
				obj[i].grey = stoi(grey, nullptr,10);
			}
		}

		// Show result

		cout << "Model: " << obj[id].model << endl;
		cout << "Price: " << obj[id].price << endl;
		cout << "X size: " << obj[id].x_size << endl;
		cout << "Y size: " << obj[id].y_size << endl;
		cout << "Grey: "<< obj[id].grey << endl;

		if(id >= 0 && id < amount) return 0;
		else return -1;
	}
	catch(const exception& e)
	{
		cerr << e.what() << '\n';
		return -1;
	}
}

int ReplaceScanById(int id)
{
	try
	{
		scan_info* obj;
		int amount;
		fstream ifs;

		ifs.open("test.txt", ios::in);
		ifs.read((char*) &amount, sizeof(int));
		obj = new scan_info[amount];
		ifs.ignore();
		
		if(ifs)
		{
			for(int i = 0; i < amount; i++)
			{
				string model = "", price = "", x = "", y = "", grey = "";

				getline(ifs, model);
				getline(ifs, price);
				getline(ifs, x);
				getline(ifs, y);
				getline(ifs, grey);

                obj[i].model = model;
				obj[i].price = stoi(price, nullptr, 10);
				obj[i].x_size = stod(x);
				obj[i].y_size = stod(y);
				obj[i].grey = stoi(grey, nullptr,10);

				
			}
		}
		ifs.close();

		// write new values
		cout << "Enter new scan." << endl;
		cout << "Model: "; cin >> obj[id].model;
		cout << "Price: "; cin >> obj[id].price;
		cout << "X size: "; cin >> obj[id].x_size;
		cout << "Y size: "; cin >> obj[id].y_size;
		cout << "Grey: "; cin >> obj[id].grey;
		cout << endl;

		// write all values
		ofstream ofs("test.txt");

		ofs.write((char*) &amount, sizeof(int));
		ofs << endl;

		for (int i = 0; i < amount; i++)
		{
			ofs << (string)obj[i].model << endl;
			ofs << obj[i].price << endl;
			ofs << obj[i].x_size << endl;
			ofs << obj[i].y_size << endl;
			ofs << obj[i].grey << endl;
		}

		ofs.close();

		if(id >= 0 && id < amount) return 0;
		else return -1;
	}
	catch(const exception& e)
	{
		cerr << e.what() << '\n';
		return -1;
	}
}

int main()
{
	scan_info* scans = 0;
	int scans_amount = 0;
	char isEnter = 'n';
	char isRead = 'n';
	char isReplace = 'n';

	cout << "Read file from id?(y/n): "; cin >> isRead;

	if(isRead == 'y')
	{
		int id;
		cout << "Enter id: "; cin >> id;

		while(ReadScanById(id) != 0)
		{
			cout << "Error! Something wrong!\nEnter id: "; cin >> id;
		}

		cout << "Do you want to replace this scanner?(y/n): "; cin >> isReplace;

		if(isReplace == 'y')
		{
			while(ReplaceScanById(id) != 0)
			{
				cout << "Error! Something wrong!";
			}
		}	
	}

	

	cout << endl;

	cout << "Add scans." << endl;
	do
	{
		scans = AddScans(scans, scans_amount);
		SetScans(scans, scans_amount);

		scans_amount++;

		cout << "Continue enter?(y/n): "; cin >> isEnter;

	} while(isEnter == 'y');
	
	WriteScans(scans, scans_amount);
	ShowScans(scans, scans_amount);

	delete[] scans;
	return 0;
}
