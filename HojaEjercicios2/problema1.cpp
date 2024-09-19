//
// Created by c0d3r on 28/08/2024.
//

#include "problema1.h"
#include <iostream>
#include <cmath>
using namespace std;

void problema1()
{
    double soles;
    int monedas_5 = 0, monedas_2 = 0, monedas_1 = 0;

    cout << "Ingrese cantidad de soles: ";
    cin >> soles;

    // Calculamos la cantidad de monedas de 5 soles
    monedas_5 = static_cast<int>(floor(soles / 5));  // floor(7.5) = 7
    soles -= monedas_5 * 5;

    // Calculamos la cantidad de monedas de 2 soles
    monedas_2 = static_cast<int>(floor(soles / 2));
    soles -= monedas_2 * 2;

    // Calculamos la cantidad de monedas de 1 sol
    monedas_1 = static_cast<int>(floor(soles / 1));

    cout << "Monedas de 5 soles: " << monedas_5 << endl;
    cout << "Monedas de 2 soles: " << monedas_2 << endl;
    cout << "Monedas de 1 sol: " << monedas_1 << endl;
}
