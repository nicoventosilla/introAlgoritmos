//
// Created by c0d3r on 03/10/2024.
//

#include "problema3.h"
#include <iostream>
#include <cmath>
using namespace std;

long long factorial3(int n)
{
    long long factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    return factorial;
}

void problema3()
{
    int terminos;
    double x;
    long double sumatoria = 0.0;

    // Pedir la cantidad de términos, que debe ser mayor que 0
    do
    {
        cout << "Ingrese la cantidad de terminos (mayor que 0): ";
        cin >> terminos;
    }
    while (terminos <= 0); // Solo seguimos si el número de términos es mayor que 0

    // Pedir el valor de x, que debe estar entre 2 y 4
    do
    {
        cout << "Ingrese el valor de x (entre 2 y 4): ";
        cin >> x;
    }
    while (x < 2 || x > 4); // Validamos que x esté en el rango correcto

    for (int i = 1; i <= terminos; i++)
    {
        double numerador = i * pow(x, i) - 10 * i;
        double denominador = factorial3(i) + x;

        if (i % 2 == 0)
        {
            sumatoria -= numerador / denominador;
        }
        else
        {
            sumatoria += numerador / denominador;
        }
    }

    cout << "La sumatoria es: " << sumatoria << endl;
}
