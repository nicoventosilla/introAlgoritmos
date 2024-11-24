//
// Created by c0d3r on 14/11/2024.
//

#include "problema1.h"
#include <iostream>
#include <cstdlib>
#include <algorithm> // sort, reverse

using namespace std;

/*
En el colegio “DeVacas”, se está llevando a cabo un control de salud el día de hoy a cada uno de los N (máximo
20) alumnos del salón 5to B de primaria.
El control consistió en preguntarle a cada alumno lo siguiente:
a) Tuviste gripe en los últimos 3 meses? (Respuestas posibles ‘S’ o ‘N’ )
b) Tuviste tos en los últimos 3 meses? (Respuestas posibles ‘S’ o ‘N’ )
c) Cuánto pesas? (entre 30 y 60 )
El Ministerio de Salud en su campaña para colegios “Prevenir” le ha solicitado a los
alumnos del curso de Programación 1 de la UPC que elaboren un programa en Lenguaje C++
que procese la información de los alumnos para lo cual se le pide:
- Implementar la función GenerayLista_Paralelos, que permita generar de forma aleatoria e
imprimir los datos de los N alumnos que se almacenan en los vectores paralelos Vgripe, Vtos y
Vpesos.
- Implementar la función Porcentaje_gripe_tos, que determine el porcentaje de alumnos que
tuvieron gripe y tos simultáneamente sobre el total de alumnos.
- Implementar la función Promedio_pesos, que determine el promedio del peso de los alumnos
que han tenido alguna enfermedad.
- Implementar la función Listado_ordenado, que imprima el listado de los alumnos ordenado
descendentemente por el peso.
- Implementar la función principal main que solicite el ingreso del valor de N y luego realice el
llamado correcto de las funciones anteriores.
*/

const int MAX_ALUMNOS = 20;

void GenerayListaParalelos(char Vgripe[], char Vtos[], int Vpesos[], int cantidad_alumnos)
{
    cout << "\nListado de alumnos:" << endl;
    for (int i = 0; i < cantidad_alumnos; i++)
    {
        Vgripe[i] = (rand() % 2 == 0) ? 'S' : 'N'; // Generar aleatoriamente 'S' o 'N'
        Vtos[i] = (rand() % 2 == 0) ? 'S' : 'N'; // Generar aleatoriamente 'S' o 'N'
        Vpesos[i] = (rand() % (60 - 30 + 1) + 30); // Generar aleatoriamente un peso entre 30 y 60

        cout << "Alumno " << i + 1 << endl;
        cout << "Gripe: " << Vgripe[i] << endl;
        cout << "Tos: " << Vtos[i] << endl;
        cout << "Peso: " << Vpesos[i] << "kg" << endl;
        cout << endl;
    }
}

double Porcentaje_gripe_tos(char Vgripe[], char Vtos[], int cantidad_alumnos)
{
    double total = 0.0;

    for (int i = 0; i < cantidad_alumnos; i++) // Recorrer los alumnos
    {
        if (Vgripe[i] == 'S' && Vtos[i] == 'S') // Si tuvo gripe y tos
        {
            total++; // Incrementar el total
        }
    }

    return (total / cantidad_alumnos) * 100; // Retornar el porcentaje
}

double Promedio_pesos(char Vgripe[], char Vtos[], int Vpesos[], int cantidad_alumnos)
{
    double pesos_total = 0.0; // Suma de los pesos de los alumnos que tuvieron alguna enfermedad
    int cantidad_con_enfermedad = 0; // Cantidad de alumnos que tuvieron alguna enfermedad

    for (int i = 0; i < cantidad_alumnos; i++) // Recorrer los alumnos
    {
        if (Vgripe[i] == 'S' || Vtos[i] == 'S') // Si tuvo gripe o tos
        {
            pesos_total += Vpesos[i]; // Sumar el peso
            cantidad_con_enfermedad++; // Incrementar la cantidad
        }
    }

    if (cantidad_con_enfermedad > 0) // Si hay alumnos con enfermedad
    {
        return pesos_total / cantidad_con_enfermedad; // Retornar el promedio
    }
    else // Si no hay alumnos con enfermedad
    {
        return 0.0; // Retornar 0.0 si no hay alumnos con enfermedad
    }
}

void Listado_ordenado(char Vgripe[], char Vtos[], int Vpesos[], int cantidad_alumnos) // Ordenar descendentemente por el peso
{
    // Arreglo de indices para mantener la posición original de los alumnos
    int indices[cantidad_alumnos];
    for (int i = 0; i < cantidad_alumnos; i++)
    {
        indices[i] = i + 1; // Inicializar los indices con los números de los alumnos
    }

    for (int i = 0; i < cantidad_alumnos - 1; i++) // Recorrer los alumnos (excepto el último)
    {
        for (int j = i + 1; j < cantidad_alumnos; j++) // Recorrer los alumnos (desde el siguiente al actual)
        {
            if (Vpesos[i] < Vpesos[j]) // Si el peso del alumno i es menor que el peso del alumno j
            {
                swap(Vpesos[i], Vpesos[j]); // Intercambiar los pesos
                swap(Vgripe[i], Vgripe[j]); // Intercambiar las gripes
                swap(Vtos[i], Vtos[j]); // Intercambiar las toses
                swap(indices[i], indices[j]); // Intercambiar los indices
            }
        }
    }

    cout << "\nListado de alumnos ordenado descendentemente por el peso:" << endl;
    for (int i = 0; i < cantidad_alumnos; i++)
    {
        cout << "Alumno " << indices[i] << endl;
        cout << "Gripe: " << Vgripe[i] << endl;
        cout << "Tos: " << Vtos[i] << endl;
        cout << "Peso: " << Vpesos[i] << "kg" << endl;
        cout << endl;
    }
}

void problema1() // int main()
{
    srand(time(0));

    int cantidad_alumnos;

    do
    {
        cout << "Ingrese la cantidad de alumnos (maximo " << MAX_ALUMNOS << "): ";
        cin >> cantidad_alumnos;
    }
    while (cantidad_alumnos < 1 || cantidad_alumnos > MAX_ALUMNOS);

    char Vgripe[MAX_ALUMNOS];
    char Vtos[MAX_ALUMNOS];
    int Vpesos[MAX_ALUMNOS];

    GenerayListaParalelos(Vgripe, Vtos, Vpesos, cantidad_alumnos);

    cout << "Porcentaje de alumnos que tuvieron gripe y tos simultaneamente: " << Porcentaje_gripe_tos(
        Vgripe, Vtos, cantidad_alumnos) << "%" << endl;
    cout << "Promedio de pesos de alumnos que han tenido alguna enfermedad: " << Promedio_pesos(
        Vgripe, Vtos, Vpesos, cantidad_alumnos) << "kg." << endl;
    Listado_ordenado(Vgripe, Vtos, Vpesos, cantidad_alumnos);
}
