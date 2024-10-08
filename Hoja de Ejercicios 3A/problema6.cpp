//
// Created by c0d3r on 29/08/2024.
//

#include "problema6.h"
#include <iostream>

std::string primera_letra(std::string cadena)
{
    return cadena.substr(0, 1);
}

void problema6()
{
    std::string cadena, letra;

    std::cout << "Ingrese una cadena de texto: ";
    std::cin >> cadena;

    letra = primera_letra(cadena);

    std::cout << "La primera letra de la cadena es: " << letra << std::endl;
}

