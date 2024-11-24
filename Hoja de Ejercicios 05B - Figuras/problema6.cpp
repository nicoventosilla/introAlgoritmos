//
// Created by c0d3r on 09/10/2024.
//

#include "problema6.h"
#include <iostream>
using namespace std;

int leer_n6()
{
    int n;
    do
    {
        cout << "Ingrese n: ";
        cin >> n;

        if (n < 1 || n > 5)
        {
            cout << "ERROR: debe ingresar un valor entre 1 y 5: " << endl;
        }
    }
    while (n < 1 || n > 5);

    return n;
}

void problema6()
{
    int n = leer_n6();
    int tamanio = 4 * n;
    int contador = 1;

    for (int j = 1; j <= tamanio; j++)
    {
        for (int i = 1; i <= j; i++)
        {
            cout << contador;
        }
        cout << endl;
        contador++;

        if (contador > 4)
        {
            contador %= 4;
        }
    }
}
