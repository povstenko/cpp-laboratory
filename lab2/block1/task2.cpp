// 2. Знайти суму елементів масиву, що розташовані між першим і останнім
// від’ємними елементами.

#include <iostream>
using namespace std;

int main()
{
	int  arr[] = {1, -1, 1, 2, 0, -10, 1, 3};
	int size = sizeof(arr)/sizeof(*arr);
	int res = 0;

	int firstIndex, lastIndex;

	// Find first index
	for(int s = size-1; s >= 0;s--)
		if(arr[s] < 0) firstIndex = s;

	cout << "first index: " << firstIndex << endl;

	// Find last index
	for(int i = 0; i < size; i++)
		if(arr[i] < 0) lastIndex = i;

	cout << "last index: " << lastIndex << endl;

	// Find sum
	for(int i = firstIndex; i <= lastIndex; i++)
	{
		cout << arr[i] << endl;
		res += arr[i];
	}

	cout << "result: " << res <<endl;

	return 0;
}