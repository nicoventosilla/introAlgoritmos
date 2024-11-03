```cpp
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <thread>
using namespace std;

void moverCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para dibujar el nuevo carácter
void dibujarCaracter(int x, int y) {
    moverCursor(x, y);
    cout << "*";
    this_thread::sleep_for(chrono::milliseconds(50));
}

// Función principal
int main()
{
    int limite_superior = 0, limite_izquierdo = 0;
    int limite_inferior = 20, limite_derecho = 50;
    int x, y;

    while (true)
    {
        for (x = limite_izquierdo; x <= limite_derecho; x++)
        {
            dibujarCaracter(x, limite_superior);
        }
        for (y = limite_superior + 1; y < limite_inferior; y++)
        {
            dibujarCaracter(limite_derecho, y);
        }
        for (x = limite_derecho; x >= limite_izquierdo; x--)
        {
            dibujarCaracter(x, limite_inferior);
        }
        for (y = limite_inferior; y > limite_superior; y--)
        {
            dibujarCaracter(limite_izquierdo, y);
        }

        limite_superior += 1;
        limite_izquierdo += 1;
        limite_derecho -= 1;
        limite_inferior -= 1;

        // Detener el bucle cuando los límites se cruzan
        if (limite_superior >= limite_inferior || limite_izquierdo >= limite_derecho) {
            break;
        }
    }

    return 0;
}
```