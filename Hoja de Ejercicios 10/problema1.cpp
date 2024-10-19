//
// Created by c0d3r on 17/10/2024.
//

#include "problema1.h"
#include <iostream>
using namespace std;

void ingresarNotas(int* notas)
{
    for (int i = 0; i < 6; i++)
    {
        cout << "Ingrese la nota " << i + 1 << ": ";
        cin >> notas[i];
    }
}

void ordenarNotas(int* notas) // ordena de menor a mayor
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if (notas[i] > notas[j])
            {
                int temp = notas[i];
                notas[i] = notas[j];
                notas[j] = temp;
            }
        }
    }
}

double calcularPromedio(int* notas)
{
    double promedio = 0.0;
    for (int i = 1; i < 6; i++)
    {
        promedio += notas[i];
    }
    promedio /= 5;
    return promedio;
}

void problema1()
{
    int* notas = new int[6];
    double promedio = 0.0;

    ingresarNotas(notas);
    ordenarNotas(notas);
    promedio = calcularPromedio(notas);

    cout << "El promedio de las notas es: " << promedio << endl;
}
