//
// Created by c0d3r on 27/08/2024.
//

#include "problema3.h"
#include <iostream>

float convertirKilometrosAMetros(float kilometros)
{
    return kilometros * 1000;
}

void problema3()
{
    float kilometros, metros;

    std::cout << "Ingrese la distancia en kilometros: ";
    std::cin >> kilometros;

    metros = convertirKilometrosAMetros(kilometros);

    std::cout << "La distancia en metros es: " << metros << std::endl;
}
