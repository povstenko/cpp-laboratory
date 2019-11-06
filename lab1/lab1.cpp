#include <iostream>
#include <string.h>
using namespace std;

void printN(string id,int n)
{
    cout << "\n[n" << id << "]: " << n;
    cout << "\nn + 3: " << n + 3;
    cout << "\nn + 6: " << n + 6;
    cout << "\nn + 9: " << n + 9;
    cout << "\nn + 12: " << n + 12;
    cout << "\nn + 15: " << n + 15;
}

int main()
{
    int n1, n2, n3, n4, n5;

    cout << "Enter values" << endl;
    cout << "Enter [n1]: "; cin >> n1;
    cout << "Enter [n2]: "; cin >> n2;
    cout << "Enter [n3]: "; cin >> n3;
    cout << "Enter [n4]: "; cin >> n4;
    cout << "Enter [n5]: "; cin >> n5;

    printN("1", n1);
    printN("2", n2);
    printN("3", n3);
    printN("4", n4);
    printN("5", n5);


    return 0;
}