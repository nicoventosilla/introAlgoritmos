//
// Created by c0d3r on 17/10/2024.
//

#include "problema2.h"
#include <iostream>
#include <algorithm>

using namespace std;

/*
* El gerente del gimnasio Fitness Gym, desea contar con un programa en C++ que permita leer los
pesos de N clientes, almacenarlos en un vector y luego le indique los siguientes datos estadísticos:
 El peso promedio.
 El peso de la persona que pesa más.
 El número de personas cuya contextura es delgada (si su peso es menor a 53 kilos)
 El número de personas cuya contextura es mediana (si su peso esta entre 53 y 60 kilos inclusive)
 El número de personas cuya contextura es gruesa (si su peso es mayor a 60 kilos)
 */

void ingresarPesos(int Pesos[], int cantidadClientes)
{
    for (int i = 0; i < cantidadClientes; i++)
    {
        cout << "Ingrese peso del cliente " << i << " : ";
        cin >> Pesos[i];
    }
    cout << endl;
}

void ordenarPesos(int Pesos[], int cantidadClientes) // Ordenar de menor a mayor
{
    sort(Pesos, Pesos + cantidadClientes);
}

void mostrarPesos(int Pesos[], int cantidadClientes)
{
    for (int i = 0; i < cantidadClientes; i++)
    {
        cout << Pesos[i] << " ";
    }
    cout << endl;
}

void calcularPromedioPesos(int Pesos[], int cantidadClientes)
{
    double suma = 0.0;
    for (int i = 0; i < cantidadClientes; i++)
    {
        suma += Pesos[i];
    }
    cout << "El promedio de pesos es: " << suma / cantidadClientes << endl;
}

void personaMasPesada(int Pesos[], int cantidadClientes)
{
    cout << "La persona mas pesada pesa: " << Pesos[cantidadClientes - 1] << endl;
}

void cantidadPersonasContexturaDelgada(int Pesos[], int cantidadClientes)
{
    int cantidadPersonasDelgadas = 0;
    for (int i = 0; i < cantidadClientes; i++)
    {
        if (Pesos[i] < 53)
        {
            cantidadPersonasDelgadas++;
        }
    }
    cout << "Cantidad de personas con contextura delgada: " << cantidadPersonasDelgadas << endl;
}

void cantidadPersonasContexturaMediana(int Pesos[], int cantidadClientes)
{
    int cantidadPersonasMedianas = 0;
    for (int i = 0; i < cantidadClientes; i++)
    {
        if (Pesos[i] >= 53 && Pesos[i] <= 60)
        {
            cantidadPersonasMedianas++;
        }
    }
    cout << "Cantidad de personas con contextura mediana: " << cantidadPersonasMedianas << endl;
}

void cantidadPersonasContexturaGruesa(int Pesos[], int cantidadClientes)
{
    int cantidadPersonasGruesas = 0;
    for (int i = 0; i < cantidadClientes; i++)
    {
        if (Pesos[i] > 60)
        {
            cantidadPersonasGruesas++;
        }
    }
    cout << "Cantidad de personas con contextura gruesa: " << cantidadPersonasGruesas << endl;
}

void problema2()
{
    int cantidadClientes; // Cantidad de clientes

    do
    {
        cout << "Ingrese numero de clientes: ";
        cin >> cantidadClientes;

        if (cantidadClientes < 1) cout << "El numero de clientes debe ser mayor a 0." << endl;
    }
    while (cantidadClientes < 1);

    int Pesos[cantidadClientes]; // Arreglo de pesos

    ingresarPesos(Pesos, cantidadClientes); // Ingresar pesos
    ordenarPesos(Pesos, cantidadClientes); // Ordenar pesos
    mostrarPesos(Pesos, cantidadClientes); // Mostrar pesos
    calcularPromedioPesos(Pesos, cantidadClientes); // Calcular promedio de pesos
    personaMasPesada(Pesos, cantidadClientes); // Persona mas pesada
    cantidadPersonasContexturaDelgada(Pesos, cantidadClientes); // Cantidad de personas con contextura delgada
    cantidadPersonasContexturaMediana(Pesos, cantidadClientes); // Cantidad de personas con contextura mediana
    cantidadPersonasContexturaGruesa(Pesos, cantidadClientes); // Cantidad de personas con contextura gruesa
}
