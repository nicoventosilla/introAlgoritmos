//
// Created by c0d3r on 24/11/2024.
//

#include "problema2.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
* Pregunta 2
Control de Consumo y Facturación en una Empresa de Ventas
Una empresa de ventas desea implementar un sistema avanzado de control y facturación del consumo de llamadas y
mensajes de texto para sus 40 vendedores. Para cada vendedor, se debe almacenar la siguiente información:

Código del vendedor (empezando en el valor 301).
Minutos de llamadas a un teléfono fijo en cada uno de los últimos tres meses.
Minutos de llamadas a celulares en cada uno de los últimos tres meses.
Cantidad de mensajes de texto enviados en cada uno de los últimos tres meses.

El plan de telefonía asignado a cada vendedor incluye lo siguiente:
* 60 minutos de llamadas a teléfono fijo al mes.
* 120 minutos de llamadas a celular al mes.
* 50 mensajes de texto al mes.
*
Si un vendedor excede cualquiera de estos límites mensuales, se aplican los siguientes costos adicionales por mes:
* 0.40 soles por cada minuto de exceso en llamadas a teléfono fijo.
* 0.50 soles por cada minuto de exceso en llamadas a celulares.
* 0.25 soles por cada mensaje de texto adicional.
*
Se debe implementar un programa en Lenguaje C++ que realice las siguientes tareas:
• Generar y mostrar un vector de 40 elementos con los códigos de los vendedores, comenzando desde 301.
• Generar y llenar una matriz de 40 x 9 de forma aleatoria con la información de minutos de llamadas a fijo,
minutos de llamadas a celular y mensajes de texto enviados para cada uno de los tres meses, de modo que
cada fila corresponda a un vendedor y cada columna a un dato específico.
• Calcular y mostrar el código del vendedor con el mayor total de minutos de llamadas a celular acumulados
en los tres meses.
• Calcular y mostrar el costo total a pagar por exceso de consumo para cada vendedor en los tres meses,
detallando el monto adicional por tipo de consumo (fijo, celular, mensajes). Sumar todos los excesos
mensuales y multiplicar por sus respectivas tarifas.
• Determinar el promedio mensual de minutos de llamadas a fijo, minutos de llamadas a celular, y mensajes de
texto enviados para todos los vendedores. Mostrar estos promedios de forma mensual y acumulada
(promedio general en los tres meses).
• Mostrar el listado de los códigos de los vendedores ordenado en forma descendente según el costo total de
exceso, de modo que los vendedores con mayores costos por excesos aparezcan primero.
• Identificar y mostrar los vendedores que no incurrieron en ningún exceso en los tres meses, es decir, que
estuvieron siempre dentro de los límites del plan mensual en llamadas y mensajes.
*/

int generarAleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void generarVectorCodigosVendedores(int VectorCodigosVendedores[])
{
    for (int i = 0; i < 40; i++)
    {
        VectorCodigosVendedores[i] = 301 + i;
    }
}

void mostrarVector(int Vector[])
{
    for (int i = 0; i < 40; i++)
    {
        cout << Vector[i] << " ";
    }
    cout << endl;
}

void generarMatriz(int Matriz[40][9])
{
    // Recorrer cada vendedor (fila)
    for (int i = 0; i < 40; i++)
    {
        // Recorrer cada mes (3 meses)
        for (int j = 0; j < 3; j++)
        {
            // Generar minutos aleatorios para llamadas a teléfono fijo (0 a 60)
            Matriz[i][j] = generarAleatorio(0, 70);
            // Generar minutos aleatorios para llamadas a celular (0 a 120)
            Matriz[i][j + 3] = generarAleatorio(0, 130);
            // Generar número aleatorio de mensajes de texto enviados (0 a 50)
            Matriz[i][j + 6] = generarAleatorio(0, 60);
        }
    }
}

