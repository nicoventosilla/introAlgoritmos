//
// Created by c0d3r on 26/08/2024.
//
#include <iostream>
#include "problema11.h"

void problema11()
{
    int edad;
    char nacionalidad;
    float sueldo_fijo;

    std::cout << "Ingrese edad del jugador: ";
    std::cin >> edad;

    std::cout << "Ingrese nacionalidad del jugador (E: Extranjero, N: Nacional): ";
    std::cin >> nacionalidad;

    sueldo_fijo = 2500;
    std::string nacionalidad_str = "nacional";

    if (nacionalidad == 'E' || nacionalidad == 'e')
    {
        sueldo_fijo = sueldo_fijo + 500;
        nacionalidad_str = "extranjero";
    }

    if (edad >= 15 && edad <= 20)
    {
        sueldo_fijo = sueldo_fijo + 1400;
    }
    else if (edad >= 21 && edad <= 25)
    {
        sueldo_fijo = sueldo_fijo + 1500;
    }
    else if (edad >= 26 && edad <= 30)
    {
        sueldo_fijo = sueldo_fijo + 1200;
    }
    else
    {
        sueldo_fijo = sueldo_fijo + 800;
    }

    std::cout << "El sueldo fijo del jugador " << nacionalidad_str << " es: " << sueldo_fijo;
}
