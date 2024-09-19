//
// Created by c0d3r on 27/08/2024.
//

#include "problema5.h"
#include <iostream>

double calcular_valor(double numero)
{
    if (numero < 0)
    {
        return -1;
    }
    else if (numero == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void problema5()
{
    double numero, valor;

    std::cout << "Ingrese numero real: ";
    std::cin >> numero;

    valor = calcular_valor(numero);

    std::cout << "El valor es: " << valor << std::endl;
}
