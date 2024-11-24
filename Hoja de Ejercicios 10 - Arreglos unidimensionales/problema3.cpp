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

void generarEdadesAleatorias(int Edades[], int cantidadPersonas) // Generar edades al azar
{
    cout << "Generando edades al azar..." << endl;
    for (int i = 0; i < cantidadPersonas; i++)
    {
        Edades[i] = rand() % 100 + 1; // Edades entre 1 y 100
    }
    cout << endl;
}

void mostrarEdades(int Edades[], int cantidadPersonas) // Mostrar edades
{
    cout << "Listado de edades generadas al azar: " << endl;
    for (int i = 0; i < cantidadPersonas; i++)
    {
        cout << "Edad " << i << ": " << Edades[i] << endl;
    }
    cout << endl;
}

void mostrarMenorEdad(int Edades[], int cantidadPersonas) // Mostrar menor edad y su posicion
{
    int menorEdad = Edades[0]; // Suponemos que la primera edad es la menor
    int posicionMenorEdad = 0; // Posicion

    for (int i = 1; i < cantidadPersonas; i++) // Buscamos
    {
        if (Edades[i] < menorEdad) // Si encontramos una edad menor
        {
            menorEdad = Edades[i]; // Actualizamos la menor edad
            posicionMenorEdad = i; // Actualizamos la posicion
        }
    }

    cout << "La menor edad es: " << menorEdad << " y se encuentra en la posicion " << posicionMenorEdad << endl;
}

void mostrarPersonasEntre30y50(int Edades[], int cantidadPersonas) // Personas entre 30 y 50 anios
{
    int cantidadPersonasEntre30y50 = 0; // Contador

    for (int i = 0; i < cantidadPersonas; i++) // Buscamos
    {
        if (Edades[i] >= 30 && Edades[i] <= 50) // Si la edad esta entre 30 y 50
        {
            cantidadPersonasEntre30y50++; // Aumentamos el contador
        }
    }

    cout << "El numero de personas que tienen entre 30 y 50 anios es: " << cantidadPersonasEntre30y50 << endl;
}

void buscarEdad(int Edades[], int cantidadPersonas)
{
    int edadABuscar; // Edad a buscar
    bool encontrado = false; // Bandera

    cout << "Ingrese edad a buscar: ";
    cin >> edadABuscar;

    for (int i = 0; i < cantidadPersonas; i++) // Buscamos
    {
        if (Edades[i] == edadABuscar) // Si encontramos la edad
        {
            encontrado = true; // Actualizamos la bandera
            break;
        }
    }

    if (encontrado) // Si se encontro
    {
        cout << "La edad " << edadABuscar << " se encontro en el arreglo." << endl;
    }
    else // Si no se encontro
    {
        cout << "La edad " << edadABuscar << " no se encontro en el arreglo." << endl;
    }
}

void problema3()
{
    srand(time(0)); // Semilla para numeros aleatorios

    int cantidadPersonas;

    // Validar cantidad de personas
    do
    {
        cout << "Ingrese numero de personas: ";
        cin >> cantidadPersonas;

        if (cantidadPersonas < 1 || cantidadPersonas > 100) cout << "El numero de personas debe ser mayor a 0." << endl;
    }
    while (cantidadPersonas < 1 || cantidadPersonas > 100);

    int Edades[cantidadPersonas]; // Arreglo de edades

    generarEdadesAleatorias(Edades, cantidadPersonas);
    mostrarEdades(Edades, cantidadPersonas);
    mostrarMenorEdad(Edades, cantidadPersonas);
    mostrarPersonasEntre30y50(Edades, cantidadPersonas);
    buscarEdad(Edades, cantidadPersonas);
}
