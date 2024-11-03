```cpp
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

void borrarCursor(int x, int y)
{
	moverCursor(x, y);
	cout << " ";
}

void dibujar(char c, int x, int y)
{
	moverCursor(x, y);
	cout << c;
}

int main()
{
	char c = '*';
	int x = 0, y = 0;
	int dx = 1, dy = 1;
	int ancho = 80, alto = 25;

	dibujar(c, x, y);

	while (true)
	{
		if (_kbhit())
		{
			char tecla = _getch();

			borrarCursor(x, y);

			switch (tecla)
			{
			case 27:
				return 0;
			case 72:
				if (y - dy >= 0) y -= dy;
				break;
			case 80:
				if (y + dy < alto) y += dy;
				break;
			case 75:
				if (x - dx >= 0) x -= dx;
				break;
			case 77:
				if (x + dx < ancho) x += dx;
				break;
			}

			dibujar(c, x, y);
		}

		Sleep(50);
	}
}
```