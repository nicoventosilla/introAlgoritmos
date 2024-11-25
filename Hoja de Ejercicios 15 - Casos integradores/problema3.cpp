//
// Created by c0d3r on 24/11/2024.
//

#include "problema3.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
*3. El Gerente de una importante empresa necesita implementar un control sobre el consumo en llamadas y
mensajes de texto de los celulares que tienen asignados un grupo de vendedores de la empresa.
De cada vendedor, que en total son 30, se debe almacenar la siguiente información: su código, los minutos de
llamadas a un teléfono fijo, los minutos de llamadas a celulares y la cantidad de mensajes de texto enviados.
Todos los celulares pertenecen a un mismo plan, el cual les permite 20 minutos de llamadas a teléfono fijo, 40
minutos a celulares y 20 mensajes de texto.
Se sabe que el exceso de minutos de llamadas o mensajes de texto, sobre lo permitido en el plan, tiene un
costo el cual es de 0.35 soles por minuto para teléfono fijo, 0.45 soles por minuto para celular y 0.20 soles por
mensaje de texto.
Para ello se le pide implementar en Lenguaje C, un programa que permita:
 Generar un vector de 30 elementos que contenga los códigos de los vendedores. Se sabe que los códigos
de los vendedores empezarán en el valor 201.
 Generar una matriz de 30 x 3, que contenga de forma aleatoria la información de los minutos de llamadas
a fijo y celulares así como el número de mensajes de texto de cada vendedor.
 Determinar el código o códigos de los vendedores que tienen la mayor cantidad de minutos de llamadas
a celulares.
 Determinar por cada vendedor el monto total a pagar por el exceso en el consumo. El monto se calcula
como: ∑excesos * tarifas.
 Determinar el tiempo promedio de llamadas a fijo, el tiempo promedio de llamadas a celular y promedio
de mensajes enviados.
 */

const int NUM_VENDEDORES = 30; // Número de vendedores
const int LLAMADAS_FIJO = 0; // Índice de llamadas a teléfono fijo
const int LLAMADAS_CELULAR = 1; // Índice de llamadas a celular
const int MENSAJES_TEXTO = 2; // Índice de mensajes de texto
const int LIMITE_FIJO = 20; // Límite de minutos de llamadas a teléfono fijo
const int LIMITE_CELULAR = 40; // Límite de minutos de llamadas a celular
const int LIMITE_MENSAJES = 20; // Límite de mensajes de texto
const double COSTO_FIJO = 0.35; // Costo por minuto de llamadas a teléfono fijo
const double COSTO_CELULAR = 0.45; // Costo por minuto de llamadas a celular
const double COSTO_MENSAJES = 0.20; // Costo por mensaje de texto

// Generar códigos de vendedores
void generarCodigosVendedores(int CodigosVendedores[])
{
    cout << "Generando codigos de vendedores..." << endl;

    for (int i = 0; i < NUM_VENDEDORES; i++)
    {
        CodigosVendedores[i] = 201 + i; // Generar códigos de vendedores (201 a 230)
    }
}

// Generar datos de vendedores
void generarDatosVendedores(int DatosVendedores[][3])
{
    cout << "Generando datos de vendedores..." << endl;

    for (int i = 0; i < NUM_VENDEDORES; i++)
    {
        DatosVendedores[i][LLAMADAS_FIJO] = rand() % 41; // Generar minutos de llamadas a teléfono fijo (0 a 40)
        DatosVendedores[i][LLAMADAS_CELULAR] = rand() % 91; // Generar minutos de llamadas a celular (0 a 90)
        DatosVendedores[i][MENSAJES_TEXTO] = rand() % 41; // Generar mensajes de texto (0 a 40)
    }
}

// Mostrar datos de vendedores
void mostrarDatosVendedores(int CodigosVendedores[], int DatosVendedores[][3])
{
    cout << "Codigo\tLlamadas Fijo\tLlamadas Celular\tMensajes Texto" << endl; // Encabezado
    for (int i = 0; i < NUM_VENDEDORES; i++) // Recorrer los vendedores
    {
        cout << CodigosVendedores[i] << "\t" // Mostrar código del vendedor
            << DatosVendedores[i][LLAMADAS_FIJO] << "\t\t" // Mostrar minutos de llamadas a teléfono fijo
            << DatosVendedores[i][LLAMADAS_CELULAR] << "\t\t\t" // Mostrar minutos de llamadas a celular
            << DatosVendedores[i][MENSAJES_TEXTO] << endl; // Mostrar mensajes de texto
    }
}

