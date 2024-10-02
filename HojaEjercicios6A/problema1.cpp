//
// Created by c0d3r on 17/09/2024.
//

#include "problema1.h"
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void problema1()
{
    int largo = 20;
    int ancho = 10;
    int x, y;

    while (true)
    {
        // Movimiento de izquierda a derecha
        for (x = 0; x <= largo; x++)
        {
            gotoxy(x, 0);
            cout << "*";
            this_thread::sleep_for(chrono::milliseconds(100));
        }

        // Movimiento de arriba a abajo
        for (y = 1; y <= ancho; y++)
        {
            gotoxy(largo, y);
            cout << "*";
            this_thread::sleep_for(chrono::milliseconds(100));
        }

        // Movimiento de derecha a izquierda
        for (x = largo - 1; x >= 0; x--)
        {
            gotoxy(x, ancho);
            cout << "*";
            this_thread::sleep_for(chrono::milliseconds(100));
        }

        // Movimiento de abajo a arriba
        for (y = ancho - 1; y >= 1; y--)
        {
            gotoxy(0, y);
            cout << "*";
            this_thread::sleep_for(chrono::milliseconds(100));
        }

        break;
    }
}
