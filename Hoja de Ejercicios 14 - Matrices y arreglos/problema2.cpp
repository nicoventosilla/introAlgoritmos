#include "problema2.h"
#include <iostream>
#include <ctime>   // time
#include <cstdlib>  // srand, rand

using namespace std;

int generarNumeroAleatorioBit(int min, int max) // Generar un numero aleatorio entre min y max
{
    return rand() % (max - min + 1) + min;
}

void Generar_Vector(int* Arreglo)
{
    for (int i = 0; i < 8; ++i)
    {
        Arreglo[i] = generarNumeroAleatorioBit(0, 1);
    }
}

void prende_apaga_bits(int* Arreglo) // Invierte los bits
{
    for (int i = 0; i < 8; ++i)
    {
        if (Arreglo[i] == 0)
        {
            Arreglo[i] = 1;
        }
        else
        {
            Arreglo[i] = 0;
        }
    }
}

void intercambia_bits(int* Arreglo) // Intercambia los bits
{
    for (int i = 0; i < 8; i += 2)
    {
        swap(Arreglo[i], Arreglo[i + 1]);
    }
}

int convertir_a_decimal(int* Arreglo) // Convierte el arreglo de bits a decimal
{
    int decimal = 0;

    for (int i = 0; i < 8; ++i)
    {
        decimal = decimal * 2 + Arreglo[i];
    }
    return decimal;
}

void problema2() // int main()
{
    srand(time(0)); // Semilla para generar números aleatorios

    int* Arreglo = new int[8]; // Arreglo de 8 bits

    Generar_Vector(Arreglo); // Genera un vector de bits aleatorios

    // Imprime el arreglo original
    cout << "Arreglo original: ";
    for (int i = 0; i < 8; ++i)
    {
        cout << Arreglo[i] << " ";
    }
    cout << endl;

    // Invierte los bits
    prende_apaga_bits(Arreglo);

    cout << "Arreglo con bits invertidos: ";
    for (int i = 0; i < 8; ++i)
    {
        cout << Arreglo[i] << " ";
    }
    cout << endl;

    // Intercambia los bits
    intercambia_bits(Arreglo);
    cout << "Arreglo con bits intercambiados: ";
    for (int i = 0; i < 8; ++i)
    {
        cout << Arreglo[i] << " ";
    }
    cout << endl;

    // Convierte el arreglo de bits a decimal
    int decimal = convertir_a_decimal(Arreglo);
    cout << "Valor decimal: " << decimal << endl;
}
