//
// Created by c0d3r on 14/11/2024.
//

#include "problema1.h"
#include <iostream>

using namespace std;

/*
* Control de Asistencia en una Escuela de Verano
* En la escuela de verano "Sol y Mar" se lleva un registro de asistencia de 15 estudiantes en el curso de Matemáticas.
* De cada estudiante se necesita conocer:
* - Número de matrícula (empezando en 5001).
* - Días asistidos durante el mes (máximo 20 días).
* - Número de tareas entregadas (máximo 10).
* Se solicita implementar un programa en C++ que:
* - Genere y muestre un vector con los números de matrícula de los estudiantes.
* - Genere una matriz 15 x 2 con los días asistidos y el número de tareas entregadas para cada estudiante, de forma
aleatoria.
* - Calcule el número de matrícula del estudiante con el mayor número de tareas entregadas.
* - Determine el porcentaje de asistencia promedio entre todos los estudiantes.
* - Liste los números de matrícula en orden descendente según la cantidad de días asistidos.
*/

void problema1()
{
    int estudiantes = 15;
    int dias = 20;
    int tareas = 10;

    // Generar vector con los números de matrícula de los estudiantes
    int* matriculas = new int[estudiantes];
    for (int i = 0; i < estudiantes; ++i)
    {
        matriculas[i] = 5001 + i;
    }

    // Generar matriz 15 x 2 con los días asistidos y el número de tareas entregadas
    int** asistencias = new int*[estudiantes];
    for (int i = 0; i < estudiantes; ++i)
    {
        asistencias[i] = new int[2];
        asistencias[i][0] = rand() % dias + 1;
        asistencias[i][1] = rand() % tareas + 1;
    }

    // Mostrar vector con los números de matrícula de los estudiantes
    cout << "Numeros de matricula de los estudiantes:" << endl;
    for (int i = 0; i < estudiantes; ++i)
    {
        cout << matriculas[i] << " ";
    }
    cout << endl;

    // Mostrar matriz 15 x 2 con los días asistidos y el número de tareas entregadas
    cout << "Dias asistidos y tareas entregadas de los estudiantes:" << endl;
    for (int i = 0; i < estudiantes; ++i)
    {
        cout << "Estudiante " << matriculas[i] << ": ";
        cout << "Dias asistidos: " << asistencias[i][0] << ", ";
        cout << "Tareas entregadas: " << asistencias[i][1] << endl;
    }

    // Calcular el número de matrícula del estudiante con el mayor número de tareas entregadas
    int maxTareas = asistencias[0][1];
    int matriculaMaxTareas = matriculas[0];
    for (int i = 1; i < estudiantes; ++i)
    {
        if (asistencias[i][1] > maxTareas)
        {
            maxTareas = asistencias[i][1];
            matriculaMaxTareas = matriculas[i];
        }
    }

    // Mostrar el número de matrícula del estudiante con el mayor número de tareas entregadas
    cout << "El estudiante con el mayor numero de tareas entregadas es: " << matriculaMaxTareas << endl;

    // Calcular el porcentaje de asistencia promedio entre todos los estudiantes
    int totalDias = 0;
    for (int i = 0; i < estudiantes; ++i)
    {
        totalDias += asistencias[i][0];
    }
    float promedioAsistencia = (float)totalDias / estudiantes;

    // Mostrar el porcentaje de asistencia promedio entre todos los estudiantes
    cout << "El porcentaje de asistencia promedio entre todos los estudiantes es: " << promedioAsistencia << "%" <<
        endl;

    // Listar los números de matrícula en orden descendente según la cantidad de días asistidos
    for (int i = 0; i < estudiantes - 1; ++i)
    {
        for (int j = i + 1; j < estudiantes; ++j)
        {
            if (asistencias[i][0] < asistencias[j][0])
            {
                swap(asistencias[i], asistencias[j]);
                swap(matriculas[i], matriculas[j]);
            }
        }
    }

    // Mostrar los números de matrícula en orden descendente según la cantidad de días asistidos
    cout << "Numeros de matricula en orden descendente segun la cantidad de dias asistidos:" << endl;
    for (int i = 0; i < estudiantes; ++i)
    {
        cout << matriculas[i] << " ";
    }

    // Liberar memoria
    delete[] matriculas;
    for (int i = 0; i < estudiantes; ++i)
    {
        delete[] asistencias[i];
    }
    delete[] asistencias;
}
