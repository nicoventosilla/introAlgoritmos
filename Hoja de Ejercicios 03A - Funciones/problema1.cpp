#include <iostream>
#include "problema1.h"

int calcular_mayor_valor(int num1, int num2, int num3)
{
    int mayor = num1;

    if (num2 > mayor)
    {
        mayor = num2;
    }

    if (num3 > mayor)
    {
        mayor = num3;
    }

    return mayor;
}

void problema1()
{
    int num1, num2, num3, mayor;

    std::cout << "Ingrese primer numero: ";
    std::cin >> num1;

    std::cout << "Ingrese segundo numero: ";
    std::cin >> num2;

    std::cout << "Ingrese tercer numero: ";
    std::cin >> num3;

    mayor = calcular_mayor_valor(num1, num2, num3);

    std::cout << "El mayor valor es: " << mayor << std::endl;
}
