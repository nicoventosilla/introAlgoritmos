//
// Created by c0d3r on 27/08/2024.
//
#include <iostream>
#include "problema12.h"
using namespace std;

void problema12()
{
    int tipo_pizza;
    float precio_pizza;

    cout << "*** BIENVENIDO A LA PIZZERIA 'LOS TORTUNINJAS' ***" << endl;
    endl(cout); // Salto de linea
    cout << "[1] Por la compra de una pizza grande, obten un 10% de descuento" << endl;
    cout << "[2] Por la compra de una pizza familiar, obten un 15% de descuento" << endl;
    cout << "[3] Por la compra de una pizza fiesta, obten un 20% de descuento" << endl;
    cout << endl; // Salto de linea
    cout << "Ingrese el tipo de pizza que desea comprar (1, 2, 3): ";
    cin >> tipo_pizza;
    cout << "Ingrese el precio de la pizza: ";
    cin >> precio_pizza;
    cout << endl;

    if (tipo_pizza == 1)
    {
        cout << "*** FELICIDADES, OBTUVISTE UN 10% DE DESCUENTO ***" << endl;
        precio_pizza = precio_pizza - (precio_pizza * 0.10);
    }
    else if (tipo_pizza == 2)
    {
        cout << "*** FELICIDADES, OBTUVISTE UN 15% DE DESCUENTO ***" << endl;
        precio_pizza = precio_pizza - (precio_pizza * 0.15);
    }
    else if (tipo_pizza == 3)
    {
        cout << "*** FELICIDADES, OBTUVISTE UN 20% DE DESCUENTO ***" << endl;
        precio_pizza = precio_pizza - (precio_pizza * 0.20);
    }
    else
    {
        cout << "Tipo de pizza no valido" << endl;
    }

    cout << endl;
    cout << "El precio de la pizza con descuento es: $" << precio_pizza << endl;
}
