//
// Created by c0d3r on 29/08/2024.
//

#include "problema8.h"
#include <iostream>
using namespace std;

int convertirHoras(int segundos)
{
    return segundos / 3600;
}

int convertirMinutos(int segundos)
{
    return (segundos % 3600) / 60;
}

int convertirSegundos(int segundos)
{
    return (segundos % 3600) % 60;
}

void problema8()
{
    int segundos, horas, minutos, segundos_restantes;

    cout << "Ingrese tiempo en segundos: ";
    cin >> segundos;

    horas = convertirHoras(segundos);
    minutos = convertirMinutos(segundos);
    segundos_restantes = convertirSegundos(segundos);

    cout << "Horas: " << horas << endl;
    cout << "Minutos: " << minutos << endl;
    cout << "Segundos: " << segundos_restantes << endl;
}
