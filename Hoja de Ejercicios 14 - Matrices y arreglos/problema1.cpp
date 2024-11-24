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
    for (int i = 0; i < longitud_mensaje; ++i) // Recorrer el mensaje
    {
        Mensajes[i] = generarNumeroAleatorio(0, 9); // Generar un numero aleatorio entre 0 y 9
    }
}

void Imprimir_Mensaje(int* Mensajes, int longitud_mensaje) // Imprimir el mensaje
{
    for (int i = 0; i < longitud_mensaje; ++i) // Recorrer el mensaje
    {
        cout << Mensajes[i] << " "; // Mostrar el mensaje
    }
    cout << endl;
}

void Existe_capicua(int* Mensajes, int longitud_mensaje) // Verificar si existe un capicua
{
    bool esCapicua4 = (Mensajes[longitud_mensaje - 4] == Mensajes[longitud_mensaje - 1]) &&
        (Mensajes[longitud_mensaje - 3] == Mensajes[longitud_mensaje - 2]);
    // Verificar si es capicua de 4 digitos (abcd)

    bool esCapicua3_der = (Mensajes[longitud_mensaje - 3] == Mensajes[longitud_mensaje - 1]) &&
        (Mensajes[longitud_mensaje - 3] == Mensajes[longitud_mensaje - 2]);
    // Verificar si es capicua de 3 digitos (abc) en la derecha

    bool esCapicua3_izq = (Mensajes[longitud_mensaje - 4] == Mensajes[longitud_mensaje - 2]) &&
        (Mensajes[longitud_mensaje - 4] == Mensajes[longitud_mensaje - 3]);
    // Verificar si es capicua de 3 digitos (abc) en la izquierda

    if (esCapicua4 || esCapicua3_der || esCapicua3_izq) // Si es capicua de 4 digitos o 3 digitos
    {
        contador_capicua++; // Aumentar el contador de capicuas

        cout << "Capicua Encontrado" << endl; // Mostrar que se encontro un capicua

        if (contador_capicua == 5) // Si se encontraron 5 capicuas
        {
            cout << "CONTACTO" << endl; // Mostrar CONTACTO
        }
    }
}

void problema1() // int main()
{
    srand(time(0)); // Semilla para generar numeros aleatorios

    int mensajes_generados = 0; // Contador de mensajes generados

    while (contador_capicua < 5) // Mientras no se encuentren 5 capicuas
    {
        const int longitud_mensaje = generarNumeroAleatorio(10, 15); // Generar un numero aleatorio entre 10 y 15

        int Mensajes[longitud_mensaje]; // Crear un arreglo en la pila

        mensajes_generados++; // Aumentar el contador de mensajes generados
        cout << "Mensajes generados: " << mensajes_generados << endl; // Mostrar la cantidad de mensajes generados

        Generar_Mensaje(Mensajes, longitud_mensaje);
        Imprimir_Mensaje(Mensajes, longitud_mensaje);
        Existe_capicua(Mensajes, longitud_mensaje);
    }
}
