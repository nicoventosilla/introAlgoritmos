//
// Created by c0d3r on 03/09/2024.
//

#include "problema12.h"
#include <iostream>

void problema12()
{
    std::string codigo_empleado, area, primer_resultante, segundo_resultante;

    std::cout << "Ingrese numero de 8 digitos: ";
    std::cin >> codigo_empleado;

    std::cout << "Ingrese area donde labora: ";
    std::cin >> area;

    primer_resultante = codigo_empleado.substr(0, 4);
    segundo_resultante = codigo_empleado.substr(4, 4);

    //Todo: resolver problema 12
}