//
// Created by c0d3r on 02/10/2024.
//

#include "series4.h"
#include <iostream>
#include <cmath>
using namespace std;

void series4()
{
    int n;
    double a;
    long double sumatoria = 0.0;

    do
    {
        cout << "Ingrese el valor de n (0<n<21): ";
        cin >> n;

        if (n <= 0 || n >= 21)
        {
            cout << "El valor de n debe ser un numero (0 < n < 21)" << endl;
        }
    }
    while (n <= 0 || n >= 21);

    // a debe ser un valor real entre 0.5 y 2
    do
    {
        cout << "Ingrese el valor de a (0.5 < a < 2): ";
        cin >> a;

        if (a <= 0.5 || a >= 2)
        {
            cout << "El valor de a debe ser un numero real (0.5 < a < 2)" << endl;
        }
    }
    while (a <= 0.5 || a >= 2);

    for (int k = 1; k <= n; k++)
    {
        double multiplicando = pow(-1, k + 1);
        double numerador = ((2 * n) - 1) * pow(a, pow(2, n - 1));
        double denominador = 2 * n;
        long double suma = multiplicando * (numerador / denominador);
        sumatoria = sumatoria + suma;
    }

    cout << "El resultado de la serie sera: " << sumatoria << endl;
}
