//
// Created by c0d3r on 14/11/2024.
//

#include "problema1.h"
#include <iostream>
#include <cstdlib>

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

void GenerayListaParalelos(char* Vgripe, char* Vtos, int* Vpesos, int cantidad_alumnos)
{
    for (int i = 0; i < cantidad_alumnos; i++)
    {
        // Tuviste gripe en los ultimos 3 meses?
        Vgripe[i] = (rand() % 2 == 0) ? 'S' : 'N';

        // Tuviste tos en los ultimos 3 meses?
        Vtos[i] = (rand() % 2 == 0) ? 'S' : 'N';

        // Cuanto pesas?
        Vpesos[i] = (rand() % (60 - 30 + 1) + 30);

        cout << "Alumno " << i + 1 << " Gripe(" << Vgripe[i] << "), Tos(" << Vtos[i] << "), Peso(" << Vpesos[i] << ")"
            << endl;
    }
}

double Porcentaje_gripe_tos(char* Vgripe, char* Vtos, int cantidad_alumnos)
{
    double total = 0.0;
    double cantidad_alumnos_2 = cantidad_alumnos * 1.0;

    for (int i = 0; i < cantidad_alumnos; i++)
    {
        if (Vgripe[i] == 'S' && Vtos[i] == 'S')
        {
            total++;
        }
    }

    return (total / cantidad_alumnos_2) * 100;
}

double Promedio_pesos(char* Vgripe, char* Vtos, int* Vpesos, int cantidad_alumnos)
{
    double pesos_total = 0.0;
    double cantidad_con_enfermedad = 0.0;

    for (int i = 0; i < cantidad_alumnos; i++)
    {
        if (Vgripe[i] == 'S' || Vtos[i] == 'S')
        {
            pesos_total += Vpesos[i];
            cantidad_con_enfermedad++;
        }
    }

    return (cantidad_con_enfermedad > 0) ? pesos_total / cantidad_con_enfermedad : 0.0;
}

void Listado_ordenado(char* Vgripe, char* Vtos, int* Vpesos, int cantidad_alumnos)
{
    for (int j = 0; j < cantidad_alumnos - 1; j++)
    {
        for (int i = j + 1; i < cantidad_alumnos; i++)
        {
            if (Vpesos[j] < Vpesos[i])
            {
                swap(Vpesos[j], Vpesos[i]);
            }
        }
    }

    for (int i = 0; i < cantidad_alumnos; i++)
    {
        cout << "Alumno " << i + 1 << " Gripe(" << Vgripe[i] << "), Tos(" << Vtos[i] << "), Peso(" << Vpesos[i] << ")"
            << endl;
    }
}

void problema1()
{
    int cantidad_alumnos;

    do
    {
        cout << "Ingrese la cantidad de alumnos (maximo " << MAX_ALUMNOS << "): ";
        cin >> cantidad_alumnos;
    }
    while (cantidad_alumnos < 1 || cantidad_alumnos > MAX_ALUMNOS);

    char* Vgripe = new char[cantidad_alumnos];
    char* Vtos = new char[cantidad_alumnos];
    int* Vpesos = new int[cantidad_alumnos];

    // Funcion genera datos aleatorios
    GenerayListaParalelos(Vgripe, Vtos, Vpesos, cantidad_alumnos);

    cout << "\nPorcentaje de alumnos que tuvieron gripe y tos simultaneamente: " << Porcentaje_gripe_tos(
        Vgripe, Vtos, cantidad_alumnos) << "%" << endl;
    cout << "Promedio de pesos de alumnos que han tenido alguna enfermedad: " << Promedio_pesos(
        Vgripe, Vtos, Vpesos, cantidad_alumnos) << "kg." << endl;

    Listado_ordenado(Vgripe, Vtos, Vpesos, cantidad_alumnos);

    delete[] Vgripe;
    delete[] Vtos;
    delete[] Vpesos;
}
