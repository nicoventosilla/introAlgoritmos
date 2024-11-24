//
// Created by c0d3r on 22/11/2024.
//

#include "problema5.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
*5. Definir una estructura para puntos en el espacio. Defina funciones que calculan las distancias entre puntos
con argumentos de estructuras.

// estructura para definir un punto en el espacio

struct puntesp
{
double x, y, z; // coordenadas de los puntos
}

// declaracion de la funcion que calcula la distancia entre dos puntos
double distancia(puntesp p1, puntesp p2);
 */

// Estructura para almacenar los datos de un punto en el espacio
struct Puntesp
{
    double x, y, z;
};

double distancia(Puntesp p1, Puntesp p2) // Calcular la distancia entre dos puntos
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2)); // Formula de distancia entre dos puntos
}

void problema5()
{
    Puntesp p1, p2;
    cout << "Ingrese las coordenadas del primer punto: " << endl;
    cout << "x: ";
    cin >> p1.x;
    cout << "y: ";
    cin >> p1.y;
    cout << "z: ";
    cin >> p1.z;

    cout << "Ingrese las coordenadas del segundo punto: " << endl;
    cout << "x: ";
    cin >> p2.x;
    cout << "y: ";
    cin >> p2.y;
    cout << "z: ";
    cin >> p2.z;

    cout << "La distancia entre los dos puntos es: " << distancia(p1, p2) << endl;
}
