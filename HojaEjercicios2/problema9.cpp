//
// Created by c0d3r on 24/08/2024.
//
#include <iostream>
#include <cmath>
#include <string>
#include "problema9.h"
using namespace std;

void problema9()
{
    string codigo_barras, dia, mes, anio, tt, pp;

    cout << "Ingrese el codigo de barras de 12 digitos: ";
    cin >> codigo_barras;

    dia = codigo_barras.substr(0, 2);
    mes = codigo_barras.substr(2, 2);
    anio = codigo_barras.substr(4, 4);
    tt = codigo_barras.substr(8, 2);
    pp = codigo_barras.substr(10, 2);

    int tt_int = stoi(tt); // Convert string to int
    char tt_ascii = static_cast<char>(tt_int); // Convert int to ASCII

    if (pp == "00")
    {
        pp = "Si";
    }
    else
    {
        pp = "No";
    }

    cout << "Dia de vencimiento: " << dia << endl;
    cout << "Mes de vencimiento: " << mes << endl;
    cout << "Anio de vencimiento: " << anio << endl;
    cout << "El tipo de producto es: " << tt_ascii << endl;
    cout << "El producto es perecible: " << pp << endl;
}
