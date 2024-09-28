#include "problema15.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_INTENTOS = 3;

int lanzarDado()
{
    return rand() % 100 + 1;
}

void problema15()
{
    // Inicializar la semilla de los números aleatorios
    srand(time(0));

    int numeroAleatorio = lanzarDado();
    int numero;

    cout << "JUEGO ADIVINA EL NUMERO" << endl;
    cout << "Tienes " << MAX_INTENTOS << " intentos para adivinar el numero entre 1 y 100." << endl;

    for (int intento = 1; intento <= MAX_INTENTOS; intento++)
    {
        cout << "Intento " << intento << ": ";
        cin >> numero;

        if (numero == numeroAleatorio)
        {
            cout << "Felicidades! Adivinaste el numero. El numero era " << numeroAleatorio << "." << endl;
            return;
        }
        else if (numero < numeroAleatorio)
        {
            if (intento == MAX_INTENTOS)
            {
                break;
            }
            cout << " Pista: El numero es mayor." << endl;
        }
        else
        {
            if (intento == MAX_INTENTOS)
            {
                break;
            }
            cout << " Pista: El numero es menor." << endl;
        }
    }

    cout << "Lo siento, no adivinaste el numero. El numero era " << numeroAleatorio << "." << endl;
}