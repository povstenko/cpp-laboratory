#include <iostream>
#include <math.h>
using namespace std;

double compute_factorial(double x)
{
    double result = 1;
    for (double i = 1; i <= x; i++)
        result *= i;

    return result;
}

void compute_row(double x, double eps)
{   
    int n = 0;
    double x_n = 0, sum = 0, sum_n = 0;

    do{
        sum_n = sum;
        // x_n = n*pow(x,n);
        x_n = pow(x, n) / compute_factorial(n);
        sum += pow((-1), n) * x_n;
        n += 2;
        if(abs(x_n) == INFINITY) break;
    } while(abs(sum - sum_n) > eps);

    cout << "| " << x << " | " << sum << " | " << n - 2 << " |" << endl;
}

int main()
{
    double x_start = 0, x_end, eps, d;
    
    cout << "Enter start x: "; cin >> x_start;
    cout << "Enter end x: "; cin >> x_end;
    cout << "Enter eps: "; cin >> eps;
    cout << "Enter d: "; cin >> d;
    
    cout << "_____________________" << endl;
    cout << "|  x  | sum |  n  |" << endl;

    for (int i = 0; (x_start + d * i) <= x_end; i++)
		compute_row((x_start + d * i), eps);

    cout << "_____________________" << endl;
    
    return 0;
}