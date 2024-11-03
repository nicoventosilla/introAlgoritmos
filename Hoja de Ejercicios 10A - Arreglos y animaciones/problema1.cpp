//
// Created by c0d3r on 01/11/2024.
//
#include "problema1.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

void ocultarCursor() // Funcion para ocultar el cursor de la consola
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

int* generarCoordenadaX(int candidadFiguras) // Genera las coordenadas X de las figuras
{
    int* cordX = new int[candidadFiguras];

    for (int i = 0; i < candidadFiguras; i++)
    {
        cordX[i] = i;
    }

    return cordX;
}

int* generarCoordenadaY(int candidadFiguras) // Genera las coordenadas Y de las figuras
{
    int* cordY = new int[candidadFiguras];

    for (int i = 0; i < candidadFiguras; i++)
    {
        cordY[i] = 0;
    }

    return cordY;
}

int* generarVelocidadY(int candidadFiguras) // Genera la velocidad de las figuras
{
    int* velocidad = new int[candidadFiguras];

    for (int i = 0; i < candidadFiguras; i++)
    {
        velocidad[i] = 1; // Velocidad de cada figura
    }

    return velocidad;
}

int* generaColor(int candidadFiguras) // Genera el color de las figuras
{
    int* color = new int[candidadFiguras];

    for (int i = 0; i < candidadFiguras; i++)
    {
        color[i] = rand() % 15 + 1; // Genera un color aleatorio entre 1 y 15
    }

    return color;
}

void imprimirFigura(int x, int y, char caracter, int color) // Imprime la figura en la consola
{
    HANDLE Consola = GetStdHandle(STD_OUTPUT_HANDLE); // Obtiene el handle de la consola
    SetConsoleTextAttribute(Consola, color); // Cambia el color de la consola
    COORD coord; // Estructura que almacena las coordenadas X y Y
    coord.X = x; // Coordenada X
    coord.Y = y; // Coordenada Y

    SetConsoleCursorPosition(Consola, coord); // Cambia la posición del cursor
    cout << caracter; // Imprime el caracter
}

void problema1() // Principal
{
    srand(time(0)); // Semilla aleatoria
    ocultarCursor(); // Oculta el cursor

    int largo = 40;
    int ancho = 20;

    int cantidadFiguras = largo; // Cantidad de figuras

    int* cordX = generarCoordenadaX(cantidadFiguras); // Genera las coordenadas X
    int* cordY = generarCoordenadaY(cantidadFiguras); // Genera las coordenadas Y
    int* color = generaColor(cantidadFiguras); // Genera los colores
    int* velocidad = generarVelocidadY(cantidadFiguras); // Genera las velocidades

    while (!_kbhit())
    {
        // Mientras no se presione una tecla

        for (int i = 0; i < cantidadFiguras; i++)
        {
            // Recorre todas las figuras

            imprimirFigura(cordX[i], cordY[i], ' ', color[i]); // Borra la figura

            if (cordY[i] + velocidad[i] < ancho) // Si la figura no llega al final
                cordY[i] = cordY[i] + velocidad[i]; // Aumenta la velocidad
            else
                cordY[i] = 0; // Vuelve a la posición inicial

            imprimirFigura(cordX[i], cordY[i], '*', color[i]); // Imprime la figura
        }

        Sleep(100); // 100 milisegundos
    }

    delete[] cordX; // Libera la memoria
    delete[] cordY; // Libera la memoria
    delete[] color; // Libera la memoria
    delete[] velocidad; // Libera la memoria
}
