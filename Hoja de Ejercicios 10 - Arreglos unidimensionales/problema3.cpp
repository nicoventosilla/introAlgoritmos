//
// Created by c0d3r on 01/11/2024.
//

#include "problema3.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
* Se desea hacer un análisis de las edades de N personas elegidas al azar. Para ello se desea realizar
un programa en C++ que reciba como dato el número de personas N y genere las edades para esta
cantidad de personas en un Arreglo y luego muestre en pantalla:
 Un listado de los N edades generados al azar (N tendrá un valor máximo de 100)
 La menor edad y su posición en el Arreglo.
 El número de personas que tienen entre 30 y 50 años.
También se desea que el programa solicite una edad a buscar en el arreglo y muestre si se encontró
o no en el arreglo.
 */

void generarEdadesAleatorias(int Edades[], int cantidadPersonas)
{
    cout << "Generando edades al azar..." << endl;
    for (int i = 0; i < cantidadPersonas; i++)
    {
        Edades[i] = rand() % 100 + 1;
    }
    cout << endl;
}

void mostrarEdades(int Edades[], int cantidadPersonas)
{
    cout << "Listado de edades generadas al azar: " << endl;
    for (int i = 0; i < cantidadPersonas; i++)
    {
        cout << "Edad " << i << ": " << Edades[i] << endl;
    }
    cout << endl;
}

void mostrarMenorEdad(int Edades[], int cantidadPersonas)
{
    int menorEdad = Edades[0];
    int posicionMenorEdad = 0;

    for (int i = 1; i < cantidadPersonas; i++)
    {
        if (Edades[i] < menorEdad)
        {
            menorEdad = Edades[i];
            posicionMenorEdad = i;
        }
    }

    cout << "La menor edad es: " << menorEdad << " y se encuentra en la posicion " << posicionMenorEdad << endl;
}

void mostrarPersonasEntre30y50(int Edades[], int cantidadPersonas)
{
    int cantidadPersonasEntre30y50 = 0;

    for (int i = 0; i < cantidadPersonas; i++)
    {
        if (Edades[i] >= 30 && Edades[i] <= 50)
        {
            cantidadPersonasEntre30y50++;
        }
    }

    cout << "El numero de personas que tienen entre 30 y 50 anios es: " << cantidadPersonasEntre30y50 << endl;
}

void buscarEdad(int Edades[], int cantidadPersonas)
{
    int edadABuscar;
    bool encontrado = false;

    cout << "Ingrese edad a buscar: ";
    cin >> edadABuscar;

    for (int i = 0; i < cantidadPersonas; i++)
    {
        if (Edades[i] == edadABuscar)
        {
            encontrado = true;
            break;
        }
    }

    if (encontrado)
    {
        cout << "La edad " << edadABuscar << " se encontro en el arreglo." << endl;
    }
    else
    {
        cout << "La edad " << edadABuscar << " no se encontro en el arreglo." << endl;
    }
}

void problema3()
{
    srand(time(0)); // Semilla para numeros aleatorios

    int cantidadPersonas;

    do
    {
        cout << "Ingrese numero de personas: ";
        cin >> cantidadPersonas;

        if (cantidadPersonas < 1 || cantidadPersonas > 100) cout << "El numero de personas debe ser mayor a 0." << endl;
    }
    while (cantidadPersonas < 1 || cantidadPersonas > 100);

    int Edades[cantidadPersonas];

    generarEdadesAleatorias(Edades, cantidadPersonas);
    mostrarEdades(Edades, cantidadPersonas);
    mostrarMenorEdad(Edades, cantidadPersonas);
    mostrarPersonasEntre30y50(Edades, cantidadPersonas);
    buscarEdad(Edades, cantidadPersonas);
}
