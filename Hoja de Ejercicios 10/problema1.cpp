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
    for (int i = 0; i < 6 - 1; i++) // se resta 1 para no comparar el ultimo elemento
    {
        for (int j = i + 1; j < 6; j++) // se empieza desde i + 1 para no comparar el mismo elemento
        {
            if (notas[i] > notas[j]) // si la nota en la posicion i es mayor a la nota en la posicion j
            {
                int temp = notas[i]; // se guarda la nota en una variable temporal
                notas[i] = notas[j]; // se intercambian las notas
                notas[j] = temp; // se asigna la nota guardada en la variable temporal
            }
        }
    }
}

double calcularPromedio(int* notas)
{
    double promedio = 0.0; // se inicializa en 0.0 para evitar errores

    for (int i = 1; i < 6; i++) // se empieza desde 1 para no considerar la nota mas baja
    {
        promedio += notas[i]; // se suman las notas
    }

    promedio /= 5; // se divide entre 5 para obtener el promedio

    return promedio;
}

void problema1()
{
    int* notas = new int[6]; // arreglo de 6 elementos
    double promedio = 0.0; // se inicializa en 0.0 para evitar errores

    ingresarNotas(notas);
    ordenarNotas(notas);
    promedio = calcularPromedio(notas);

    cout << "El promedio de las notas es: " << promedio << endl;
}
