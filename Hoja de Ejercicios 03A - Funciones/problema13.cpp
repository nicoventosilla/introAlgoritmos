//
// Created by c0d3r on 12/09/2024.
//

#include "problema13.h"
#include <iostream>
using namespace std;

double determinarPrecio(char marca, char catergoria)
{
    if (marca == 'B' || marca == 'b')
    {
        if (catergoria == 'P' || catergoria == 'p')
        {
            return 1300;
        }
        else if (catergoria == 'M' || catergoria == 'm')
        {
            return 1000;
        }
    }
    else if (marca == 'M' || marca == 'm')
    {
        if (catergoria == 'P' || catergoria == 'p')
        {
            return 1350;
        }
        else if (catergoria == 'M' || catergoria == 'm')
        {
            return 2500;
        }
    }
    else if (marca == 'O' || marca == 'o')
    {
        if (catergoria == 'P' || catergoria == 'p')
        {
            return 900;
        }
        else if (catergoria == 'M' || catergoria == 'm')
        {
            return 3200;
        }
    }
}

void problema13()
{
    char marca, categoria;
    double precio;

    cout << "Ingrese marca de bicicleta (B: Best; M: Monark; O: Oxford): ";
    cin >> marca;

    cout << "Ingrese Categoria (P: Paseo; M: Montanera): ";
    cin >> categoria;

    precio = determinarPrecio(marca, categoria);

    cout << "El monto a pagar es: " << precio << endl;
}
