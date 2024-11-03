//
// Created by c0d3r on 03/11/2024.
//

#include "problema4.h"
#include <iostream>
#include <cstdlib> // Para usar srand y rand
#include <ctime> // Para usar time

using namespace std;

void problema4()
{
    srand(time(0));

    // Ingresar el numero de pernos
    int numero_pernos;

    do
    {
        cout << "Ingrese el numero de pernos: ";
        cin >> numero_pernos;

        if (numero_pernos < 1 || numero_pernos > 100)
        {
            cout << "El numero de pernos debe estar entre 1 y 100" << endl;
        }
    }
    while (numero_pernos < 1 || numero_pernos > 100);

    // Crear un arreglo de pernos
    int* Pernos = new int[numero_pernos];

    // Genera un numero aleatorio entre 5 y 30: rand() % (max - min + 1) + min;
    for (int i = 0; i < numero_pernos; i++)
    {
        Pernos[i] = rand() % (30 - 5 + 1) + 5;
    }

    // Ordenar el diametro de los pernos de mayor a menor
    for (int j = 0; j < numero_pernos - 1; j++)
    {
        for (int i = j + 1; i < numero_pernos; i++)
        {
            if (Pernos[j] < Pernos[i])
            {
                int aux = Pernos[j];
                Pernos[j] = Pernos[i];
                Pernos[i] = aux;
            }
        }
    }

    cout << "Diametro de los pernos ordenados de mayor a menor: " << endl;

    for (int i = 0; i < numero_pernos; i++)
    {
        cout << Pernos[i] << " ";
    }

    // Calcula el promedio de los pernos
    double promedio = 0.0;

    for (int i = 0; i < numero_pernos; i++)
    {
        promedio += Pernos[i];
    }

    promedio /= numero_pernos;

    cout << "\nEl promedio del diametro de los pernos es: " << promedio << endl;

    // Buscar pernos con diametro menor al ingresado
    int diametro;
    cout << "Ingrese el diametro del perno a buscar: ";
    cin >> diametro;

    int cantidad_pernos_inferiores = 0;

    for (int i = 0; i < numero_pernos; i++)
    {
        if (Pernos[i] < diametro)
        {
            cantidad_pernos_inferiores++;
        }
    }

    cout << "Cantidad de pernos con diametro menor a " << diametro << ": " << cantidad_pernos_inferiores << endl;

    // si más del 50% de los pernos posee un diámetro inferior a ingresado imprima el mensaje "Lote defectuoso"
    if (cantidad_pernos_inferiores > numero_pernos / 2)
    {
        cout << "Lote defectuoso" << endl;
    }
}
