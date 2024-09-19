//
// Created by c0d3r on 27/08/2024.
//

#include "problema4.h"
#include <iostream>

float calcular_menor_numero(int numero1, int numero2)
{
    if (numero1 < numero2)
    {
        return numero1;
    }
    else
    {
        return numero2;
    }
}

void problema4()
{
    int numero1, numero2, menor;

    std::cout << "Ingrese el primer numero: ";
    std::cin >> numero1;

    std::cout << "Ingrese el segundo numero: ";
    std::cin >> numero2;

    menor = calcular_menor_numero(numero1, numero2);

    std::cout << "El menor numero es: " << menor << std::endl;
}
