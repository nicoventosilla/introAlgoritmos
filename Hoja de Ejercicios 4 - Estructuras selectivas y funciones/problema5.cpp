//
// Created by c0d3r on 18/09/2024.
//

#include "problema5.h"
#include <iostream>
using namespace std;

void problema5()
{
    double precio_ambrosoli = 0.75, precio_ticTac = 1.15, precio_donofrio = 0.65, propina, total;
    int cantidad_ambrosoli, cantidad_ticTac, cantidad_donofrio;

    cout << "Ingrese la cantidad de caramelos Ambrosoli que desea comprar: ";
    cin >> cantidad_ambrosoli;

    cout << "Ingrese la cantidad de caramelos Tic Tac que desea comprar: ";
    cin >> cantidad_ticTac;

    cout << "Ingrese la cantidad de caramelos Donofrio que desea comprar: ";
    cin >> cantidad_donofrio;

    cout << "Ingrese el monto de la propina: ";
    cin >> propina;


    total = cantidad_ambrosoli * precio_ambrosoli + cantidad_ticTac * precio_ticTac + cantidad_donofrio *
        precio_donofrio;

    cout << "El total a pagar es: " << total << endl;

    if (propina >= total)
    {
        cout << "LA PROPINA ES SUFICIENTE PARA PAGAR EL TOTAL" << endl;
    }
    else
    {
        cout << "LA PROPINA NO ES SUFICIENTE PARA PAGAR EL TOTAL" << endl;
    }
}
