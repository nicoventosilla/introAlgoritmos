//
// Created by c0d3r on 09/10/2024.
//

#include "problema2.h"
#include <iostream>
using namespace std;

int leer_n2()
{
    int n;
    do
    {
        cout << "Ingrese n: ";
        cin >> n;

        if (n < 3 || n > 10)
        {
            cout << "ERROR: debe ingresar un valor entre 3 y 10: " << endl;
        }
    }
    while (n < 3 || n > 10);

    return n;
}

void dibujar_cuadrado(int identificador, int espacios)
{
    for (int j = 1; j <= 4; j++)
    {
        for (int e = 1; e <= espacios; e++)
        {
            cout << "  ";
        }
        for (int i = 1; i <= 4; i++)
        {
            if (i == 2 && j == 3)
            {
                cout << identificador << ' ';
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

void problema2()
{
    int n = leer_n2();
    int espacios = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int f = 1; f <= k; f++)
        {
            dibujar_cuadrado(k, (f - 1) * 4);
        }
        cout << endl;
    }
}

/*
for (int k = 1; k <= n; k++) // cantidad de cuadrados
    {
        for (int f = 1; f <= k; f++) // filas
        {
            for (int j = 1; j <= tamanio; j++) // cuadrados
            {
                espacios = tamanio * (f - 1);

                for (int esp = 1; esp <= espacios; esp++) // espacios
                {
                    cout << "  ";
                }

                for (int i = 1; i <= 4; i++) // asteriscos
                {
                    if (i == 2 && j == 3)
                    {
                        cout << k << " ";
                    }
                    else
                    {
                        cout << "* ";
                    }
                }
                cout << endl;
            }
        }
        cout << endl;
    }
*/
