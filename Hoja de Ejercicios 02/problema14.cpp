//
// Created by c0d3r on 11/09/2024.
//

#include "problema14.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void problema14()
{
    char modelo, color;
    int edad;
    double precio = 0, incremento;

    cout << "Ingrese el modelo del auto: ";
    cin >> modelo;

    cout << "Ingrese color (B: blanco; M: metalizado; O: otros): ";
    cin >> color;

    cout << "Ingrese edad del conductor: ";
    cin >> edad;

    if (modelo == 'A' || modelo == 'a')
    {
        if (color == 'B' || color == 'b')
        {
            precio = 240.50;
        }
        else if (color == 'M' || color == 'm')
        {
            precio = 330.00;
        }
        else if (color == 'O' || color == 'o')
        {
            precio = 270.50;
        }
    }
    else if (modelo == 'B' || modelo == 'b')
    {
        if (color == 'B' || color == 'b')
        {
            precio = 300.00;
        }
        else if (color == 'M' || color == 'm')
        {
            precio = 360.50;
        }
        else if (color == 'O' || color == 'o')
        {
            precio = 330.00;
        }
    }

    if (edad < 31)
    {
        precio += precio * 0.25;
    }
    else if (edad >= 31 && edad <= 65)
    {
        precio += 0;
    }
    else if (edad > 65)
    {
        precio += precio * 0.10;
    }

    cout << "El precio del seguro es: " << precio << endl;
}
