//
// Created by c0d3r on 28/08/2024.
//

#include "problema8.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void problema8()
{
    int litros;
    double cuota_fija = 20, pago = 0;

    cout << "Ingrese numero de litros consumidos: ";
    cin >> litros;

    if (litros <= 50)
    {
        pago = cuota_fija;
    }
    else if (litros >= 51 && litros <= 200)
    {
        pago = cuota_fija + (litros - 50) * 2;
    }
    else if (litros > 200)
    {
        pago = cuota_fija + 300 + (litros - 200) * 3.5;
    }

    cout << "El monto a pagar es: " << pago << endl;
}
