//
// Created by c0d3r on 11/09/2024.
//

#include "problema9.h"
#include <iostream>
using namespace std;

double calcularTotal(double monto)
{
    if (monto < 1000)
    {
        return monto * 0.1;
    }
    if (monto >= 1000)
    {
        return monto * 0.2;
    }
}

void problema9()
{
    double monto, total;

    cout << "Ingrese monto: ";
    cin >> monto;

    total = calcularTotal(monto);

    cout << "Total: " << total << endl;
}
