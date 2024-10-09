//
// Created by c0d3r on 09/10/2024.
//

#include "problema4.h"
#include <iostream>
using namespace std;

int leer_n4()
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

void problema4()
{
    int n = leer_n4();
    int tamanio = 5;

    for (int k = n; k >= 1; k--) // numero de cuadros
    {
        for (int j = 1; j <= tamanio; j++) // lineas
        {
            for (int i = 1; i <= tamanio * 2; i++)
            {
                if (i == 1 || i == tamanio * 2 || j == 1 || j == tamanio)
                {
                    cout << k;
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }}
