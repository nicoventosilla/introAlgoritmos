//
// Created by c0d3r on 07/09/2024.
//

#include "problema4.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void problema4()
{
    string marca, color, capacidad;
    double precio = 0, descuento;

    cout << "Ingrese marca del celular (N: nokia, S: samsung): ";
    cin >> marca;

    cout << "Ingrese color (0: rojo, 1: blanco): ";
    cin >> color;

    cout << "Ingrese capacidad (8: 8GB, 16: 16GB): ";
    cin >> capacidad;

    if (marca == "N" || marca == "n")
    {
        if (color == "0")
        {
            if (capacidad == "8")
            {
                precio = 1800;
            }
            else if (capacidad == "16")
            {
                precio = 2650;
            }
        }
        else if (color == "1")
        {
            if (capacidad == "16")
            {
                precio = 2780;
            }
        }
    }
    else if (marca == "S" || marca == "s")
    {
        if (color == "0")
        {
            if (capacidad == "8")
            {
                precio = 1700;
            }
            else if (capacidad == "16")
            {
                precio = 2500;
            }
        }
        else if (color == "1")
        {
            if (capacidad == "16")
            {
                precio = 2900;
            }
        }
    }

    if (precio >= 2800)
    {
        descuento = precio * 0.06;
        precio = precio - descuento;

        cout << "Precio con descuento: " << precio << endl;
    }
    else
    {
        cout << "Precio sin descuento: " << precio << endl;
    }
}
