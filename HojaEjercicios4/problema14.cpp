//
// Created by c0d3r on 25/09/2024.
//

#include "problema14.h"
#include <iostream>
#include <locale>
using namespace std;

void dibujarAs(string simbolo)
{
    cout << "     " << endl;
    cout << "     " << endl;
    cout << "  " << simbolo << "  " << endl;
    cout << "     " << endl;
    cout << "     " << endl;
}

void dibujarDos(string simbolo)
{
    cout << "     " << endl;
    cout << "  " << simbolo << "  " << endl;
    cout << "     " << endl;
    cout << "  " << simbolo << "  " << endl;
    cout << "     " << endl;
}

void dibujarTres(string simbolo)
{
    cout << "     " << endl;
    cout << "  " << simbolo << "  " << endl;
    cout << "  " << simbolo << "  " << endl;
    cout << "  " << simbolo << "  " << endl;
    cout << "     " << endl;
}

void dibujarCuatro(string simbolo)
{
    cout << "     " << endl;
    cout << " " << simbolo << " " << simbolo << " " << endl;
    cout << "     " << endl;
    cout << " " << simbolo << " " << simbolo << " " << endl;
    cout << "     " << endl;
}

void dibujarCinco(string simbolo)
{
    cout << "     " << endl;
    cout << " " << simbolo << " " << simbolo << " " << endl;
    cout << "  " << simbolo << "  " << endl;
    cout << " " << simbolo << " " << simbolo << " " << endl;
    cout << "     " << endl;
}

void dibujarSeis(string simbolo)
{
    cout << "     " << endl;
    cout << " " << simbolo << " " << simbolo << " " << endl;
    cout << " " << simbolo << " " << simbolo << " " << endl;
    cout << " " << simbolo << " " << simbolo << " " << endl;
    cout << "     " << endl;
}

void dibujarSiete(string simbolo)
{
    cout << "     " << endl;
    cout << " " << simbolo << " " << simbolo << " " << endl;
    cout << " " << simbolo << simbolo << simbolo << " " << endl;
    cout << " " << simbolo << " " << simbolo << " " << endl;
    cout << "     " << endl;
}

void dibujarOcho(string simbolo)
{
    cout << "     " << endl;
    cout << " " << simbolo << simbolo << simbolo << " " << endl;
    cout << " " << simbolo << " " << simbolo << " " << endl;
    cout << " " << simbolo << simbolo << simbolo << " " << endl;
    cout << "     " << endl;
}

void dibujarNueve(string simbolo)
{
    cout << "     " << endl;
    cout << " " << simbolo << simbolo << simbolo << " " << endl;
    cout << " " << simbolo << simbolo << simbolo << " " << endl;
    cout << " " << simbolo << simbolo << simbolo << " " << endl;
    cout << "     " << endl;
}

void dibujarDiez(string simbolo)
{
    cout << simbolo << "   " << simbolo << endl;
    cout << " " << simbolo << " " << simbolo << " " << simbolo << " " << endl;
    cout << simbolo << "   " << simbolo << endl;
    cout << " " << simbolo << " " << simbolo << " " << simbolo << " " << endl;
    cout << simbolo << "   " << simbolo << endl;
}

void dibujarJ(string simbolo)
{
    cout << "     " << endl;
    cout << "  J  " << endl;
    cout << "  " << simbolo << "  " << endl;
    cout << "  J  " << endl;
    cout << "     " << endl;
}

void dibujarQ(string simbolo)
{
    cout << "     " << endl;
    cout << "  Q  " << endl;
    cout << "  " << simbolo << "  " << endl;
    cout << "  Q  " << endl;
    cout << "     " << endl;
}

void dibujarK(string simbolo)
{
    cout << "     " << endl;
    cout << "  K  " << endl;
    cout << "  " << simbolo << "  " << endl;
    cout << "  K  " << endl;
    cout << "     " << endl;
}

void dibujarCartas(string simbolo, int primera_carta)
{
    switch (primera_carta)
    {
    case 1:
        dibujarAs(simbolo);
        break;
    case 2:
        dibujarDos(simbolo);
        break;
    case 3:
        dibujarTres(simbolo);
        break;
    case 4:
        dibujarCuatro(simbolo);
        break;
    case 5:
        dibujarCinco(simbolo);
        break;
    case 6:
        dibujarSeis(simbolo);
        break;
    case 7:
        dibujarSiete(simbolo);
        break;
    case 8:
        dibujarOcho(simbolo);
        break;
    case 9:
        dibujarNueve(simbolo);
        break;
    case 10:
        dibujarDiez(simbolo);
        break;
    case 11:
        dibujarJ(simbolo);
        break;
    case 12:
        dibujarQ(simbolo);
        break;
    case 13:
        dibujarK(simbolo);
        break;
    }
}

void problema14()
{
    char palo;
    string simbolo;
    int primera_carta, segunda_carta;

    cout << "*** Palos de barajas ***" << endl;
    cout << "<C> Corazones ♥" << endl;
    cout << "<D> Diamantes ♦" << endl;
    cout << "<T> Treboles ♣" << endl;
    cout << "<E> Espadas ♠" << endl;

    // Validar palo
    do
    {
        cout << "Elegir palo de barajas a jugar : ";
        cin >> palo;

        if (palo != 'C' && palo != 'c' && palo != 'D' && palo != 'd' && palo != 'T' && palo != 't' && palo != 'E' &&
            palo != 'e')
        {
            cout << "Palo incorrecto, intente de nuevo" << endl;
        }
    }
    while (palo != 'C' && palo != 'c' && palo != 'D' && palo != 'd' && palo != 'T' && palo != 't' && palo != 'E' && palo
        != 'e');

    // Validar cartas
    do
    {
        cout << "Muestre la primera carta: ";
        cin >> primera_carta;

        if (primera_carta < 1 || primera_carta > 13)
        {
            cout << "Carta incorrecta, intente de nuevo" << endl;
        }
    }
    while (primera_carta < 1 || primera_carta > 13);

    do
    {
        cout << "Muestre la segunda carta: ";
        cin >> segunda_carta;

        if (segunda_carta < 1 || segunda_carta > 13)
        {
            cout << "Carta incorrecta, intente de nuevo" << endl;
        }
    }
    while (segunda_carta < 1 || segunda_carta > 13);

    if (primera_carta == 1 && segunda_carta == 1)
    {
        cout << "PAR DE ASES!" << endl;
    }
    else if (primera_carta == 3 && segunda_carta == 3)
    {
        cout << "TRIOS!" << endl;
    }
    else if (primera_carta == 13 && segunda_carta == 13)
    {
        cout << "REYES!" << endl;
    }

    if (palo == 'C' || palo == 'c')
    {
        simbolo = "♥";
    }
    else if (palo == 'D' || palo == 'd')
    {
        simbolo = "♦";
    }
    else if (palo == 'T' || palo == 't')
    {
        simbolo = "♣";
    }
    else if (palo == 'E' || palo == 'e')
    {
        simbolo = "♠";
    }

    dibujarCartas(simbolo, primera_carta);
    dibujarCartas(simbolo, segunda_carta);
}
