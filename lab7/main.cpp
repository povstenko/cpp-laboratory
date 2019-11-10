// Скласти програму, яка містить поточну інформацію про заявки на авіаквитки
// Кожна заявка включає:
	// пункт призначення;
	// номер рейсу;
	// прізвище та ініціали пасажира;
	// бажану дату вильоту.
// Програма повинна забезпечувати:
	// зберігання всіх заявок у вигляді двійкового дерева;
	// додавання і видалення заявок;
	// по заданому номеру рейсу і дату вильоту виведеннязаявок з їх подальшим видаленням;
	// виведення всіх заявок.

#include <iostream>
#include <string>
using namespace std;

struct Ticket
{
	string destination;
	int number;
	string name;
	string date;
};

struct Tree
{
	int key;
	Ticket data;
	Tree *left = NULL;
	Tree *right = NULL;
};

void AddToTree(Tree* root, Tree* new_element)
{
	if (root->key > new_element->key  && root->left != NULL)
		AddToTree(root->left, new_element);
	if (root->key < new_element->key  && root->right != NULL)
		AddToTree(root->right, new_element);
 
	if (root->key > new_element->key  && root->left == NULL)
		root->left = new_element;
	if (root->key < new_element->key  && root->right == NULL)
		root->right = new_element;
}

void InputElement(Tree* root)
{
	cout << "\n_______________________________________\n";
	Tree *a1 = new Tree;

	cout << "Enter flight number: "; cin >> a1->key;
	cout << "Enter destination: "; cin >> a1->data.destination;
	cout << "Enter owner's name: "; cin >> a1->data.name;
	cout << "Enter flight date: "; cin >> a1->data.date;
	a1->data.number = a1->key;

	AddToTree(root, a1);
}

void CountLevels(Tree *root_d, int &i, int &max_level)
{
	if (root_d->left != NULL)
	{
		i++;
		if (max_level < i)
			max_level = i;
		CountLevels(root_d->left, i, max_level);
		i--;
	}
	if (root_d->right != NULL)
	{
		i++;
		if (max_level < i)
			max_level = i;
		CountLevels(root_d->right, i, max_level);
		i--;
	}
}

void DisplayLevel(Tree *root_d, int &i, int CountLevels)
{
	if (i == CountLevels)
		cout << root_d->key << "(" << root_d->data.name << ") ";
	if (root_d->left != NULL)
	{
		i++;
		DisplayLevel(root_d->left, i, CountLevels);
		i--;
	}
	if (root_d->right != NULL)
	{
		i++;
		DisplayLevel(root_d->right, i, CountLevels);
		i--;
	}
}

void DisplayAll(Tree *root)
{
	int i = 0;//нужна для сквозной нумерации уровня в рекурсиях.(по крайней мере моя башка не придумала ничего лучше этого костыля)
	int max_level = 0;
	CountLevels(root, i, max_level); //---узнаю максимальный уровень дерева
	cout << "max CountLevels = " << max_level << endl;
	for (int CountLevels = 0; CountLevels <= max_level; CountLevels++) //--цикл поочереди выводит каждый уровень девера, начиная с корняж
	{
		if (CountLevels == 0)
			cout << "[ root ] : ";
		else
			cout << "[" << CountLevels << " lvl] : ";
		DisplayLevel(root, i, CountLevels);//--функция вывода 1 уровня  дерева  
		cout << endl;
	}
}

void Search(Tree* root, int key)
{
	if (root->key == key)
		cout << root->key << ": " <<  root->data.name << endl;
	else if (key < root->key)
		return Search(root->left, key);
	else
		return Search(root->right, key);
}

void Delete_1(Tree* r, Tree* q)
{
	Tree* s;

	if(r->right==NULL)
    {
		q->key = r->key;
		q = r; 
		s = r;
		r = r->left;
	  delete s;
	}
  else Delete_1 (r->right, q);
}
void Delete(Tree* root, int key)
{
	Tree* q;

	if(root == NULL)
		cout << "root is NULL\n";
	else if(key < root->key)
		Delete(root->left, key); 
    else if(key > root->key)
		Delete(root->right, key); 
    else
	{ 
		q = root; 
		if(q->right == NULL)
		{
			root = q->left;
			delete q;
		} 
		else if(q->left == NULL)
		{
			root = q->right;
			delete q;
		}
        else
			Delete_1(q->left, q);
	}
}

int main()
{
	Tree *root = NULL;
	Tree *a0 = new Tree;
	cout << "Enter root:" << endl;
	cout << "Enter flight number: "; cin >> a0->key;
	cout << "Enter destination: "; cin >> a0->data.destination;
	cout << "Enter owner's name: "; cin >> a0->data.name;
	cout << "Enter flight date: "; cin >> a0->data.date;
	a0->data.number = a0->key;
	root = a0;

	/////////////////////////////////////////

	for(int i = 0; i < 3; i++)
	{
		system("clear");
		DisplayAll(root);
		InputElement(root);		
	}

	char flag = 'y';
	while(flag == 'y' || flag != 'n')
	{
		int n;
		cout << "Search ticket by flight number: "; cin >> n;
		Search(root, n);
		cout << "Delete(y/n)? "; cin >> flag;
		if(flag == 'y')
			Delete(root, n);
		cout << "Search again(y/n)? "; cin >> flag;
	}
	
	DisplayAll(root);

	return 0;
}