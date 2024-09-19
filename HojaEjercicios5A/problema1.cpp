//
// Created by c0d3r on 12/09/2024.
//

#include "problema1.h"
#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n)
{
    long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

long long funcion(int n, int x, int y)
{
    return pow(y, 2 * x) * pow(x, y) + ((x - y) * factorial(n) / pow(x, n) * pow(y, n + 1));
}

void problema1()
{
    int n, x, y;
    long long sumatoria = 0;

    do
    {
        cout << "Ingrese el valor de n: ";
        cin >> n;
    }
    while (n < 2 || n > 20);

    do
    {
        cout << "Ingrese el valor de x: ";
        cin >> x;
    }
    while (x < 2 || x > 10);

    do
    {
        cout << "Ingrese el valor de y: ";
        cin >> y;
    }
    while (y < 2 || y > 5);

    // Calculating the sumatoria
    for (int i = 2; i <= n; i++)
    {
        sumatoria += funcion(i, x, y);
    }

    cout << "La sumatoria es: " << sumatoria << endl;
}
