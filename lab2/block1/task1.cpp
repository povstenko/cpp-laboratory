// 1. Знайти суму елементів масиву з непарними номерами.

#include <iostream>
#include <array>
using namespace std;

int main()
{
	int  arr[] = {1, -1, 1, 2, 0};
    int res = 0;

	for(int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
		if(i % 2 != 0)
		{
			res += arr[i];
			cout << "(" << arr[i] << ") + ";
		}
        
    cout << " = " << res << endl;

	return 0;
}