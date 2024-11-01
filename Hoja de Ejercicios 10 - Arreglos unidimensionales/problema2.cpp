//
// Created by c0d3r on 17/10/2024.
//

#include "problema2.h"
#include <iostream>
using namespace std;

void ingresarPesos(int* pesosClientes, int cantidadClientes)
{
    for (int i = 0; i < cantidadClientes; i++)
    {
        cout << "Ingrese el peso del cliente " << i + 1 << ": ";
        cin >> pesosClientes[i];
    }
}

void ordenarPesos(int* pesosClientes, int cantidadClientes) // Ordenar de menor a mayor
{
    for (int j = 0; j < cantidadClientes - 1; j++)
    {
        for (int i = j + 1; i < cantidadClientes; i++)
        {
            if (pesosClientes[j] > pesosClientes[i])
            {
                int temp = pesosClientes[j];
                pesosClientes[j] = pesosClientes[i];
                pesosClientes[i] = temp;
            }
        }
    }
}

void calcularPromedio(int* pesosClientes, int cantidadClientes)
{
    double promedio = 0.0;

    for (int i = 0; i < cantidadClientes; i++)
    {
        promedio += pesosClientes[i];
    }

    promedio /= cantidadClientes;

    cout << "\nEl promedio de los pesos de los clientes es: " << promedio << endl;
}

void personaMasPesada(int* pesosClientes, int cantidadClientes)
{
    cout << "La persona que mas pesa es: " << pesosClientes[cantidadClientes - 1] << endl;
}

void cantidadPersonasContexturaDelgada(int* pesosClientes, int cantidadClientes)
{
    int cantidadDelgadas = 0;

    for (int i = 0; i < cantidadClientes; i++)
    {
        if (pesosClientes[i] < 53)
        {
            cantidadDelgadas++;
        }
    }

    cout << "Cantidad de personas cuya contextura es delgada (si su peso es menor a 53 kilos): " << cantidadDelgadas <<
        endl;
}

void cantidadPersonasContexturaMediana(int* pesosClientes, int cantidadClientes)
{
    int cantidadMedianas = 0;

    for (int i = 0; i < cantidadClientes; i++)
    {
        if (pesosClientes[i] >= 53 && pesosClientes[i] <= 60)
        {
            cantidadMedianas++;
        }
    }

    cout <<
        "Cantidad de personas cuya contextura es mediana (si su peso es mayor o igual a 53 kilos y menor o igual a 60 kilos): "
        << cantidadMedianas << endl;
}

void cantidadPersonasContexturaGruesa(int* pesosClientes, int cantidadClientes)
{
    int cantidadGruesas = 0;

    for (int i = 0; i < cantidadClientes; i++)
    {
        if (pesosClientes[i] > 60)
        {
            cantidadGruesas++;
        }
    }

    cout << "Cantidad de personas cuya contextura es gruesa (si su peso es mayor a 60 kilos): " << cantidadGruesas <<
        endl;
}

void problema2()
{
    int cantidadClientes;

    do
    {
        cout << "Ingrese numero de clientes: ";
        cin >> cantidadClientes;

        if (cantidadClientes < 1) cout << "El numero de clientes debe ser mayor a 0." << endl;
    }
    while (cantidadClientes < 1);

    int* pesosClientes = new int[cantidadClientes];

    ingresarPesos(pesosClientes, cantidadClientes);
    ordenarPesos(pesosClientes, cantidadClientes);

    cout << "Pesos de los clientes ordenados de menor a mayor: ";
    for (int i = 0; i < cantidadClientes; i++)
    {
        cout << pesosClientes[i] << " ";
    }

    calcularPromedio(pesosClientes, cantidadClientes);
    personaMasPesada(pesosClientes, cantidadClientes);
    cantidadPersonasContexturaDelgada(pesosClientes, cantidadClientes);
    cantidadPersonasContexturaMediana(pesosClientes, cantidadClientes);
    cantidadPersonasContexturaGruesa(pesosClientes, cantidadClientes);

    // Liberar memoria
    delete[] pesosClientes;
}
