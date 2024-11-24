#include <iostream> // Para usar cout
#include <windows.h> // Para usar SetConsoleCursorPosition
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
    this_thread::sleep_for(chrono::milliseconds(100));
}

// Función principal
int main()
{
    int alto = 10, ancho = 20;
    int x, y;

    while (true)
    {
        for (x = 0; x <= ancho; x++)
        {
            dibujarCaracter(x, 0);
        }
        for (y = 1; y < alto; y++)
        {
            dibujarCaracter(ancho, y);
        }
        for (x = ancho; x >= 0; x--)
        {
            dibujarCaracter(x, alto);
        }
        for (y = alto; y > 0; y--)
        {
            dibujarCaracter(0, y);
        }

        break;
    }

    return 0;
}
