//
// Created by c0d3r on 09/10/2024.
//

#include "problema5.h"
#include <iostream>
using namespace std;

int leer_n5()
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

void problema5()
{
    int n = leer_n5();
    int tamanio = 4;
    int espacios1 = 0;
    int espacios2 = 0;

    for (int k = 1; k <= n; k++)
    {
        if (k <= 3)
        {
            espacios1 = (k - 1) * 4;
        }
        else
        {
            espacios1 -= 4;
        }

        if (k <= 2)
        {
            espacios2 = 4 * (5 - (k * 2));
        }
        else if (k == 3)
        {
            espacios2 = 0;
        }
        else if (k == 4)
        {
            espacios2 = 4;
        }
        else
        {
            espacios2 = 12;
        }


        for (int j = 1; j <= tamanio; j++)
        {
            for (int esp1 = 1; esp1 <= espacios1; esp1++)
            {
                cout << " ";
            }

            for (int i = 1; i <= tamanio; i++)
            {
                if (i == 1 || i == tamanio || j == 1 || j == tamanio)
                {
                    cout << k;
                }
                else
                {
                    cout << " ";
                }
            }

            if (k != 3)
            {
                for (int esp2 = 1; esp2 <= espacios2; esp2++)
                {
                    cout << " ";
                }

                for (int i = 1; i <= tamanio; i++)
                {
                    if (i == 1 || i == tamanio || j == 1 || j == tamanio)
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
