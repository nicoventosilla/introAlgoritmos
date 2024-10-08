//
// Created by c0d3r on 01/10/2024.
//

#include "figuras3.h"
#include <iostream>
using namespace std;

void dibujarCuadrados2(int n)
{
    int tamanio = 5;
    int espacios = 0;

    for (int k = n; k >= 1; k--) // n° veces
    {
        espacios += 2;

        for (int fila = 1; fila <= tamanio; fila++) // Fila
        {

            for (int esp = 1; esp <= espacios; esp++) // Espacios
            {
                cout << " ";
            }

            for (int j = 1; j <= k; j++) // Cuadrados
            {
                for (int i = 1; i <= tamanio - 1; i++)
                {
                    if (fila == 1 || fila == tamanio || i == 1 || i == tamanio - 1)
                    {
                        cout << k;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}

void figuras3()
{
    int n;

    do
    {
        cout << "Introduce un numero entre 1 y 5: ";
        cin >> n;

        if (n < 1 || n > 5)
        {
            cout << "Numero no valido. Intentalo de nuevo." << endl;
        }
    } while (n < 1 || n > 5);

    dibujarCuadrados2(n);
}