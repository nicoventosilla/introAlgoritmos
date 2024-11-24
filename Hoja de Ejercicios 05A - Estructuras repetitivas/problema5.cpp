//
// Created by c0d3r on 07/10/2024.
//

#include "problema5.h"
#include <iostream>
#include <cmath>
using namespace std;

int leer_n5()
{
    int n;

    do
    {
        cout << "Cantidad de terminos: ";
        cin >> n;

        if (n < 1 || n > 21)
        {
            cout << "ERROR:debe ingresar una valor positivo menor que 21" << endl;
        }
    }
    while (n > 21 || n < 1);
    return n;
}

int leer_a5()
{
    int a;

    do
    {
        cout << "Valor de a: ";
        cin >> a;

        if (a < 1 || a > 4)
        {
            cout << "ERROR: debe ingresar un valor entre 1 y 4" << endl;
        }
    }
    while (a > 4 || a < 1);
    return a;
}

long long factorial5(int n)
{
    long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

long double calcular_sumatoria5(int n, int a)
{
    long double sumatoria = 0.0;

    cout << "Los terminos son: " << endl;

    for (int i = 1; i <= n; i++)
    {
        double numerador = a * factorial5(a + i);
        double denominador = i * (i + 1);
        int termino = numerador / denominador;

        if (i % 2 == 0)
        {
            cout << "-" << termino << " ";
            sumatoria -= termino;
        }
        else
        {
            cout << termino << " ";
            sumatoria += termino;
        }
    }

    return sumatoria;
}

void imprimir_resultado(double sumatoria)
{
    cout << "La suma de los terminos es: " << sumatoria << endl;
}

void problema5()
{
    int n = leer_n5();
    int a = leer_a5();
    long double sumatoria = calcular_sumatoria5(n, a);
    imprimir_resultado(sumatoria);
}
