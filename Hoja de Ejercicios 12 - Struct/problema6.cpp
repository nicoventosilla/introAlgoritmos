//
// Created by c0d3r on 22/11/2024.
//

#include "problema6.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * 6. Definir estructuras para cuadriláteros y triángulos, defina las funciones que calculan las áreas.
 */

struct Cuadrado
{
    double lado;
};

struct Triangulo
{
    double base;
    double altura;
};

double area1(Cuadrado c) // Area de un cuadrado
{
    return c.lado * c.lado; // Lado al cuadrado
}

double area2(Triangulo t) // Area de un triangulo
{
    return (t.base * t.altura) / 2; // Base por altura dividido entre 2
}

void problema6() // int main()
{
    Cuadrado c;
    Triangulo t;

    cout << "Ingrese el lado del cuadrado: ";
    cin >> c.lado;

    cout << "Ingrese la base del triangulo: ";
    cin >> t.base;

    cout << "Ingrese la altura del triangulo: ";
    cin >> t.altura;

    cout << "El area del cuadrado es: " << area1(c) << endl;
    cout << "El area del triangulo es: " << area2(t) << endl;
}
