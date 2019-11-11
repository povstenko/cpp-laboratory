//Вивчити алгоритм і реалізувати інтерполяційний поліном Лагранжа.
// x     2 5  -6   7   4  3 8   9   1  -2
// f(x) -1	77 -297 249 33 9 389 573 -3 -21

#include <iostream>
using namespace std;
const int n=10;

double lagranz(double X[n],  double Y[n],  double t){
	double z = 0,  p1,  p2;

	for(int j = 0; j < n; j++)
	{
		p1 = 1;
		p2 = 1;
		for(int i = 0; i < n; i++){
			if (i == j)
			{
				p1 = p1 * 1;
				p2 = p2 * 1;
			}
			else
			{
				p1 = p1 * (t - X[i]);
				p2 = p2 * (X[j] - X[i]);
			}
		}
		z = z + Y[j] * p1 / p2;
	}
	return z;
}

int main()
{
	double X[n] = {2, 5, -6, 7, 4, 3, 8, 9, 1, -2};
    double Y[n] = {-1, 77, -297, 249, 33, 9, 389, 573, -3, -21};

	cout << "x     2 5  -6   7   4  3 8   9   1  -2" << endl;
	cout << "f(x) -1	77 -297 249 33 9 389 573 -3 -21" << endl << endl;

	int arg;
	cout << "Enter function argument: "; cin >> arg;
    cout << "Ln(" << arg << ") = " << lagranz(X, Y, arg) << endl;
    return 0;
}