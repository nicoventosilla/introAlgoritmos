//
// Created by c0d3r on 12/09/2024.
//

#include "problema1.h"
#include <iostream>
#include <cmath>
using namespace std;

long long factorial(int n)
{
    long long factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    return factorial;
}

void problema1()
{
    int n, x, y;
    long double sumatoria = 0.0;

    do
    {
        cout << "Ingrese el valor de n (entre 2 y 20): ";
        cin >> n;
    }
    while (n < 2 || n > 20);

    do
    {
        cout << "Ingrese el valor de x (entre 2 y 10): ";
        cin >> x;
    }
    while (x < 2 || x > 10);

    do
    {
        cout << "Ingrese el valor de y (entre 2 y 5): ";
        cin >> y;
    }
    while (y < 2 || y > 5);

    for (int i = 2; i <= n; i++)
    {
        long double suma = pow(y, 2 * x) * pow(x, y) + ((x - y) * factorial(i)) / pow(x, n) * pow(y, i + 1);
        sumatoria += suma;
    }

    cout << "La sumatoria es: " << sumatoria;
}
