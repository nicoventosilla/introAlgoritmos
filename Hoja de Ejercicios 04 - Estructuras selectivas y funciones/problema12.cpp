//
// Created by c0d3r on 25/09/2024.
//

#include "problema12.h"
#include <iostream>
#include <string>
using namespace std;

string convertirARomano(int numero)
{
    string romano = "";

    if (numero >= 90)
    {
        romano += "XC";
        numero -= 90;
    }

    if (numero >= 50)
    {
        romano += "L";
        numero -= 50;
    }

    if (numero >= 40)
    {
        romano += "XL";
        numero -= 40;
    }

    while (numero >= 10)
    {
        romano += "X";
        numero -= 10;
    }

    if (numero == 9)
    {
        romano += "IX";
        numero -= 9;
    }

    if (numero >= 5)
    {
        romano += "V";
        numero -= 5;
    }

    if (numero == 4)
    {
        romano += "IV";
        numero -= 4;
    }

    while (numero >= 1)
    {
        romano += "I";
        numero -= 1;
    }

    return romano;
}

void problema12()
{
    int numero;

    cout << "Ingrese un numero entre 1 y 100: ";
    cin >> numero;

    if (numero < 1 || numero > 100)
    {
        cout << "Numero fuera de rango" << endl;
    }
    else
    {
        cout << "El numero en romano es: " << convertirARomano(numero) << endl;
    }
}
