//
// Created by c0d3r on 14/11/2024.
//

#include "problema1.h"
#include <iostream>
#include <ctime> // Para time
#include <cstdlib> // Para srand y rand
#include <algorithm>

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

const int CANT_ESTUDIANTES = 15;

// Generar números de matrícula de los estudiantes
void generarMatriculas(int ArregloMatriculasEstudiantes[])
{
    for (int i = 0; i < CANT_ESTUDIANTES; i++)
    {
        ArregloMatriculasEstudiantes[i] = 5001 + i; // Número de matrícula (empezando en 5001)
    }
}

// Mostrar números de matrícula de los estudiantes
void mostrarArregloMatriculas(int ArregloMatriculasEstudiantes[])
{
    for (int i = 0; i < CANT_ESTUDIANTES; i++)
    {
        cout << ArregloMatriculasEstudiantes[i] << " ";
    }
    cout << endl;
}

// Generar matriz de asistencia de los estudiantes
void generarMatrizAsistencia(int MatrizAsistencia[][2])
{
    for (int i = 0; i < CANT_ESTUDIANTES; i++)
    {
        MatrizAsistencia[i][0] = rand() % 21; // Días asistidos durante el mes de forma aleatoria (máximo 20 días)
        MatrizAsistencia[i][1] = rand() % 11; // Número de tareas entregadas de forma aleatoria (máximo 10)
    }
}

// Mostrar matriz de asistencia de los estudiantes
void mostrarMatrizAsistencia(int MatrizAsistencia[][2], int ArregloMatriculasEstudiantes[])
{
    cout << "Matriz de asistencias:" << endl;

    for (int i = 0; i < CANT_ESTUDIANTES; i++)
    {
        cout << "Estudiante " << ArregloMatriculasEstudiantes[i] << ": ";
        cout << "Dias asistidos: " << MatrizAsistencia[i][0] << ", ";
        cout << "Tareas entregadas: " << MatrizAsistencia[i][1] << endl;
    }
}

// Calcular el número de matrícula del estudiante con el mayor número de tareas entregadas
void calcularEstudianteMayorTareas(int MatrizAsistencia[][2], int ArregloMatriculasEstudiantes[])
{
    int mayorTareas = 0;

    // Encontrar el mayor número de tareas entregadas
    for (int i = 0; i < CANT_ESTUDIANTES; i++)
    {
        if (MatrizAsistencia[i][1] > mayorTareas)
        {
            mayorTareas = MatrizAsistencia[i][1];
        }
    }

    // Mostrar los estudiantes con el mayor número de tareas entregadas
    cout << "Estudiantes con mayor numero de tareas entregadas (" << mayorTareas << ") son: ";
    for (int i = 0; i < CANT_ESTUDIANTES; i++)
    {
        if (MatrizAsistencia[i][1] == mayorTareas)
        {
            cout << ArregloMatriculasEstudiantes[i] << " ";
        }
    }
    cout << endl;
}

// Determinar el porcentaje de asistencia promedio entre todos los estudiantes
void calcularPorcentajeAsistenciaPromedio(int MatrizAsistencia[][2])
{
    int totalDiasAsistidos = 0;

    for (int i = 0; i < CANT_ESTUDIANTES; i++)
    {
        totalDiasAsistidos += MatrizAsistencia[i][0];
    }

    double promedioAsistencia = (totalDiasAsistidos / (CANT_ESTUDIANTES * 20.0)) * 100;

    cout << "Porcentaje de asistencia promedio: " << promedioAsistencia << "%" << endl;
}

// Listar los números de matrícula en orden descendente según la cantidad de días asistidos
void listarMatriculasOrdenDescendente(int MatrizAsistencia[][2], int ArregloMatriculasEstudiantes[])
{
    cout << "Matriculas en orden descendente segun la cantidad de dias asistidos:" << endl;

    for (int i = 0; i < CANT_ESTUDIANTES - 1; i++)
    {
        for (int j = i + 1; j < CANT_ESTUDIANTES; j++)
        {
            if (MatrizAsistencia[i][0] < MatrizAsistencia[j][0])
            {
                swap(MatrizAsistencia[i], MatrizAsistencia[j]);
                swap(ArregloMatriculasEstudiantes[i], ArregloMatriculasEstudiantes[j]);
            }
        }
    }
    mostrarMatrizAsistencia(MatrizAsistencia, ArregloMatriculasEstudiantes);
}

void problema1()
{
    srand(time(0));

    int ArregloMatriculasEstudiantes[CANT_ESTUDIANTES]; // Arreglo de matrículas
    int MatrizAsistencia[CANT_ESTUDIANTES][2]; // Matriz de asistencia

    generarMatriculas(ArregloMatriculasEstudiantes);
    mostrarArregloMatriculas(ArregloMatriculasEstudiantes);

    generarMatrizAsistencia(MatrizAsistencia);
    mostrarMatrizAsistencia(MatrizAsistencia, ArregloMatriculasEstudiantes);

    calcularEstudianteMayorTareas(MatrizAsistencia, ArregloMatriculasEstudiantes);
    calcularPorcentajeAsistenciaPromedio(MatrizAsistencia);
    listarMatriculasOrdenDescendente(MatrizAsistencia, ArregloMatriculasEstudiantes);
}
