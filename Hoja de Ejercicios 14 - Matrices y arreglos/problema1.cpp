#include "problema1.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int contador_capicua = 0;

int generarNumeroAleatorio(int min, int max) // Generar un numero aleatorio entre min y max
{
    return rand() % (max - min + 1) + min;
}

void Generar_Mensaje(int* Mensajes, int longitud_mensaje) // Generar un mensaje aleatorio
{
    for (int i = 0; i < longitud_mensaje; ++i)
    {
        Mensajes[i] = generarNumeroAleatorio(0, 9);
    }
}

void Imprimir_Mensaje(int* Mensajes, int longitud_mensaje) // Imprimir el mensaje
{
    for (int i = 0; i < longitud_mensaje; ++i)
    {
        cout << Mensajes[i] << " ";
    }
    cout << endl;
}

void Existe_capicua(int* Mensajes, int longitud_mensaje) // Verificar si existe un capicua
{
    bool esCapicua4 = (Mensajes[longitud_mensaje - 4] == Mensajes[longitud_mensaje - 1]) &&
        (Mensajes[longitud_mensaje - 3] == Mensajes[longitud_mensaje - 2]);

    bool esCapicua3_der = (Mensajes[longitud_mensaje - 3] == Mensajes[longitud_mensaje - 1]) &&
        (Mensajes[longitud_mensaje - 3] == Mensajes[longitud_mensaje - 2]);;

    bool esCapicua3_izq = (Mensajes[longitud_mensaje - 4] == Mensajes[longitud_mensaje - 2]) &&
        (Mensajes[longitud_mensaje - 4] == Mensajes[longitud_mensaje - 3]);

    if (esCapicua4 || esCapicua3_der || esCapicua3_izq)
    {
        contador_capicua++;

        cout << "Capicua Encontrado" << endl;

        if (contador_capicua == 5)
        {
            cout << "CONTACTO" << endl;
        }
    }
}

void problema1() // int main()
{
    srand(time(0)); // Semilla para generar numeros aleatorios

    int mensajes_generados = 0;

    while (contador_capicua < 5)
    {
        int longitud_mensaje = generarNumeroAleatorio(10, 15); // Generar un numero aleatorio entre 10 y 15

        int* Mensajes = new int[longitud_mensaje]; // Crear un arreglo dinamico

        mensajes_generados++;
        cout << "Mensajes generados: " << mensajes_generados << endl;

        Generar_Mensaje(Mensajes, longitud_mensaje);
        Imprimir_Mensaje(Mensajes, longitud_mensaje);
        Existe_capicua(Mensajes, longitud_mensaje);

        delete[] Mensajes; // Liberar memoria
    }
}
