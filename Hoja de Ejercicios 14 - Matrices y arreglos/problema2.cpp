#include "problema2.h"
#include <iostream>
#include <ctime>   // time
#include <cstdlib> // srand, rand
#include <cmath>  // pow

using namespace std;

// Generar un número aleatorio entre min y max
int generarNumeroAleatorioBit(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Generar un vector de bits aleatorios
void Generar_Vector(int Arreglo[])
{
    for (int i = 0; i < 8; ++i) // Recorrer el arreglo
    {
        Arreglo[i] = generarNumeroAleatorioBit(0, 1); // Generar un número aleatorio entre 0 y 1
    }
}

// Imprimir el arreglo
void Imprimir_Arreglo(int Arreglo[])
{
    for (int i = 0; i < 8; ++i) // Recorrer el arreglo
    {
        cout << Arreglo[i] << " "; // Mostrar el arreglo
    }
    cout << endl;
}

// Invertir los bits del arreglo
void prende_apaga_bits(int Arreglo[])
{
    for (int i = 0; i < 8; ++i) // Recorrer el arreglo
    {
        if (Arreglo[i] == 0) // Si el bit es 0
        {
            Arreglo[i] = 1; // Cambiarlo a 1
        }
        else // Si el bit es 1
        {
            Arreglo[i] = 0; // Cambiarlo a 0
        }
    }
}

// Intercambiar los bits del arreglo
void intercambia_bits(int Arreglo[])
{
    for (int i = 0; i < 8; i += 2) // Recorrer el arreglo de 2 en 2
    {
        swap(Arreglo[i], Arreglo[i + 1]); // Intercambiar los bits (0 1 -> 1 0)
    }
}

// Convertir el arreglo de bits a decimal
int convertir_a_decimal(int Arreglo[])
{
    int decimal = 0;
    for (int i = 0; i < 8; ++i)
    {
        // Multiplica el bit por 2 elevado a la posición del bit
        decimal += Arreglo[i] * pow(2, 7 - i);
    }
    return decimal;
}

void problema2() // int main()
{
    srand(time(0)); // Semilla para generar números aleatorios

    int Arreglo[8]; // Arreglo de 8 bits en la pila

    // Genera un vector de bits aleatorios
    Generar_Vector(Arreglo);

    cout << "Arreglo de bits" << endl;
    Imprimir_Arreglo(Arreglo);

    // Invierte los bits (0 -> 1, 1 -> 0)
    prende_apaga_bits(Arreglo);
    cout << "Arreglo con bits invertidos" << endl;
    Imprimir_Arreglo(Arreglo);

    // Intercambia los bits de dos en dos (0 1 -> 1 0)
    intercambia_bits(Arreglo);
    cout << "Arreglo con bits intercambiados" << endl;
    Imprimir_Arreglo(Arreglo);

    int decimal = convertir_a_decimal(Arreglo); // Convierte el arreglo de bits a decimal
    cout << "Valor decimal: " << decimal << endl; // Imprime el valor decimal
}
