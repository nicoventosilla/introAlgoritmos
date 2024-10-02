#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void moverCursor(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void borrarCaracter(int x, int y)
{
    moverCursor(x, y);
    cout << " ";
}

void dibujarCaracter(char caracter, int x, int y)
{
    moverCursor(x, y);
    cout << caracter;
}

void animaciones6()
{
    int x = 0, y = 0;
    int dx = 0, dy = 0;
    int ancho = 10, alto = 5;
    char caracter = '*';

    dibujarCaracter(caracter, x, y);

    while (true)
    {
        if (_kbhit())
        {
            char tecla = _getch();

            if (tecla == 27) break;

            else if (tecla == 72)
            {
                dx = 0;
                dy = -1;
            }
            else if (tecla == 80)
            {
                dx = 0;
                dy = 1;
            }
            else if (tecla == 77)
            {
                dx = 1;
                dy = 0;
            }
            else if (tecla == 75)
            {
                dx = -1;
                dy = 0;
            }
        }

        borrarCaracter(x, y);

        x += dx;
        y += dy;

        if (x < 0) x = 0;
        if (x >= ancho) x = ancho - 1;
        if (y < 0) y = 0;
        if (y >= alto) y = alto - 1;

        dibujarCaracter(caracter, x, y);

        Sleep(100);
    }
}
