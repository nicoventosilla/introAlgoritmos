//
// Created by c0d3r on 18/09/2024.
//

#include "problema9.h"
#include <iostream>
using namespace std;

double calcularPrecio(char modelo, char color, char juego)
{
    double precio = 0.0;

    if (modelo == 'T' || modelo == 't')
    {
        if (color == 'B' || color == 'b') precio = 6.0;
        else if (color == 'A' || color == 'a') precio = 7.0;
        else if (color == 'N' || color == 'n') precio = 8.0;
    }
    else if (modelo == 'K' || modelo == 'k')
    {
        if (color == 'B' || color == 'b') precio = 10.0;
        else if (color == 'A' || color == 'a') precio = 12.0;
        else if (color == 'N' || color == 'n') precio = 15.0;
    }

    if (juego == 'G' || juego == 'g') precio += (precio * 0.25);
    else if (juego == 'C' || juego == 'c') precio += (precio * 0.0);
    else if (juego == 'A' || juego == 'a') precio += (precio * 0.10);

    return precio;
}

void problema9()
{
    char modelo, color, juego;
    double precio;

    cout << "Ingrese modelo de mascarilla (K: KN95, T: tradicional): ";
    cin >> modelo;

    cout << "Ingrese color (B: blanco, A: azul, N: Negro): ";
    cin >> color;

    cout << "Juego (G: gel de mano, C: curitas, A: alcohol: ";
    cin >> juego;

    precio = calcularPrecio(modelo, color, juego);

    cout << "Precio del combo: $" << precio;
}
