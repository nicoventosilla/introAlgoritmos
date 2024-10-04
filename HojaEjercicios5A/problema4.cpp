//
// Created by c0d3r on 03/10/2024.
//

#include "problema4.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int leer_a()
{
    int a;
    do
    {
        cout << "Ingrese el valor del primer término (entre 1 y 3): ";
        cin >> a;
        if (a < 1 || a > 3)
        {
            cout << "ERROR: debe ingresar un valor entre 1 y 3" << endl;
        }
    }
    while (a < 1 || a > 3);
    return a;
}

int leer_n()
{
    int n;
    do
    {
        cout << "Ingrese la cantidad de terminos (entre 7 y 14): ";
        cin >> n;
        if (n < 7 || n > 14)
        {
            cout << "ERROR: debe ingresar un valor entre 7 y 14" << endl;
        }
    }
    while (n < 7 || n > 14);
    return n;
}


long long factorial4(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

double calcular_sumatoria(int a, int n)
{
    long double sumatoria = 0.0;
    double termino = static_cast<double>(a);

    cout << "Los terminos son: " << endl;

    for (int i = 1; i <= n; i++)
    {
        termino = (2.0 * (termino + 3)) / ((3 * i + 10) * factorial4(i));
        cout << fixed << setprecision(4) << termino << " ";
        sumatoria += termino;
    }

    return sumatoria;
}

void imprimirSumatoria(long double sumatoria)
{
    cout << endl<< "La sumatoria es: " << fixed << setprecision(4) << sumatoria << endl;
}

void problema4()
{
    int a = leer_a();
    int n = leer_n();
    long double sumatoria = calcular_sumatoria(a, n);
    imprimirSumatoria(sumatoria);
}
