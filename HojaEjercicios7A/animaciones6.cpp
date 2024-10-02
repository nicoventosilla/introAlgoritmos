//
// Created by c0d3r on 01/10/2024.
//

#include "animaciones6.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void animaciones6()
{
    int x = 1, y = 1;
    char direccion = 'R';
    int ancho = 40, alto = 15;
    bool salir = false;

    while (!salir)
    {
        system("cls");

        for (int i = 0; i < y; i++) cout << endl;
        for (int i = 0; i < x; i++) cout << " ";
        cout << "*";

        if (_kbhit())
        {
            char tecla = _getch();

            if (tecla == 27) salir = true;
            else if (tecla == 72) direccion = 'U';
            else if (tecla == 80) direccion = 'D';
            else if (tecla == 77) direccion = 'R';
            else if (tecla == 75) direccion = 'L';
        }

        if (direccion == 'U' && y > 0) y--;
        else if (direccion == 'D' && y <= alto) y++;
        else if (direccion == 'R' && x <= ancho) x++;
        else if (direccion == 'L' && x > 0) x--;

        Sleep(100);
    }
}
