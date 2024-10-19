//
// Created by c0d3r on 12/10/2024.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int numero_aleatorio()
{
    return rand() % 40 + 1;
}

// int* num1, int* num2, int* num3, int* num4 apuntan a direcciones de memoria
void Generar_numero(int* num1, int* num2, int* num3, int* num4)
{
    do
    {
        *num1 = numero_aleatorio();
        *num2 = numero_aleatorio();
        *num3 = numero_aleatorio();
        *num4 = numero_aleatorio();
    }
    while (*num1 == *num2 || *num1 == *num3 || *num1 == *num4 ||
        *num2 == *num3 || *num2 == *num4 || *num3 == *num4);
}

void Graficar(int* num1, int* num2, int* num3, int* num4)
{
    int espacios = 0;

    for (int j = 1; j <= 6; j++) // 6 filas
    {
        if (j == 2) espacios = 40 - *num1;
        else if (j == 3) espacios = 40 - *num2;
        else if (j == 4) espacios = 40 - *num3;
        else if (j == 5) espacios = 40 - *num4;
        else espacios = 0;

        for (int i = 1; i <= 40; i++) // 40 columnas
        {
            if (j == 1) break;
            else if (j == 2)
            {
                if (i < espacios) cout << " ";
                else if (i == espacios)
                {
                    if (*num1 < 10) cout << " " << *num1;
                    else cout << *num1;
                }
                else if (i > espacios) cout << "*";
            }
            else if (j == 3)
            {
                if (i < espacios) cout << " ";
                else if (i == espacios) cout << *num2;
                else if (i > espacios) cout << "*";
            }
            else if (j == 4)
            {
                if (i < espacios) cout << " ";
                else if (i == espacios) cout << *num3;
                else if (i > espacios) cout << "*";
            }
            else if (j == 5)
            {
                if (i < espacios) cout << " ";
                else if (i == espacios) cout << *num4;
                else if (i > espacios) cout << "*";
            }
        }
        cout << endl;
    }
}

void problema1()
{
    int num1, num2, num3, num4;

    // num1, num2, num3, num4 son direcciones de memoria
    Generar_numero(&num1, &num2, &num3, &num4);

    Graficar(&num1, &num2, &num3, &num4);
}
