//
// Created by c0d3r on 29/08/2024.
//

#include "problema7.h"
#include <iostream>

double convertir_pulgadas(double centimetros)
{
    return centimetros / 2.54;
}

void problema7()
{
    double centimetros, pulgadas;

    std::cout << "Ingrese una medida en centimetros: ";
    std::cin >> centimetros;

    pulgadas = convertir_pulgadas(centimetros);

    std::cout << centimetros << " centimetros equivalen a " << pulgadas << " pulgadas." << std::endl;
}
