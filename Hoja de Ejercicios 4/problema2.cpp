//
// Created by c0d3r on 06/09/2024.
//

#include "problema2.h"
#include <iostream>

void problema2()
{
    int edad;

    std::cout << "Ingrese edad: ";
    std::cin >> edad;

    if (edad <= 0)
    {
        std::cout << "Debe ingresar una edad correcta";
    }
    else if (edad < 18)
    {
        std::cout << "El precio de la entrada es de 7 soles";
    }
    else if (edad >= 18 && edad <= 50)
    {
        std::cout << "El precio de la entrada es de 15 soles";
    }
    else if (edad > 50)
    {
        std::cout << "El precio de la entrada es de 5 soles";
    }
}
