//
// Created by c0d3r on 18/09/2024.
//

#include "problema8.h"
#include <iostream>
#include <string>
using namespace std;

void problema8()
{
    int zona;
    double consumo, resto, total = 0;

    cout << "Ingrese zona (1 - 2): ";
    cin >> zona;

    cout << "Ingrese consumo de luz: ";
    cin >> consumo;

    if (zona == 1)
    {
        total = 50;

        if (consumo <= 100)
        {
            total += consumo * 0.75;
        }
        else if (consumo > 100)
        {
            resto = consumo - 100;
            total += (100 * 0.75) + resto * 0.9;
        }
    }
    else if (zona == 2)
    {
        total = 25;

        if (consumo <= 100)
        {
            total += consumo * 0.30;
        }
        else if (consumo > 100)
        {
            resto = consumo - 100;
            total += (100 * 0.30) + resto * 0.7;
        }
    }

    cout << "El total a pagar es: " << total;
}