void mostrarMatriz(int Matriz[40][9])
{
    cout << "Vendedor\tFijo1\tFijo2\tFijo3\tCel1\tCel2\tCel3\tMsg1\tMsg2\tMsg3" << endl;

    for (int i = 0; i < 40; i++)
    {
        cout << "Vendedor " << i + 301 << ":\t";
        for (int j = 0; j < 9; j++)
        {
            cout << Matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

void mostrarVendedorConMayorTotalMinutosCelular(int Matriz[40][9])
{
    int mayorTotalMinutosCelular = 0;
    int codigoVendedorMayorTotalMinutosCelular = 0;

    for (int i = 0; i < 40; i++)
    {
        int totalMinutosCelular = Matriz[i][3] + Matriz[i][4] + Matriz[i][5];
        if (totalMinutosCelular > mayorTotalMinutosCelular)
        {
            mayorTotalMinutosCelular = totalMinutosCelular;
            codigoVendedorMayorTotalMinutosCelular = i + 301;
        }
    }

    cout << "Vendedor con mayor total de minutos de llamadas a celular acumulados en los tres meses ("
        << mayorTotalMinutosCelular << " minutos): " << codigoVendedorMayorTotalMinutosCelular << endl;
}

void calcularYMostrarCostoExceso(int Matriz[40][9])
{
    const double TARIFA_FIJO = 0.40;
    const double TARIFA_CELULAR = 0.50;
    const double TARIFA_MENSAJES = 0.25;

    for (int i = 0; i < 40; i++)
    {
        double costoExcesoFijo = 0;
        double costoExcesoCelular = 0;
        double costoExcesoMensajes = 0;

        for (int j = 0; j < 3; j++)
        {
            int excesoFijo = 0;
            if (Matriz[i][j] > 60)
            {
                excesoFijo = Matriz[i][j] - 60;
            }

            int excesoCelular = 0;
            if (Matriz[i][j + 3] > 120)
            {
                excesoCelular = Matriz[i][j + 3] - 120;
            }

            int excesoMensajes = 0;
            if (Matriz[i][j + 6] > 50)
            {
                excesoMensajes = Matriz[i][j + 6] - 50;
            }

            costoExcesoFijo += excesoFijo * TARIFA_FIJO;
            costoExcesoCelular += excesoCelular * TARIFA_CELULAR;
            costoExcesoMensajes += excesoMensajes * TARIFA_MENSAJES;
        }

        double costoTotal = costoExcesoFijo + costoExcesoCelular + costoExcesoMensajes;

        cout << "Vendedor " << i + 301 << ":" << endl;
        cout << "  Costo por exceso en llamadas a fijo: " << costoExcesoFijo << " soles" << endl;
        cout << "  Costo por exceso en llamadas a celular: " << costoExcesoCelular << " soles" << endl;
        cout << "  Costo por exceso en mensajes de texto: " << costoExcesoMensajes << " soles" << endl;
        cout << "  Costo total por exceso: " << costoTotal << " soles" << endl;
    }
}

void calcularYMostrarPromedios(int Matriz[40][9])
{
    double promedioFijo = 0;
    double promedioCelular = 0;
    double promedioMensajes = 0;

    for (int i = 0; i < 40; i++)
    {
        promedioFijo += Matriz[i][0] + Matriz[i][1] + Matriz[i][2];
        promedioCelular += Matriz[i][3] + Matriz[i][4] + Matriz[i][5];
        promedioMensajes += Matriz[i][6] + Matriz[i][7] + Matriz[i][8];
    }

    promedioFijo /= 40;
    promedioCelular /= 40;
    promedioMensajes /= 40;

    cout << "Promedio de minutos de llamadas a fijo: " << promedioFijo << endl;
    cout << "Promedio de minutos de llamadas a celular: " << promedioCelular << endl;
    cout << "Promedio de mensajes de texto: " << promedioMensajes << endl;
}

void mostrarVendedoresOrdenadosPorCostoExceso(int Matriz[40][9])
{
    const double TARIFA_FIJO = 0.40;
    const double TARIFA_CELULAR = 0.50;
    const double TARIFA_MENSAJES = 0.25;

    int codigosVendedores[40];
    double costosVendedores[40];

    for (int i = 0; i < 40; i++)
    {
        double costoExcesoFijo = 0;
        double costoExcesoCelular = 0;
        double costoExcesoMensajes = 0;

        for (int j = 0; j < 3; j++)
        {
            int excesoFijo = 0;
            if (Matriz[i][j] > 60)
            {
                excesoFijo = Matriz[i][j] - 60;
            }

            int excesoCelular = 0;
            if (Matriz[i][j + 3] > 120)
            {
                excesoCelular = Matriz[i][j + 3] - 120;
            }

            int excesoMensajes = 0;
            if (Matriz[i][j + 6] > 50)
            {
                excesoMensajes = Matriz[i][j + 6] - 50;
            }

            costoExcesoFijo += excesoFijo * TARIFA_FIJO;
            costoExcesoCelular += excesoCelular * TARIFA_CELULAR;
            costoExcesoMensajes += excesoMensajes * TARIFA_MENSAJES;
        }

        double costoTotal = costoExcesoFijo + costoExcesoCelular + costoExcesoMensajes;
        codigosVendedores[i] = 301 + i;
        costosVendedores[i] = costoTotal;
    }

    // Ordenar los vendedores por costo total de exceso en orden descendente
    for (int i = 0; i < 40 - 1; i++)
    {
        for (int j = i + 1; j < 40; j++)
        {
            if (costosVendedores[i] < costosVendedores[j])
            {
                swap(costosVendedores[i], costosVendedores[j]);
                swap(codigosVendedores[i], codigosVendedores[j]);
            }
        }
    }

    cout << "Listado de vendedores ordenado por costo total de exceso (de mayor a menor):" << endl;
    for (int i = 0; i < 40; i++)
    {
        cout << "Vendedor " << codigosVendedores[i] << ": " << costosVendedores[i] << " soles" << endl;
    }
}

void mostrarVendedoresSinExcesos(int Matriz[40][9])
{
    cout << "Vendedores que no incurrieron en ningun exceso en los tres meses:" << endl;

    for (int i = 0; i < 40; i++)
    {
        int mesesSinExceso = 0;

        for (int j = 0; j < 3; j++)
        {
            if (Matriz[i][j] <= 60 && Matriz[i][j + 3] <= 120 && Matriz[i][j + 6] <= 50)
            {
                mesesSinExceso++;
            }
        }

        if (mesesSinExceso == 3)
        {
            cout << "Vendedor " << i + 301 << endl;
        }
    }
}

void problema2() // int main()
{
    srand(time(0));

    // Generar y mostrar un vector de 40 elementos con los códigos de los vendedores, comenzando desde 301.
    int VectorCodigosVendedores[40];

    generarVectorCodigosVendedores(VectorCodigosVendedores);

    cout << "Vector de codigos de vendedores: ";
    mostrarVector(VectorCodigosVendedores);

    // Generar y llenar una matriz de 40 x 9 de forma aleatoria con los datos de minutos de llamadas a fijo, minutos de llamadas a celular y mensajes de texto enviados para cada uno de los tres meses.
    int Matriz[40][9]; // 40 vendedores, 9 datos por vendedor (3 meses x 3 datos por mes)

    generarMatriz(Matriz);
    mostrarMatriz(Matriz);

    // Calcular y mostrar el código del vendedor con el mayor total de minutos de llamadas a celular acumulados en los tres meses.
    mostrarVendedorConMayorTotalMinutosCelular(Matriz);

    // Calcular y mostrar el costo total a pagar por exceso de consumo para cada vendedor en los tres meses.
    // Detallar el monto adicional por tipo de consumo (fijo, celular, mensajes).
    // Sumar todos los excesos mensuales y multiplicar por sus respectivas tarifas.
    calcularYMostrarCostoExceso(Matriz);

    // Determinar el promedio mensual de minutos de llamadas a fijo, minutos de llamadas a celular, y mensajes de texto enviados para todos los vendedores.
    // Mostrar estos promedios de forma mensual y acumulada (promedio general en los tres meses).
    calcularYMostrarPromedios(Matriz);

    // Mostrar el listado de los códigos de los vendedores ordenado en forma descendente según el costo total de exceso.
    // De modo que los vendedores con mayores costos por excesos aparezcan primero.
    mostrarVendedoresOrdenadosPorCostoExceso(Matriz);

    // Identificar y mostrar los vendedores que no incurrieron en ningún exceso en los tres meses.
    // Es decir, que estuvieron siempre dentro de los límites del plan mensual en llamadas y mensajes.
    mostrarVendedoresSinExcesos(Matriz);
}
