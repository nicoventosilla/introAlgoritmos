//
// Created by c0d3r on 11/09/2024.
//

#include "problema10.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void problema10()
{
    int anios, puntaje;
    char estudios;

    cout << "Ingrese cantidad de anios que labora: ";
    cin >> anios;

    cout << "Ingrese estudios (P: primaria; S: secundaria; U: universitario; G: posgrado): ";
    cin >> estudios;

    puntaje = (anios < 5) ? 5 : 10;

    if (estudios == 'P' || estudios == 'p')
    {
        puntaje += 5;
    }
    else if (estudios == 'S' || estudios == 's')
    {
        puntaje += 10;
    }
    else if (estudios == 'U' || estudios == 'u')
    {
        puntaje += 20;
    }
    else if (estudios == 'G' || estudios == 'g')
    {
        puntaje += 30;
    }

    cout << "Puntaje obtenido: " << puntaje << endl;
}
