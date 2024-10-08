//
// Created by c0d3r on 11/09/2024.
//

#include "problema15.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void problema15()
{
    char zona, socio;
    double precio = 0, descuento = 0, descuento_adicional = 0, total;
    int entradas;

    cout << "Ingrese zona elegida  (Vip, Platea, Popular): ";
    cin >> zona;

    cout << "Ingrese cantidad de entradas: ";
    cin >> entradas;

    cout << "Es socio de la U (S: si; N: no): ";
    cin >> socio;

    if (zona == 'V' || zona == 'v')
    {
        precio = 350;
    }
    else if (zona == 'P' || zona == 'p')
    {
        precio = 130;
    }
    else if (zona == 'O' || zona == 'o')
    {
        precio = 50;
    }

    if (entradas >= 3 && entradas <= 6)
    {
        descuento = 0.05;
    }
    else if (entradas >= 7 && entradas <= 9)
    {
        descuento = 0.075;
    }
    else if (entradas > 9)
    {
        descuento = 0.10;
    }

    if (socio == 'S' || socio == 's')
    {
        descuento_adicional = 0.08;
    }
    else if (socio == 'N' || socio == 'n')
    {
        descuento_adicional = 0;
    }

    total = precio * entradas * (1 - descuento) * (1 - descuento_adicional);

    cout << "El precio total a pagar es: " << total << endl;
}
