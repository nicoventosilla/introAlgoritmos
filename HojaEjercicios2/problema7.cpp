//
// Created by c0d3r on 24/08/2024.
//
#include <iostream>
#include <cmath>
#include "problema7.h"

void problema7()
{
    float x, y;
    int cuadrante;

    std::cout << "Ingrese el valor de x: ";
    std::cin >> x;

    std::cout << "Ingrese el valor de y: ";
    std::cin >> y;

    if (x > 0 && y > 0)
    {
        cuadrante = 1;
    }
    else if (x < 0 && y > 0)
    {
        cuadrante = 2;
    }
    else if (x < 0 && y < 0)
    {
        cuadrante = 3;
    }
    else if (x > 0 && y < 0)
    {
        cuadrante = 4;
    }
    else
    {
        cuadrante = 0;
    }

    std::cout << "El punto (" << x << ", " << y << ") se encuentra en el cuadrante " << cuadrante;
}
