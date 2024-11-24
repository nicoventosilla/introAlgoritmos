//
// Created by c0d3r on 29/09/2024.
//

#include "problema10.h"
#include <iostream>
using namespace std;

void problema10()
{
    string codigoBarras;

    cout << "Ingrese codigo de barras: ";
    cin >> codigoBarras;

    int hora_venta = stoi(codigoBarras.substr(0, 2));
    int minuto_venta = stoi(codigoBarras.substr(2, 2));
    int segundo_venta = stoi(codigoBarras.substr(4, 2));
    int mercancia_id = stoi(codigoBarras.substr(6, 5));
    int e_commerce = stoi(codigoBarras.substr(11, 1));

    cout << "Hora de venta: " << hora_venta << endl;
    cout << "Minuto de venta: " << minuto_venta << endl;
    cout << "Segundo de venta: " << segundo_venta << endl;
    cout << "ID de mercancia: " << mercancia_id << endl;
    cout << "Mercancia vendida (1: Venta por E-commerce, 0: No venta por E-commerce): " << e_commerce << endl;
}
