Se verifica en cada carácter

```cpp
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void moverCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void borrarCaracter(int x, int y) {
    moverCursor(x, y);
    cout << " ";
}

void dibujarCaracter(char caracter, int x, int y) {
    moverCursor(x, y);
    cout << caracter;
}

int main() {
    char caracter = '*';
    int x = 2, y = 2;
    int dx = 0, dy = 0;
    int ancho = 10, alto = 5;

    dibujarCaracter(caracter, x, y);

    while (true) {
        if (_kbhit()) {
            char tecla = _getch();

            if (tecla == 27) {
                break;
            }

            switch (tecla) {
            case 72:  // Flecha arriba
                dx = 0;  // No cambiar en x
                dy = -1; // Moverse hacia arriba
                break;
            case 80:  // Flecha abajo
                dx = 0;
                dy = 1;  // Moverse hacia abajo
                break;
            case 75:  // Flecha izquierda
                dx = -1; // Moverse hacia la izquierda
                dy = 0;
                break;
            case 77:  // Flecha derecha
                dx = 1;  // Moverse hacia la derecha
                dy = 0;
                break;
            }
        }

        borrarCaracter(x, y);

        // Actualizar la posición del carácter con el movimiento
        x += dx;
        y += dy;

        // Evitar que se salga de la pantalla
        if (x < 0) x = 0;
        if (x >= ancho) x = ancho - 1;
        if (y < 0) y = 0;
        if (y >= alto) y = alto - 1;

        // Dibujar el carácter en la nueva posición
        dibujarCaracter(caracter, x, y);

        // Pausar brevemente para controlar la velocidad del movimiento
        Sleep(100);
    }

    return 0;
}
```