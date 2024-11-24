//
// Created by c0d3r on 17/10/2024.
//

#include "problema1.h"
#include <iostream>
#include <algorithm>

using namespace std;

/*
* En el curso de Matemática Discreta, se toman 6 evaluaciones de las cuales se elimina la menor nota
antes de hallar el promedio. Considere que sólo se elimina la menor una sola vez, es decir por
ejemplo si la menor nota estuviese duplicada o triplicada, sólo se eliminará una de ellas.
Se le pide que elabore un programa en C++ que permita leer las calificaciones de un alumno,
almacenarlas en un arreglo y finalmente calcule e imprima el promedio de notas del alumno.
Ejemplo 1:
Si las notas que se ingresan fueran: 13, 20, 14, 12, 16, 17
La nota que no se considera en el promedio seria 12
Ejemplo 2:
Si las notas que se ingresan fueran: 15, 16, 11, 17, 11, 19
La nota que no se considera en el promedio seria el 11 (nota que esta duplicada, sólo se elimina un
sólo 11)
 */

void ingresarNotas(int Notas[], int cantidadNotas) // Ingresar las notas
{
    for (int i = 0; i < cantidadNotas; i++)
    {
        cout << "Ingrese la nota " << i << ": ";
        cin >> Notas[i];
    }
}

void ordenarNotas(int Notas[], int cantidadNotas) // ordena de menor a mayor
{
    sort(Notas, Notas + cantidadNotas); // Ordena el arreglo de menor a mayor
}

double calcularPromedio(int Notas[], int cantidadNotas)
{
    double suma = 0.0;
    for (int i = 0; i < cantidadNotas; i++)
    {
        suma += Notas[i];
    }
    return suma / cantidadNotas;
}

void problema1()
{
    int cantidadNotas = 6; // Cantidad de notas
    double promedio = 0.0;

    int Notas[cantidadNotas]; // Arreglo de 6 elementos

    ingresarNotas(Notas, cantidadNotas);
    ordenarNotas(Notas, cantidadNotas);
    promedio = calcularPromedio(Notas, cantidadNotas);

    cout << "El promedio de las notas es: " << promedio << endl;
}
