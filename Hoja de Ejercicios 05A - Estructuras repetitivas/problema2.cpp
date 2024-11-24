#include "problema2.h"
#include <iostream>
#include <cmath>
using namespace std;

long long factorial2(int n)
{
    long long factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    return factorial;
}

void problema2()
{
    int n, x, y;
    long double sumatoria = 0.0;

    do
    {
        cout << "Ingrese el valor de n: ";
        cin >> n;
    }
    while (n <= 1 || n > 10);

    do
    {
        cout << "Ingrese el valor de x: ";
        cin >> x;
    }
    while (x < 2 || x > 5);

    do
    {
        cout << "Ingrese el valor de y: ";
        cin >> y;
    }
    while (y < 1 || y > 9);

    long double parte_constante = sqrt(x) * pow(y, 2 + x);

    for (int i = 2; i <= n; i++)
    {
        long double parte_variable = (factorial2(i)) / pow(y, i + 1) * sin(x);
        sumatoria += parte_constante + parte_variable;
    }

    cout << "La sumatoria es: " << sumatoria;
}
