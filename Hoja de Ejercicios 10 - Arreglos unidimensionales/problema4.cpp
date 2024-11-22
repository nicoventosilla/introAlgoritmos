//
// Created by c0d3r on 03/11/2024.
//

#include "problema4.h"
#include <iostream>
#include <cstdlib> // Para usar srand y rand
#include <ctime> // Para usar time
#include <algorithm> // Para usar sort

using namespace std;

/*
* La empresa TORNILLOS S.A. ha ganado una licitación para exportar pernos y desea hacer un análisis
de los diametros de los pernos que produce para cumplir con los estándares de calidad. Para ello se
desea contar con un programa en C++ que realice lo siguiente:
 Solicite como dato el número de pernos a analizar (N: tendrá un valor máximo de 100)
 Genere aleatoriamente el diametro (en mm) de los N pernos. El valor del diametro puede ser un
valor entre 5 y 30.
 Muestre un listado ordenado descendentemente por el diametro, de los N pernos.
 Calcule el diametro promedio de los N pernos analizados.
 Solicite un diametro (DE) e indique cuantos pernos tienen un diametro inferior al ingresado.
Además si más del 50% de los pernos posee un diametro inferior a DE imprima el mensaje
“Lote defectuoso”.
Recuerde que la aplicación deberá validar el ingreso de datos.
 */

int generarAleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void generarPernosAleatorios(int Pernos[], int numero_pernos)
{
    cout << "Generando pernos aleatorios..." << endl;
    for (int i = 0; i < numero_pernos; i++)
    {
        Pernos[i] = generarAleatorio(5, 30);
    }
    cout << endl;
}

void mostrarPernos(int Pernos[], int numero_pernos)
{
    for (int i = 0; i < numero_pernos; i++)
    {
        cout << "Perno " << i << ": " << Pernos[i] << " mm" << endl;
    }
}

void ordenarPernosDescendente(int Pernos[], int numero_pernos)
{
    cout << "Ordenando pernos descendentemente..." << endl;
    sort(Pernos, Pernos + numero_pernos);
    reverse(Pernos, Pernos + numero_pernos);
    mostrarPernos(Pernos, numero_pernos);
}

void calcularPromedioPernos(int Pernos[], int numero_pernos)
{
    double suma = 0.0;
    for (int i = 0; i < numero_pernos; i++)
    {
        suma += Pernos[i];
    }
    cout << "El diametro promedio de los pernos es: " << suma / numero_pernos << " mm" << endl;
}

void buscarPernosMenores(int Pernos[], int numero_pernos)
{
    cout << "Ingrese el diametro a buscar: ";
    int diametro;
    cin >> diametro;

    int pernos_menores = 0;
    for (int i = 0; i < numero_pernos; i++)
    {
        if (Pernos[i] < diametro)
        {
            pernos_menores++;
        }
    }

    cout << "Cantidad de pernos con diametro menor a " << diametro << ": " << pernos_menores << endl;

    if (pernos_menores > numero_pernos / 2)
    {
        cout << "Lote defectuoso" << endl;
    }
}

void problema4()
{
    srand(time(0));

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

    int Pernos[numero_pernos];

    generarPernosAleatorios(Pernos, numero_pernos);
    mostrarPernos(Pernos, numero_pernos);
    ordenarPernosDescendente(Pernos, numero_pernos);
    calcularPromedioPernos(Pernos, numero_pernos);
    buscarPernosMenores(Pernos, numero_pernos);
}
