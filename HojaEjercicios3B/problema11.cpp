//
// Created by c0d3r on 29/09/2024.
//

#include "problema11.h"
#include <iostream>
using namespace std;

void problema11()
{
    int anios, puntos;
    char estudios;

    cout << "Ingrese cantidad de anios que labora: ";
    cin >> anios;

    cout << "Estudios (P: primaria; S: secundaria; U: universitario; G: posgrado): ";
    cin >> estudios;

    puntos = (anios < 5) ? 5 : 10;
    (estudios == 'P' || estudios == 'p')
        ? puntos += 5
        : (estudios == 'S' || estudios == 's')
        ? puntos += 10
        : (estudios == 'U' || estudios == 'u')
        ? puntos += 20
        : puntos += 30;

    cout << "Puntaje Obtenido: " << puntos << endl;
}
