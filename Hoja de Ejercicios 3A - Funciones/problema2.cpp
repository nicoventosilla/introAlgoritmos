//
// Created by c0d3r on 27/08/2024.
//

#include "problema2.h"
#include <iostream>

float calcular_cubo(float numero)
{
    return numero * numero * numero;
}

void problema2()
{
    float numero, cubo;

    std::cout << "Ingrese un número: ";
    std::cin >> numero;

    cubo = calcular_cubo(numero);

    std::cout << "El cubo de " << numero << " es: " << cubo << std::endl;
}
