//
// Created by c0d3r on 24/08/2024.
//
#include <iostream>
#include <cmath>
#include "problema3.h"

void problema3()
{
    int numero_neumaticos;
    float precio_neumatico, precio_total;

    std::cout << "Ingrese el numero de neumaticos a comprar: ";
    std::cin >> numero_neumaticos;

    if (numero_neumaticos < 3)
    {
        precio_neumatico = 145;
    }
    else if (numero_neumaticos >= 3 && numero_neumaticos < 5)
    {
        precio_neumatico = 138;
    }
    else
    {
        precio_neumatico = 135;
    }

    precio_total = numero_neumaticos * precio_neumatico;
    std::cout << "El precio total de los neumaticos es: " << precio_total;
}
