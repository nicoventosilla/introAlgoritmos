#include "problema16.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int tirarDado()
{
    return rand() % 6 + 1;
}

void mostrarDado(int dado)
{
    switch (dado)
    {
    case 1:
        cout << endl;
        cout << "[     ]" << endl;
        cout << "[  o  ]" << endl;
        cout << "[     ]" << endl;
        break;
    case 2:
        cout << endl;
        cout << "[o    ]" << endl;
        cout << "[     ]" << endl;
        cout << "[    o]" << endl;
        break;
    case 3:
        cout << endl;
        cout << "[o    ]" << endl;
        cout << "[  o  ]" << endl;
        cout << "[    o]" << endl;
        break;
    case 4:
        cout << endl;
        cout << "[o   o]" << endl;
        cout << "[     ]" << endl;
        cout << "[o   o]" << endl;
        break;
    case 5:
        cout << endl;
        cout << "[o   o]" << endl;
        cout << "[  o  ]" << endl;
        cout << "[o   o]" << endl;
        break;
    case 6:
        cout << endl;
        cout << "[o   o]" << endl;
        cout << "[o   o]" << endl;
        cout << "[o   o]" << endl;
        break;
    }
}

void problema16()
{
    // Inicializar la semilla de los números aleatorios
    srand(time(0));

    int dado1, dado2;

    cout << "JUEGO DADOS" << endl;
    cout << "Presiona Enter para lanzar los dados." << endl;
    cin.ignore();
    cin.get();

    dado1 = tirarDado();
    dado2 = tirarDado();

    cout << "Dado 1: " << dado1 << endl;
    cout << "Dado 2: " << dado2 << endl;

    if (dado1 == dado2)
    {
        switch (dado1)
        {
        case 1:
            cout << "ASES!" << endl;
            break;
        case 2:
            cout << "PATOS!" << endl;
            break;
        case 3:
            cout << "TRENES!" << endl;
            break;
        case 4:
            cout << "CUADRAS!" << endl;
            break;
        case 5:
            cout << "QUINAS!" << endl;
            break;
        case 6:
            cout << "CENAS!" << endl;
            break;
        }
    }

    mostrarDado(dado1);
    mostrarDado(dado2);
}