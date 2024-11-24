//
// Created by c0d3r on 23/11/2024.
//

#include "problema3.h"
#include <iostream>
#include <ctime> // Libreria para el uso de time
#include <cstdlib> // Libreria para el uso de rand

using namespace std;

/**
*3. Una empresa automotriz tiene cinco agencias y cuenta con la información acerca de las ventas
mensuales de automóviles logradas el año pasado por cada una de éstas. A partir de esta
información la empresa construyó la siguiente matriz ventas:

            Agencia 1 Agencia 2 Agencia 3 Agencia 4 Agencia 5
Enero
Febrero
...
Diciembre

Donde cada fila representa un mes y cada columna una agencia.

Se le solicita a usted que elabore un programa en C++ que permita lo siguiente:
a) Registrar la información de las ventas por mes de cada una de las agencias.
b) Mostrar en pantalla el resumen de ventas de cada agencia.
c) Mostrar cuál fue el total de ventas en el año de la Agencia 3.
d) Mostar el promedio de ventas en el mes de diciembre.
e) Mostrar el número de la agencia que tuvo mayores ventas en el mes de mayo.
f) Indicar en qué mes se registraron las menores ventas del año, considerando todas las agencias.
 */

int generarNumerosAleatorios(int min, int max) // Generar un numero aleatorio entre min y max
{
    return rand() % (max - min + 1) + min; // Formula para generar un numero aleatorio entre min y max
}

void generarMatriz(int Matriz[12][5])
{
    for (int i = 0; i < 12; i++) // Recorrer filas
    {
        for (int j = 0; j < 5; j++) // Recorrer columnas
        {
            Matriz[i][j] = generarNumerosAleatorios(1000, 10000); // Ventas aleatorias entre 1000 y 10000
        }
    }
}

void mostrarVentasAgencias(int Ventas[12][5])
{
    const char* meses[12] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre",
        "Diciembre"
    };
    cout << "            Agencia 1  Agencia 2  Agencia 3  Agencia 4  Agencia 5" << endl;
    for (int i = 0; i < 12; i++) // Recorrer filas (Meses)
    {
        cout << meses[i] << " ";
        for (int j = 0; j < 5; j++) // Recorrer columnas (Agencias)
        {
            cout << "    " << Ventas[i][j] << "    ";
        }
        cout << endl;
    }
}

void mostrarResumenVentasAgencias(int Ventas[12][5])
{
    for (int i = 0; i < 5; i++) // Recorrer columnas (Agencias)
    {
        int totalVentas = 0;
        for (int j = 0; j < 12; j++) // Recorrer filas (Meses)
        {
            totalVentas += Ventas[j][i]; // Sumar las ventas de cada mes
        }
        cout << "Total de ventas de la Agencia " << i + 1 << ": " << totalVentas << endl;
        // Mostrar el total de ventas de la agencia
    }
}

void mostrarVentasAgencia3(int Ventas[12][5])
{
    int totalVentasAgencia3 = 0;
    for (int i = 0; i < 12; i++) // Recorrer filas (Meses)
    {
        totalVentasAgencia3 += Ventas[i][2]; // Sumar las ventas de la Agencia 3
    }

    cout << "Total de ventas en el anio de la Agencia 3: " << totalVentasAgencia3 << endl;
}

void mostrarPromedioDiciembre(int Ventas[12][5])
{
    int totalVentasDiciembre = 0;
    for (int i = 0; i < 5; i++) // Recorrer columnas (Agencias)
    {
        totalVentasDiciembre += Ventas[11][i]; // Sumar las ventas de cada agencia en diciembre
    }
    cout << "Promedio de ventas en el mes de diciembre: " << totalVentasDiciembre / 5 << endl;
}

void mostrarVentasAgenciaMayo(int Ventas[12][5])
{
    int mayorVentasMayo = Ventas[4][0]; // Inicializar con las ventas de la Agencia 1
    int numeroAgencia = 1; // Inicializar con el número de la Agencia 1
    for (int i = 1; i < 5; i++) // Recorrer columnas (Agencias)
    {
        if (Ventas[4][i] > mayorVentasMayo) // Si las ventas de la agencia son mayores
        {
            mayorVentasMayo = Ventas[4][i]; // Actualizar las ventas
            numeroAgencia = i + 1; // Actualizar el número de la agencia
        }
    }
    cout << "La agencia con mayores ventas en el mes de mayo es la Agencia " << numeroAgencia << endl;
}

void mostrarMesMenoresVentas(int Ventas[12][5])
{
    int menorVentas = Ventas[0][0]; // Inicializar con las ventas de la Agencia 1 en enero
    int mesMenorVentas = 1; // Inicializar con el mes de enero
    for (int i = 0; i < 12; i++) // Recorrer filas (Meses)
    {
        for (int j = 0; j < 5; j++) // Recorrer columnas (Agencias)
        {
            if (Ventas[i][j] < menorVentas) // Si las ventas son menores
            {
                menorVentas = Ventas[i][j]; // Actualizar las ventas
                mesMenorVentas = i + 1; // Actualizar el mes
            }
        }
    }
    cout << "El mes con menores ventas del anio es el mes " << mesMenorVentas << endl;
}

void problema3()
{
    // Inicializar la semilla para los numeros aleatorios
    srand(time(0));

    // Generar matriz de 12 x 5
    int Ventas[12][5];

    // Ingresar las ventas de cada mes y agencia
    generarMatriz(Ventas);

    // Mostrar las ventas de cada agencia
    mostrarVentasAgencias(Ventas);

    // Mostrar en pantalla el resumen de ventas de cada agencia
    mostrarResumenVentasAgencias(Ventas);

    // Mostrar cuál fue el total de ventas en el año de la Agencia 3
    mostrarVentasAgencia3(Ventas);

    // Mostrar el promedio de ventas en el mes de diciembre
    mostrarPromedioDiciembre(Ventas);

    // Mostrar el número de la agencia que tuvo mayores ventas en el mes de mayo
    mostrarVentasAgenciaMayo(Ventas);

    // Indicar en qué mes se registraron las menores ventas del año, considerando todas las agencias
    mostrarMesMenoresVentas(Ventas);
}
