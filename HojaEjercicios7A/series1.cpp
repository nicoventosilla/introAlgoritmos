//
// Created by c0d3r on 02/10/2024.
//

#include "series1.h"
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

void series1()
{
    int N;
    double x;
    long double sumatoria = 0.0;

    do
    {
        cout << "Ingrese el valor de x (0 < x <= 1): ";
        cin >> x;

        if (x < 0 || x > 1)
        {
            cout << "El valor de x debe ser un numero (0 < x <= 1)";
        }
    } while (x <= 0 || x > 1);

    do
    {
        cout << "Ingrese el valor de n: ";
        cin >> N;

        if (N < 1 || N > 10)
        {
            cout << "El valor de n debe ser un numero entre 1 y 10";
        }
    } while (N < 1 || N > 10);


    for (int n = 0; n < N; n++)
    {
        long double numerador = factorial(2 * n);
        long double denominador = pow(4, n) * pow(factorial(n), 2) * (2 * n + 1);
        long double multiplicando = pow(x, 2 * n + 1);

        long double suma = (numerador / denominador) * multiplicando;

        sumatoria = sumatoria + suma;
    }

    cout << "El valor aproximado de arcsen(" << x << ") es: " << sumatoria << endl;

}
