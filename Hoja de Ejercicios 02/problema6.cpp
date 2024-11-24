#include "problema6.h"
#include <iostream>

void problema6()
{
    int lado1, lado2, lado3;
    std::string escaleno = "F", isosceles = "F", equilatero = "F";

    std::cout << "Ingrese primer lado del triangulo: ";
    std::cin >> lado1;

    std::cout << "Ingrese segundo lado del triangulo: ";
    std::cin >> lado2;

    std::cout << "Ingrese tercer lado del triangulo: ";
    std::cin >> lado3;

    // Check if the triangle is valid
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1)
    {
        if (lado1 == lado2 && lado1 == lado3)
        {
            equilatero = "V";
        }
        else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
        {
            isosceles = "V";
        }
        else
        {
            escaleno = "V";
        }
    }
    else
    {
        std::cout << "Los lados ingresados no forman un triangulo" << std::endl;
    }

    std::cout << "Triangulo escaleno: " << escaleno << std::endl;
    std::cout << "Triangulo isosceles: " << isosceles << std::endl;
    std::cout << "Triangulo equilatero: " << equilatero << std::endl;
}