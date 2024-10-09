//
// Created by c0d3r on 09/10/2024.
//

#include "problema3.h"
#include <iostream>
using namespace std;

int leer_n3()
{
    int n;
    do
    {
        cout << "Ingrese n: ";
        cin >> n;

        if (n < 0 || n > 10)
        {
            cout << "ERROR: debe ingresar un valor entre 0 y 10: " << endl;
        }
    }
    while (n < 0 || n > 10);

    return n;
}

void problema3()
{
    int n = leer_n3();
    int tamanio = 4;
    char caracter;

    for (int k = 1; k <= n; k++)
    {
        for (int j = 1; j <= tamanio; j++)
        {
            for (int i = 1; i <= tamanio; i++) // asteriscos
            {
                if (i == 1 || i == tamanio || j == 1 || j == tamanio)
                {
                    caracter = rand() % (91 - 65) + 65;
                    cout << caracter << " ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}
