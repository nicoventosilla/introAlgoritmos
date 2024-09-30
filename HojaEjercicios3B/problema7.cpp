//
// Created by c0d3r on 14/09/2024.
//

#include "problema7.h"
#include <iostream>
#include <string>
using namespace std;

string encriptarBase2(int numero)
{
    string resultado;

    while (numero > 0)
    {
        resultado = to_string(numero % 2) + resultado;
        numero /= 2;
    }

    return resultado;
}

string encriptarBase4(int numero)
{
    string resultado;

    while (numero > 0)
    {
        resultado = to_string(numero % 4) + resultado;
        numero /= 4;
    }

    return resultado;
}

string encriptarBase6(int numero)
{
    string resultado;

    while (numero > 0)
    {
        resultado = to_string(numero % 6) + resultado;
        numero /= 6;
    }

    return resultado;
}

string encriptarBase8(int numero)
{
    string resultado;

    while (numero > 0)
    {
        resultado = to_string(numero % 8) + resultado;
        numero /= 8;
    }

    return resultado;
}

string encriptarBase9(int numero)
{
    string resultado;

    while (numero > 0)
    {
        resultado = to_string(numero % 9) + resultado;
        numero /= 9;
    }

    return resultado;
}

void problema7()
{
    int latitud, longitud, altitud, hora, minuto, segundo;
    char metal_precioso;

    cout << "Latitud: ";
    cin >> latitud;

    cout << "Longitud: ";
    cin >> longitud;

    cout << "Altitud: ";
    cin >> altitud;

    cout << "Metal precioso: ";
    cin >> metal_precioso;

    cout << "Hora: ";
    cin >> hora;

    cout << "Minuto: ";
    cin >> minuto;

    cout << "Segundo: ";
    cin >> segundo;

    string latitud_encriptada = encriptarBase2(latitud);
    string longitud_encriptada = encriptarBase4(longitud);
    string altitud_encriptada = encriptarBase6(altitud);
    string metal_precioso_encriptado = encriptarBase2(static_cast<int>(metal_precioso));
    string hora_encriptada = encriptarBase2(hora);
    string minuto_encriptado = encriptarBase8(minuto);
    string segundo_encriptado = encriptarBase9(segundo);

    cout << "Datos encriptados: " << endl;
    cout << latitud_encriptada << " ";
    cout << longitud_encriptada << " ";
    cout << altitud_encriptada << " ";
    cout << metal_precioso_encriptado << " ";
    cout << hora_encriptada << " ";
    cout << minuto_encriptado << " ";
    cout << segundo_encriptado << endl;
}
