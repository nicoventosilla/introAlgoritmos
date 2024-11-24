//
// Created by c0d3r on 14/09/2024.
//

#include "problema6.h"
#include <iostream>
using namespace std;

string encriptarTarjeta(string tarjeta_sin_ultimos_cuatro_digitos, string ultimos_cuatro_digitos)
{
    string letra_primer_digito, letra_segundo_digito, letra_tercer_digito, letra_cuarto_digito;
    string tarjeta_encriptada;

    int primer_digito = stoi(ultimos_cuatro_digitos.substr(0, 1));
    int segundo_digito = stoi(ultimos_cuatro_digitos.substr(1, 1));
    int tercer_digito = stoi(ultimos_cuatro_digitos.substr(2, 1));
    int cuarto_digito = stoi(ultimos_cuatro_digitos.substr(3, 1));

    // Encriptar primer digito
    if (primer_digito >= 1 && primer_digito <= 3)
    {
        primer_digito += 2;
        tarjeta_encriptada += to_string(primer_digito);
    }
    else if (primer_digito >= 4 && primer_digito <= 6)
    {
        letra_primer_digito = "J";
        tarjeta_encriptada += letra_primer_digito;
    }
    else if (primer_digito >= 7 && primer_digito <= 9)
    {
        primer_digito -= 4;
        tarjeta_encriptada += to_string(primer_digito);
    }
    else
    {
        letra_primer_digito = "K";
        tarjeta_encriptada += letra_primer_digito;
    }

    // Encriptar segundo digito
    if (segundo_digito >= 1 && segundo_digito <= 3)
    {
        letra_segundo_digito = "H";
        tarjeta_encriptada += letra_segundo_digito;
    }
    else if (segundo_digito >= 4 && segundo_digito <= 6)
    {
        letra_segundo_digito = "P";
        tarjeta_encriptada += letra_segundo_digito;
    }
    else if (segundo_digito >= 7 && segundo_digito <= 9)
    {
        segundo_digito -= 1;
        tarjeta_encriptada += to_string(segundo_digito);
    }
    else
    {
        segundo_digito -= 3;
        tarjeta_encriptada += to_string(segundo_digito);
    }

    // Encriptar tercer digito
    if (tercer_digito >= 1 && tercer_digito <= 3)
    {
        letra_tercer_digito = "L";
        tarjeta_encriptada += letra_tercer_digito;
    }
    else if (tercer_digito >= 4 && tercer_digito <= 6)
    {
        tercer_digito -= 3;
        tarjeta_encriptada += to_string(tercer_digito);
    }
    else if (tercer_digito >= 7 && tercer_digito <= 9)
    {
        letra_tercer_digito = "G";
        tarjeta_encriptada += letra_tercer_digito;
    }
    else
    {
        tercer_digito += 7;
        tarjeta_encriptada += to_string(tercer_digito);
    }

    // Encriptar cuarto digito
    if (cuarto_digito >= 1 && cuarto_digito <= 3)
    {
        cuarto_digito -= 1;
        tarjeta_encriptada += to_string(cuarto_digito);
    }
    else if (cuarto_digito >= 4 && cuarto_digito <= 6)
    {
        cuarto_digito += 2;
        tarjeta_encriptada += to_string(cuarto_digito);
    }
    else if (cuarto_digito >= 7 && cuarto_digito <= 9)
    {
        letra_cuarto_digito = "T";
        tarjeta_encriptada += letra_cuarto_digito;
    }
    else
    {
        letra_cuarto_digito = "F";
        tarjeta_encriptada += letra_cuarto_digito;
    }

    return tarjeta_sin_ultimos_cuatro_digitos + tarjeta_encriptada;
}

void problema6()
{
    string tarjeta, ultimos_cuatro_digitos, tarjeta_sin_ultimos_cuatro_digitos, tarjeta_encriptada;

    cout << "Ingrese el numero de tarjeta: ";
    cin >> tarjeta;

    tarjeta_sin_ultimos_cuatro_digitos = tarjeta.substr(0, 12);
    ultimos_cuatro_digitos = tarjeta.substr(12, 4);

    tarjeta_encriptada = encriptarTarjeta(tarjeta_sin_ultimos_cuatro_digitos, ultimos_cuatro_digitos);

    cout << "El numero encriptado es: " << tarjeta_encriptada << endl;
}
