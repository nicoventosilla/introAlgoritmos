//
// Created by c0d3r on 12/10/2024.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int numero_aleatorio()
{
    return rand() % 40 + 1; // Número aleatorio entre 1 y 40
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

int Hallar_mayor(int num1, int num2, int num3, int num4)
{
    return max(max(num1, num2), max(num3, num4)); // Retorna el mayor de los 4 números
}

int Hallar_menor(int num1, int num2, int num3, int num4)
{
    return min(num1, min(num2, min(num3, num4))); // Retorna el menor de los 4 números
}

int Hallar_anterior_mayor(int num1, int num2, int num3, int num4)
{
    int mayor = Hallar_mayor(num1, num2, num3, num4);
    int anterior_mayor = 0;

    if (num1 != mayor && num1 > anterior_mayor) anterior_mayor = num1;
    if (num2 != mayor && num2 > anterior_mayor) anterior_mayor = num2;
    if (num3 != mayor && num3 > anterior_mayor) anterior_mayor = num3;
    if (num4 != mayor && num4 > anterior_mayor) anterior_mayor = num4;

    return anterior_mayor;
}

void Graficar(int* num1, int* num2, int* num3, int* num4)
{
    int numeros[4] = {*num1, *num2, *num3, *num4};
    sort(numeros, numeros + 4); // Ordenar los números de menor a mayor

    int espacios = 0;

    for (int j = 1; j <= 5; j++) // 5 filas
    {
        if (j == 2) espacios = 40 - numeros[0];
        else if (j == 3) espacios = 40 - numeros[1];
        else if (j == 4) espacios = 40 - numeros[2];
        else if (j == 5) espacios = 40 - numeros[3];
        else espacios = 0;

        for (int i = 1; i <= 40; i++) // 40 columnas
        {
            if (j == 1) break;
            else if (j == 2)
            {
                if (i < espacios) cout << " ";
                else if (i == espacios)
                {
                    if (numeros[0] < 10) cout << " " << numeros[0];
                    else cout << numeros[0];
                }
                else if (i > espacios) cout << "*";
            }
            else if (j == 3)
            {
                if (i < espacios) cout << " ";
                else if (i == espacios)
                {
                    if (numeros[1] < 10) cout << " " << numeros[1];
                    else cout << numeros[1];
                }
                else if (i > espacios) cout << "*";
            }
            else if (j == 4)
            {
                if (i < espacios) cout << " ";
                else if (i == espacios)
                {
                    if (numeros[2] < 10) cout << " " << numeros[2];
                    else cout << numeros[2];
                }
                else if (i > espacios) cout << "*";
            }
            else if (j == 5)
            {
                if (i < espacios) cout << " ";
                else if (i == espacios)
                {
                    if (numeros[3] < 10) cout << " " << numeros[3];
                    else cout << numeros[3];
                }

                else if (i > espacios) cout << "*";
            }
        }
        cout << endl;
    }
}
void problema1()
{
    srand(time(0)); // Semilla para generar números aleatorios

    int num1, num2, num3, num4;

    // num1, num2, num3, num4 son direcciones de memoria
    Generar_numero(&num1, &num2, &num3, &num4);

    Graficar(&num1, &num2, &num3, &num4);
}
