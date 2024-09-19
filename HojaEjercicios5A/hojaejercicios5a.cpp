//
// Created by c0d3r on 12/09/2024.
//

#include "hojaejercicios5a.h"
#include "problema1.h"
#include <iostream>

void mostrarMenu()
{
    std::cout << "1. Problema 1" << std::endl;
    std::cout << "2. Problema 2" << std::endl;
    std::cout << "3. Problema 3" << std::endl;
    std::cout << "0. Salir" << std::endl;
}

int main()
{
    int opcion;

    mostrarMenu();

    std::cout << "Ingrese su opcion: ";
    std::cin >> opcion;

    switch (opcion)
    {
    case 1:
        problema1();
        break;
    default:
        std::cout << "Opcion no valida" << std::endl;
        break;
    }
}
