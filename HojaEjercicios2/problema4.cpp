//
// Created by c0d3r on 24/08/2024.
//
#include <iostream>
#include <cmath>
#include "problema4.h"

void problema4()
{
    float centimetros, ingredientes_extra, precio_total, precio_pizza, extra;

    std::cout << "Ingrese la cantidad de centimetros de pizza: ";
    std::cin >> centimetros;

    std::cout << "Ingrese la cantidad de ingredientes extra: ";
    std::cin >> ingredientes_extra;

    precio_pizza = 1.5 * centimetros;
    extra = ingredientes_extra * 2.5;

    precio_total = precio_pizza + extra;

    std::cout << "El precio total de la pizza es: " << precio_total;
}
