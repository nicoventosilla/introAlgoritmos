//
// Created by c0d3r on 01/11/2024.
//

#include "problema3.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void menorEdad(int* Personas, int cantidadPersonas) // Hallar la menor edad y su posicion
{
    int menor = Personas[0];
    int posicion = 0;

    for (int i = 1; i < cantidadPersonas; i++)
    {
        if (Personas[i] < menor)
        {
            menor = Personas[i];
            posicion = i;
        }
    }

    cout << "La menor edad es " << menor << " y se encuentra en la posicion " << posicion << endl;
}

void problema3()
{
    srand(time(0)); // Semilla para numeros aleatorios

    int cantidadPersonas;

    do
    {
        cout << "Ingrese numero de personas: ";
        cin >> cantidadPersonas;

        if (cantidadPersonas < 1) cout << "El numero de personas debe ser mayor a 0." << endl;
    }
    while (cantidadPersonas < 1);

    int* Personas = new int[cantidadPersonas];

    for (int i = 0; i < cantidadPersonas; i++) // Llenar el arreglo con numeros aleatorios
    {
        Personas[i] = rand() % 100 + 1; // Numero aleatorio entre 1 y 100
    }

    for (int i = 0; i < cantidadPersonas; i++) // Mostrar el arreglo
    {
        cout << Personas[i] << " ";
    }

    cout << endl;

    // Hallar la menor edad y su posicion
    menorEdad(Personas, cantidadPersonas);

    // Cantidad personas entre 30 y 50
    int cantidadPersonas30y50 = 0;

    for (int i = 0; i < cantidadPersonas; i++)
    {
        if (Personas[i] >= 30 && Personas[i] <= 50)
        {
            cantidadPersonas30y50++;
        }
    }

    cout << "Cantidad de personas cuya edad esta entre 30 y 50: " << cantidadPersonas30y50 << endl;

    // Solicitar una edad y mostrar si se encuentra en el arreglo
    int edad;

    cout << "Ingrese una edad: ";
    cin >> edad;

    bool encontrado = false;

    for (int i = 0; i < cantidadPersonas; i++)
    {
        if (Personas[i] == edad)
        {
            encontrado = true;
            break;
        }
    }

    if (encontrado) // Si se encuentra
    {
        cout << "La edad " << edad << " si se encuentra en el arreglo." << endl;
    }
    else // Si no se encuentra
    {
        cout << "La edad " << edad << " no se encuentra en el arreglo." << endl;
    }
}