// Determinar el código o códigos de los vendedores que tienen la mayor cantidad de minutos de llamadas a celulares
void determinarVendedoresConMayorLlamadasACelulares(int CodigosVendedores[], int DatosVendedores[][3])
{
    cout << "Determinando vendedores con mayor cantidad de llamadas a celulares..." << endl;

    int mayorLlamadasCelulares = 0; // Mayor cantidad de llamadas a celulares

    // Recorremos la matriz de datos de vendedores para encontrar el mayor número de llamadas a celulares
    for (int i = 0; i < NUM_VENDEDORES; i++)
    {
        if (DatosVendedores[i][LLAMADAS_CELULAR] > mayorLlamadasCelulares) // Si la cantidad de llamadas a celulares es mayor
        {
            mayorLlamadasCelulares = DatosVendedores[i][LLAMADAS_CELULAR]; // Actualizar mayor cantidad de llamadas a celulares
        }
    }

    cout << "Vendedores con mayor cantidad de llamadas a celulares (" << mayorLlamadasCelulares << " minutos): ";

    // Recorremos la matriz de datos de vendedores para encontrar los vendedores con la mayor cantidad de llamadas a celulares
    for (int i = 0; i < NUM_VENDEDORES; i++)
    {
        if (DatosVendedores[i][LLAMADAS_CELULAR] == mayorLlamadasCelulares) // Si la cantidad de llamadas a celulares es igual a la mayor cantidad
        {
            cout << CodigosVendedores[i] << " "; // Mostrar código del vendedor
        }
    }
    cout << endl;
}

// Determinar el monto total a pagar por el exceso en el consumo de cada vendedor
void determinarMontoTotalAPagarPorExceso(int CodigosVendedores[], int DatosVendedores[][3])
{
    cout << "Determinando monto total a pagar por exceso en el consumo..." << endl;

    for (int i = 0; i < NUM_VENDEDORES; i++)
    {
        double montoTotal = 0; // Monto total a pagar por el exceso en el consumo

        int excesoFijo = DatosVendedores[i][LLAMADAS_FIJO] - LIMITE_FIJO; // Calcular exceso de minutos de llamadas a teléfono fijo
        int excesoCelular = DatosVendedores[i][LLAMADAS_CELULAR] - LIMITE_CELULAR; // Calcular exceso de minutos de llamadas a celular
        int excesoMensajes = DatosVendedores[i][MENSAJES_TEXTO] - LIMITE_MENSAJES; // Calcular exceso de mensajes de texto

        if (excesoFijo > 0) // Si hay exceso de minutos de llamadas a teléfono fijo
        {
            montoTotal += excesoFijo * COSTO_FIJO; // Calcular monto total a pagar por el exceso de minutos de llamadas a teléfono fijo
        }

        if (excesoCelular > 0) // Si hay exceso de minutos de llamadas a celular
        {
            montoTotal += excesoCelular * COSTO_CELULAR; // Calcular monto total a pagar por el exceso de minutos de llamadas a celular
        }

        if (excesoMensajes > 0) // Si hay exceso de mensajes de texto
        {
            montoTotal += excesoMensajes * COSTO_MENSAJES; // Calcular monto total a pagar por el exceso de mensajes de texto
        }

        cout << "Vendedor " << CodigosVendedores[i] << " debe pagar: " << montoTotal << " soles" << endl;
    }
}

// Determinar el tiempo promedio de llamadas a fijo, el tiempo promedio de llamadas a celular y promedio de mensajes enviados
void determinarTiemposPromedio(int DatosVendedores[][3])
{
    cout << "Determinando tiempos promedio de llamadas a fijo, llamadas a celular y mensajes enviados..." << endl;

    double promedioFijo = 0; // Promedio de minutos de llamadas a teléfono fijo
    double promedioCelular = 0; // Promedio de minutos de llamadas a celular
    double promedioMensajes = 0; // Promedio de mensajes de texto

    for (int i = 0; i < NUM_VENDEDORES; i++)
    {
        promedioFijo += DatosVendedores[i][LLAMADAS_FIJO]; // Sumar minutos de llamadas a teléfono fijo
        promedioCelular += DatosVendedores[i][LLAMADAS_CELULAR]; // Sumar minutos de llamadas a celular
        promedioMensajes += DatosVendedores[i][MENSAJES_TEXTO]; // Sumar mensajes de texto
    }

    promedioFijo /= NUM_VENDEDORES; // Calcular promedio de minutos de llamadas a teléfono fijo
    promedioCelular /= NUM_VENDEDORES; // Calcular promedio de minutos de llamadas a celular
    promedioMensajes /= NUM_VENDEDORES; // Calcular promedio de mensajes de texto

    cout << "Promedio de minutos de llamadas a fijo: " << promedioFijo << endl;
    cout << "Promedio de minutos de llamadas a celular: " << promedioCelular << endl;
    cout << "Promedio de mensajes de texto: " << promedioMensajes << endl;
}

void problema3() // int main()
{
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios

    int CodigosVendedores[NUM_VENDEDORES]; // Vector o arreglo de códigos de vendedores
    int DatosVendedores[NUM_VENDEDORES][3]; // Matriz de datos de vendedores

    generarCodigosVendedores(CodigosVendedores); // Generar códigos de vendedores
    generarDatosVendedores(DatosVendedores); // Generar datos de vendedores
    mostrarDatosVendedores(CodigosVendedores, DatosVendedores); // Mostrar datos de vendedores
    determinarVendedoresConMayorLlamadasACelulares(CodigosVendedores, DatosVendedores); // Determinar vendedores con mayor cantidad de llamadas a celulares
    determinarMontoTotalAPagarPorExceso(CodigosVendedores, DatosVendedores); // Determinar monto total a pagar por exceso en el consumo
}
