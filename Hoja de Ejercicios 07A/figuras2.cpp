#include "figuras2.h"
#include <iostream>
using namespace std;

void dibujarCuadrados1(int n)
{
    int tamanio = 5;
    int espacios = (n * 2);

    for (int k = 1; k <= n; k++)
    {
        espacios -= 2;

        for (int j = 0; j < tamanio; j++) // Filas
        {
            for (int esp = 1; esp <= espacios; esp++)
            {
                cout << " ";
            }

            for (int i = 1; i <= k; i++) // Cuadrados
            {
                for (int col = 0; col < tamanio - 1; col++) // Columnas
                {
                    if (j == 0 || j == tamanio - 1 || col == 0 || col == tamanio - 2)
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

void figuras2()
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
    }
    while (n < 1 || n > 5);

    dibujarCuadrados1(n);
}
