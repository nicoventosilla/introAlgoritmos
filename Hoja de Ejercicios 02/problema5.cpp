//
// Created by c0d3r on 28/08/2024.
//

#include "problema5.h"
#include <iostream>

void problema5()
{
    int horas, salario, horas_extra;

    std::cout << "Ingrese el numero de horas trabajadas: ";
    std::cin >> horas;

    if (horas <= 40)
    {
        salario = horas * 16;
    }
    else
    {
        horas_extra = horas - 40;
        salario = 40 * 16 + horas_extra * 20;
    }

    std::cout << "El salario es: " << salario << std::endl;
}
