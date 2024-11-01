//
// Created by c0d3r on 12/09/2024.
//

#include "problema12.h"
#include <iostream>
using namespace std;

char determinarDestino(int departamento)
{
    if (departamento == 1)
    {
        return 'T';
    }
    else if (departamento == 2)
    {
        return 'A';
    }
    else if (departamento == 3)
    {
        return 'P';
    }
}

char determinarParada(int realizan_paradas)
{
    if (realizan_paradas == 1)
    {
        return 'S';
    }
    else if (realizan_paradas == 2)
    {
        return 'N';
    }
}

void problema12()
{
    string codigo_salida;
    int departamento, hora_salida, realizan_paradas;
    char destino, parada;

    cout << "Ingrese codigo de salida: ";
    cin >> codigo_salida;

    departamento = stoi(codigo_salida.substr(0, 1));
    hora_salida = stoi(codigo_salida.substr(1, 2));
    realizan_paradas = stoi(codigo_salida.substr(3, 1));

    destino = determinarDestino(departamento);
    parada = determinarParada(realizan_paradas);

    cout << "Departamento de destino: " << destino << endl;
    cout << "Hora de salida: " << hora_salida << endl;
    cout << "Realizan paradas: " << parada << endl;
}
