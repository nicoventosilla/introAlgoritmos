//
// Created by c0d3r on 02/10/2024.
//
#include "series3.h"
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

void series3()
{
    int n;
    double x;
    long double sumatoria = 0.0;

    // Validar número de términos (n) entre 1 y 20
    do
    {
        cout << "Cuantos terminos?: ";
        cin >> n;
        if (n < 1 || n > 20)
        {
            cout << "El numero de terminos debe estar entre 1 y 20." << endl;
        }
    }
    while (n < 1 || n > 20);

    // Validar valor de x entre -2.5 y 2.5
    do
    {
        cout << "Valor de x: ";
        cin >> x;
        if (x < -2.5 || x > 2.5)
        {
            cout << "El valor de x debe estar entre -2.5 y 2.5." << endl;
        }
    }
    while (x < -2.5 || x > 2.5);

    for (int k = 1; k <= n; k++)
    {
        long double suma = (pow(-1, k) * (pow(x, k) / factorial(k + 2)));
        sumatoria = sumatoria + suma;
    }

    cout << "La sumatoria es: " << sumatoria << endl;
}
