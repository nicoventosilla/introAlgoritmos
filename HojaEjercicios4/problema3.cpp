//
// Created by c0d3r on 07/09/2024.
//

#include "problema3.h"
#include <iostream>

bool validarTriangulo(int lado1, int lado2, int lado3)
{
    return (lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1);
}

void problema3()
{
    int lado1, lado2, lado3;
    bool esTriangulo;

    std::cout << "Ingrese los lados del triangulo (1 2 3): ";
    std::cin >> lado1 >> lado2 >> lado3;

    esTriangulo = validarTriangulo(lado1, lado2, lado3);

    if (esTriangulo)
    {
        std::cout << "SI ES UN TRIANGULO";
    }
    else
    {
        std::cout << "NO ES UN TRIANGULO";
    }
}
