//
// Created by c0d3r on 30/09/2024.
//

#include "figuras1.h"
#include <iostream>
using namespace std;

void dibujarRelojes(int n)
{
    char caracter;
    int tamanio = 8;

    for (int k = 0; k <= n; k++)
    {
        for (int j = 0; j < tamanio; j++)
        {
            for (int i = 0; i < tamanio; i++)
            {
                caracter = rand() % (91 - 65) + 65;

                if (j == 0 || j == tamanio - 1 || j == i || j + i == tamanio - 1)
                {
                    cout << caracter;
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

void figuras1()
{
    int n;

    do
    {
        cout << "Ingrese un numero entre 3 y 10: ";
        cin >> n;

        if (n < 3 || n > 10)
        {
            cout << "Número no válido. Intente de nuevo." << endl;
        }
    }
    while (n < 3 || n > 10);

    dibujarRelojes(n);
}
