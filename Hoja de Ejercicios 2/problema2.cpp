//
// Created by c0d3r on 24/08/2024.
//
#include <iostream>
#include <cmath>
#include "problema2.h"

void problema2()
{
    int x1, y1, x2, y2;
    float distancia, angulo;

    std::cout << "COORDENADA (x1, y1)" << std::endl;

    std::cout << "Ingrese el valor de x1: ";
    std::cin >> x1;

    std::cout << "Ingrese el valor de y1: ";
    std::cin >> y1;

    std::cout << "COORDENADA (x2, y2)" << std::endl;

    std::cout << "Ingrese el valor de x2: ";
    std::cin >> x2;

    std::cout << "Ingrese el valor de y2: ";
    std::cin >> y2;

    distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    angulo = atan2(y2 - y1, x2 - x1) * 180 / 3.1416;

    std::cout << "La distancia entre los puntos es: " << distancia << std::endl;
    std::cout << "El angulo entre los puntos es: " << angulo << std::endl;
}
