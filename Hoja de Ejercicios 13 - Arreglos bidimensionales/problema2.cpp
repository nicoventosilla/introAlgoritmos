//
// Created by c0d3r on 23/11/2024.
//

#include "problema2.h"
#include <iostream>
#include <ctime> // Libreria para el uso de time
#include <cstdlib> // Libreria para el uso de rand

using namespace std;

/**
*2. La Facultad de Agrónomos de una universidad extranjera, está realizando estudios sobre la vida de
los topos en las parcelas de cultivos al aire libre. Es por ello que ha logrado determinar en un 100%
de casos exitosos, que la guarida de los mismos se encuentra bajo un patrón cultivo dado.
Para ello, se tiene tres tipos de cultivos: 1 (Zanahoria), 2(Berenjena), 3(Nabos).
El patrón encontrado es el siguiente:

  3
2 GT 2
  1

Donde GT es la guarida del topo.

Para ello se le pide implementar en C++, un programa que permita:
Generar una matriz de 10 x 15, donde contenga de forma aleatoria los tres tipos de cultivos.
Determinar que cultivo tiene la mayor y menor frecuencia.
Determinar los puntos (fila, columna), donde pueda existir una guarida de topo.
*/

int generarAleatorios(int min, int max) // Generar un numero aleatorio entre min y max
{
    return rand() % (max - min + 1) + min; // Formula para generar un numero aleatorio entre min y max
}

void generarMatriz(int Matriz[10][15])
{
    for (int i = 0; i < 10; i++) // Recorrer filas
    {
        for (int j = 0; j < 15; j++) // Recorrer columnas
        {
            Matriz[i][j] = generarAleatorios(1, 3); // Cultivo aleatorio entre 1 y 3
        }
    }
}

void mostrarMatriz(int Matriz[10][15])
{
    for (int i = 0; i < 10; i++) // Recorrer filas
    {
        for (int j = 0; j < 15; j++) // Recorrer columnas
        {
            cout << Matriz[i][j] << " "; // Mostrar el cultivo
        }
        cout << endl;
    }
}

void cultivoMayorYMenorFrecuencia(int Matriz[10][15])
{
    int frecuenciaZanahoria = 0;
    int frecuenciaBerenjena = 0;
    int frecuenciaNabos = 0;

    for (int i = 0; i < 10; i++) // Recorrer filas
    {
        for (int j = 0; j < 15; j++) // Recorrer columnas
        {
            if (Matriz[i][j] == 1) frecuenciaZanahoria++; // Si es zanahoria aumentar en 1
            else if (Matriz[i][j] == 2) frecuenciaBerenjena++; // Si es berenjena aumentar en 1
            else if (Matriz[i][j] == 3) frecuenciaNabos++; // Si son nabos aumentar en 1
        }
    }

    cout << "Frecuencia de Zanahoria: " << frecuenciaZanahoria << endl;
    cout << "Frecuencia de Berenjena: " << frecuenciaBerenjena << endl;
    cout << "Frecuencia de Nabos: " << frecuenciaNabos << endl;

    // Determinar cultivo con mayor frecuencia
    cout << "Cultivo con mayor frecuencia: ";
    if (frecuenciaZanahoria >= frecuenciaBerenjena && frecuenciaZanahoria >= frecuenciaNabos)
    // Si la zanahoria es la mayor
    {
        cout << "Zanahoria" << endl;
    }
    else if (frecuenciaBerenjena >= frecuenciaZanahoria && frecuenciaBerenjena >= frecuenciaNabos)
    // Si la berenjena es la mayor
    {
        cout << "Berenjena" << endl;
    }
    else // Si los nabos son los mayores
    {
        cout << "Nabos" << endl;
    }

    // Determinar cultivo con menor frecuencia
    cout << "Cultivo con menor frecuencia: ";
    if (frecuenciaZanahoria <= frecuenciaBerenjena && frecuenciaZanahoria <= frecuenciaNabos)
    // Si la zanahoria es la menor
    {
        cout << "Zanahoria" << endl;
    }
    else if (frecuenciaBerenjena <= frecuenciaZanahoria && frecuenciaBerenjena <= frecuenciaNabos)
    // Si la berenjena es la menor
    {
        cout << "Berenjena" << endl;
    }
    else // Si los nabos son los menores
    {
        cout << "Nabos" << endl;
    }
}

void mostrarGuaridaTopo(int Matriz[10][15])
{
    cout << "Posibles guaridas de topo: " << endl;
    for (int i = 1; i < 9; i++) // Recorrer filas (No se puede buscar en la primera y ultima fila)
    {
        for (int j = 1; j < 14; j++) // Recorrer columnas (No se puede buscar en la primera y ultima columna)
        {
            if (Matriz[i - 1][j] == 3 && Matriz[i + 1][j] == 1 && Matriz[i][j - 1] == 2 && Matriz[i][j + 1] == 2)
            // Si cumple el patron de la guarida de topo
            {
                cout << "Fila: " << i + 1 << ", Columna: " << j + 1 << endl;
                // Mostrar la posible guarida de topo (Sumar 1 para mostrar la fila y columna correcta)
            }
        }
    }
}

void problema2() // int main()
{
    srand(time(0)); // Inicializar la semilla para los numeros aleatorios

    // Generar matriz de 10 x 15
    int Matriz[10][15];

    // Generar matriz de forma aleatoria
    generarMatriz(Matriz);

    // Mostrar matriz
    mostrarMatriz(Matriz);

    // Determinar cultivo con mayor frecuencia
    cultivoMayorYMenorFrecuencia(Matriz);

    // Determinar puntos donde pueda existir una guarida de topo
    mostrarGuaridaTopo(Matriz);
}
