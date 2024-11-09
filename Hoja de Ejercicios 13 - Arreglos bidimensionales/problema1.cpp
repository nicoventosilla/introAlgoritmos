#include "problema1.h"
#include <iostream>

using namespace std;

// Constantes para el número de llamadas, columnas, oficinas y tipos de llamadas
const int num_llamadas = 50;
const int num_columnas = 3;
const int num_oficina = 3;
const int num_tipo_llamada = 3;

// Constantes para el costo de cada tipo de llamada
const float costo_llamada_local = 0.3;
const float costo_llamada_celular = 0.8;
const float costo_llamada_internacional = 1.5;

// Función para generar números aleatorios en un rango dado
int numAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void problema1()
{
    // Crear una matriz dinámica para almacenar las llamadas
    int** llamadas = new int*[num_llamadas];

    for (int i = 0; i < num_llamadas; i++)
    {
        llamadas[i] = new int[num_columnas];
    }

    // Llenar la matriz con datos aleatorios
    for (int i = 0; i < num_llamadas; i++)
    {
        llamadas[i][0] = numAleatorio(1, num_oficina); // Oficina
        llamadas[i][1] = numAleatorio(1, 30); // Minutos
        llamadas[i][2] = numAleatorio(1, num_tipo_llamada); // Tipo de llamada
    }

    // Array para almacenar los minutos por oficina
    int minutosPorOficina[num_oficina] = {0};

    // Calcular los minutos totales por oficina
    for (int i = 0; i < num_llamadas; i++)
    {
        int oficina = llamadas[i][0] - 1;
        int minutos = llamadas[i][1];

        minutosPorOficina[oficina] += minutos;
    }

    // Encontrar la oficina con el mayor número de minutos
    int maxMinutos = 0;

    cout << "La oficina y oficinas con mayor cantidad de minutos en llamadas: " << endl;

    for (int i = 0; i < num_oficina; i++)
    {
        if (minutosPorOficina[i] == maxMinutos)
        {
            cout << "Oficina: " << (i + 1) << " - " << maxMinutos << " minutos.";
        }
    }

    // Variables para almacenar el monto total por tipo de llamada
    float montoTotalLocal = 0.0;
    float montoTotalCelular = 0.0;
    float montoTotalInternacional = 0.0;

    // Calcular el monto total a pagar por cada tipo de llamada
    for (int i = 0; i < num_llamadas; i++)
    {
        int minutos = llamadas[i][1];
        int tipoLlamada = llamadas[i][2];

        switch (tipoLlamada)
        {
        case 1:
            montoTotalLocal += minutos * costo_llamada_local;
            break;
        case 2:
            montoTotalCelular += minutos * costo_llamada_celular;
            break;
        case 3:
            montoTotalInternacional += minutos * costo_llamada_internacional;
            break;
        }
    }

    // Mostrar el monto total a pagar por cada tipo de llamada
    cout << endl << "Monto total a pagar por llamada: " << endl;
    cout << "Llamadas locales: " << montoTotalLocal << endl;
    cout << "Llamadas a celular: " << montoTotalCelular << endl;
    cout << "Llamadas internacionales: " << montoTotalInternacional << endl;

    // Variables para almacenar la cantidad y el tiempo total de llamadas por tipo en la oficina 3
    int cantidadLlamadaLocal = 0;
    int cantidadLlamadaCelular = 0;
    int cantidadLlamadaInternacional = 0;

    float totalTiempoLocal = 0.0;
    float totalTiempoCelular = 0.0;
    float totalTiempoInternacional = 0.0;

    // Calcular el tiempo promedio de llamadas por tipo en la oficina 3
    for (int i = 0; i < num_llamadas; i++)
    {
        if (llamadas[i][0] == 3)
        {
            int minutos = llamadas[i][1];
            int tipoLlamada = llamadas[i][2];

            switch (tipoLlamada)
            {
            case 1:
                totalTiempoLocal += minutos;
                cantidadLlamadaLocal++;
                break;
            case 2:
                totalTiempoCelular += minutos;
                cantidadLlamadaCelular++;
                break;
            case 3:
                totalTiempoInternacional += minutos;
                cantidadLlamadaInternacional++;
                break;
            default:
                break;
            }
        } // Fin del if
    } // Fin del for

    // Mostrar el tiempo promedio de llamadas por tipo en la oficina 3
    if (cantidadLlamadaLocal > 0)
    {
        cout << endl << "Tiempo promedio de llamadas locales en ventas: " << totalTiempoLocal / cantidadLlamadaLocal <<
            endl;
    }

    if (cantidadLlamadaCelular > 0)
    {
        cout << "Tiempo promedio de llamadas a celular en ventas: " << totalTiempoCelular / cantidadLlamadaCelular <<
            endl;
    }

    if (cantidadLlamadaInternacional > 0)
    {
        cout << "Tiempo promedio de llamadas internacionales en ventas: " << totalTiempoInternacional /
            cantidadLlamadaInternacional << endl;
    }

    // Liberar la memoria dinámica
    for (int i = 0; i < num_llamadas; i++)
    {
        delete[] llamadas[i];
    }

    delete[] llamadas;
}
