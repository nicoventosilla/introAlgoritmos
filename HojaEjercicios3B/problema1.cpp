//
// Created by c0d3r on 29/08/2024.
//

#include "problema1.h"
#include <iostream>
    #include <cmath>
using namespace std;

void problema1()
{
    double x, resultado;

    cout << "Ingrese el valor de x: ";
    cin >> x;

    double f1 = pow(x, 6) + x - 2;
    double f2 = sqrt(pow(x, 3) + 4 * x + 1);
    double f3 = pow(x, 2) + 1;

    resultado = x <= 0 ? f1 : (x < 4 ? f2 : f3);

    cout << "El resultado es: " << resultado << endl;
}
