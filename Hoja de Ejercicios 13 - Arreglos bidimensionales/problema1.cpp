#include "problema1.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
* El Gerente de una importante empresa necesita implementar un control de minutos de llamadas en
su centro comunicaciones.
Al finalizar cada llamada, que en total han sido 50, se debe almacenar lo siguiente: La oficina de la
cual se realiza la llamada (1: Logística; 2: Recursos humanos; 3: Ventas), la cantidad de minutos de
la llamada y el tipo de llamada (1: local; 2: celular; 3: internacional).
Se sabe que una llamada local tiene una tarifa de 0.30 soles por minuto, una llamada a celular 0.80
y una llamada internacional 1.50.
El tiempo máximo de una llamada no excederá los 30 minutos.
Para ello se le pide implementar en C++, un programa que permita:
 Generar una matriz de 50 x 3, donde contenga de forma aleatoria la información de cada
llamada.
 Determinar la oficina u oficinas que tienen la mayor cantidad de minutos en llamadas.
 Determinar por cada tipo de llamada el monto total a pagar. El monto de cada llamada se
calcula como: tiempo de llamada * tarifa.
 Determinar para la oficina de Ventas, el tiempo promedio de llamadas locales, a celular e
internacional.
*/

int generarAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void generarLlamadas(int Llamadas[50][3])
{
    for (int i = 0; i < 50; i++)
    {
        Llamadas[i][0] = generarAleatorio(1, 3); // Oficina
        Llamadas[i][1] = generarAleatorio(1, 30); // Minutos
        Llamadas[i][2] = generarAleatorio(1, 3); // Tipo de llamada
    }
}

void mostrarLlamadas(int Llamadas[50][3])
{
    for (int i = 0; i < 50; i++)
    {
        cout << "Llamada " << i + 1 << ": ";
        cout << "Oficina: " << Llamadas[i][0] << ", ";
        cout << "Minutos: " << Llamadas[i][1] << ", ";
        cout << "Tipo de llamada: " << Llamadas[i][2] << endl;
    }
}

void determinarOficinaMayorMinutos(int Llamadas[50][3])
{
    // 1: Logistica; 2: Recursos humanos; 3: Ventas
    int minutosLogistica = 0;
    int minutosRecursosHumanos = 0;
    int minutosVentas = 0;

    for (int i = 0; i < 50; i++) // Recorrer todas las llamadas
    {
        if (Llamadas[i][0] == 1) // Si la llamada es de Logistica
        {
            minutosLogistica += Llamadas[i][1]; // Sumar los minutos de la llamada a Logistica
        }
        else if (Llamadas[i][0] == 2) // Si la llamada es de Recursos Humanos
        {
            minutosRecursosHumanos += Llamadas[i][1]; // Sumar los minutos de la llamada a Recursos Humanos
        }
        else if (Llamadas[i][0] == 3) // Si la llamada es de Ventas
        {
            minutosVentas += Llamadas[i][1]; // Sumar los minutos de la llamada a Ventas
        }
    }

    // Mostrar los minutos de cada oficina
    cout << "Minutos Logistica: " << minutosLogistica << endl;
    cout << "Minutos Recursos Humanos: " << minutosRecursosHumanos << endl;
    cout << "Minutos Ventas: " << minutosVentas << endl;

    // Determinar la oficina con mayor cantidad de minutos
    if (minutosLogistica > minutosRecursosHumanos && minutosLogistica > minutosVentas)
    {
        cout << "La oficina con mayor cantidad de minutos es Logistica" << endl;
    }
    else if (minutosRecursosHumanos > minutosLogistica && minutosRecursosHumanos > minutosVentas)
    {
        cout << "La oficina con mayor cantidad de minutos es Recursos Humanos" << endl;
    }
    else if (minutosVentas > minutosLogistica && minutosVentas > minutosRecursosHumanos)
    {
        cout << "La oficina con mayor cantidad de minutos es Ventas" << endl;
    }
    else
    {
        cout << "Hay empate en la cantidad de minutos" << endl;
    }
}

void determinarMontoTotalPagar(int Llamadas[50][3])
{
    // 1: local; 2: celular; 3: internacional
    float montoLocal = 0;
    float montoCelular = 0;
    float montoInternacional = 0;

    for (int i = 0; i < 50; i++) // Recorrer todas las llamadas
    {
        if (Llamadas[i][2] == 1) // Si la llamada es local
        {
            montoLocal += Llamadas[i][1] * 0.30; // Sumar el monto de la llamada local
        }
        else if (Llamadas[i][2] == 2) // Si la llamada es a celular
        {
            montoCelular += Llamadas[i][1] * 0.80; // Sumar el monto de la llamada a celular
        }
        else if (Llamadas[i][2] == 3) // Si la llamada es internacional
        {
            montoInternacional += Llamadas[i][1] * 1.50; // Sumar el monto de la llamada internacional
        }
    }

    // Mostrar los montos totales a pagar
    cout << "Monto total a pagar por llamadas locales: " << montoLocal << endl;
    cout << "Monto total a pagar por llamadas a celular: " << montoCelular << endl;
    cout << "Monto total a pagar por llamadas internacionales: " << montoInternacional << endl;
}

void determinarTiempoPromedioLlamadas(int Llamadas[50][3])
{
    // 1: local; 2: celular; 3: internacional
    int cantidadLocales = 0;
    int cantidadCelulares = 0;
    int cantidadInternacionales = 0;
    int minutosLocales = 0;
    int minutosCelulares = 0;
    int minutosInternacionales = 0;

    for (int i = 0; i < 50; i++) // Recorrer todas las llamadas
    {
        if (Llamadas[i][0] == 3) // Si la llamada es de Ventas
        {
            if (Llamadas[i][2] == 1) // Si la llamada es local
            {
                cantidadLocales++; // Aumentar la cantidad de llamadas locales
                minutosLocales += Llamadas[i][1]; // Sumar los minutos de la llamada local
            }
            else if (Llamadas[i][2] == 2) // Si la llamada es a celular
            {
                cantidadCelulares++; // Aumentar la cantidad de llamadas a celular
                minutosCelulares += Llamadas[i][1]; // Sumar los minutos de la llamada a celular
            }
            else if (Llamadas[i][2] == 3) // Si la llamada es internacional
            {
                cantidadInternacionales++; // Aumentar la cantidad de llamadas internacionales
                minutosInternacionales += Llamadas[i][1]; // Sumar los minutos de la llamada internacional
            }
        }
    }

    // Mostrar el tiempo promedio de llamadas de Ventas
    cout << "Tiempo promedio de llamadas locales de Ventas: " << (float)minutosLocales / cantidadLocales << endl; // Convertir a float para obtener decimales
    cout << "Tiempo promedio de llamadas a celular de Ventas: " << (float)minutosCelulares / cantidadCelulares << endl;
    cout << "Tiempo promedio de llamadas internacionales de Ventas: " << (float)minutosInternacionales /
        cantidadInternacionales << endl;
}

void problema1()
{
    srand(time(0));

    int Llamadas[50][3]; // 50 llamadas, 3 datos por llamada

    generarLlamadas(Llamadas); // Generar llamadas aleatorias
    mostrarLlamadas(Llamadas); // Mostrar llamadas
    determinarOficinaMayorMinutos(Llamadas); // Determinar oficina con mayor cantidad de minutos
    determinarMontoTotalPagar(Llamadas); // Determinar monto total a pagar
    determinarTiempoPromedioLlamadas(Llamadas); // Determinar tiempo promedio de llamadas de Ventas
}
