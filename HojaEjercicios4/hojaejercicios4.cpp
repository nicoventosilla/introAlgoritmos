//
// Created by c0d3r on 06/09/2024.
//

#include "hojaejercicios4.h"
#include "problema2.h"
#include "problema3.h"
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
    case 2:
        problema2();
        break;
    case 3:
        problema3();
        break;
    default:
        std::cout << "Opcion no valida" << std::endl;
        break;
    }
}
