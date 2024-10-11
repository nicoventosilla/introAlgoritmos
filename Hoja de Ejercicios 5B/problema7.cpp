//
// Created by c0d3r on 10/10/2024.
//

#include "problema7.h"
#include <iostream>
#include <string>
using namespace std;

int leer_n7()
{
    int n;
    do
    {
        cout << "Ingrese n: ";
        cin >> n;

        if (n < 2 || n > 6)
        {
            cout << "ERROR: debe ingresar un valor entre 2 y 6: " << endl;
        }
    }
    while (n < 2 || n > 6);

    return n;
}

void imprimir_espacios(int espacios)
{
    for (int i = 1; i <= espacios; i++)
    {
        cout << "  ";
    }
}

void problema7()
{
    int n = leer_n7();
    int tamanio = n * 2;
    int espacios_inicio = n - 1;
    int espacios_final = -1;
    int limite = 1;
    string A = "A ", B = "B ", C = "C ", D = "D ", E = "E ", F = "F ";

    for (int j = 1; j < tamanio; j++)
    {
        for (int e = 1; e <= espacios_inicio; e++)
        {
            cout << "  ";
        }
        espacios_inicio--;

        for (int i = 1; i <= limite; i++)
        {
            if (i == 1 || i == limite)
            {
                if (j <= n) cout << A;
                else continue;
            }
            else if (i == 2 || i == limite - 1)
            {
                if (j <= n + 1) cout << B;
                else continue;
            }
            else if (i == 3 || i == limite - 2)
            {
                if (j >= 3 && j < 3 + n)
                {
                    if (n >= 3)
                    {
                        if (i > 3 && i < limite - 2) cout << "  ";
                        else cout << C;
                    }
                    else cout << "  ";
                }
                continue;
            }
            else if (i == 4 || i == limite - 3)
            {
                if (j >= 4 && j < 4 + n)
                {
                    if (n >= 4)
                    {
                        if (i > 4 && i < limite - 3) cout << "  ";
                        else cout << D;
                    }
                    else cout << "  ";
                }
                continue;
            }
            else if (i == 5 || i == limite - 4)
            {
                if (j >= 5 && j < 5 + n)
                {
                    if (n >= 5)
                    {
                        if (i > 5 && i < limite - 4) cout << "  ";
                        else cout << E;
                    }
                    else cout << "  ";
                }
                continue;
            }
            else if (i == 6 || i == limite - 5)
            {
                if (j >= 5 && j < 6 + n)
                {
                    if (n >= 6)
                    {
                        if (i > 6 && i < limite - 5) cout << "  ";
                        else cout << F;
                    }
                    else cout << "  ";
                }
                continue;
            }
            else
            {
                cout << "  ";
            }
        }

        limite += 2;

        cout << endl;
    }
}
