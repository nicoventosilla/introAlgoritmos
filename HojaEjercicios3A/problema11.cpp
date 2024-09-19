#include "problema11.h"
#include <iostream>
#include <cstdlib> // Para usar la funcion rand() y srand()
#include <ctime>   // Para usar la funcion time()
using namespace std;

void mostrarRecomendacion(int aqi, double pm25)
{
    if (aqi >= 0 && aqi <= 50 && pm25 >= 0 && pm25 <= 12.0)
    {
        cout << "*** Good air quality ***\n";
        cout << "Air quality is satisfactory and poses little or no risk.\n";
    }
    else if (aqi >= 51 && aqi <= 100 && pm25 > 12.0 && pm25 <= 35.4)
    {
        cout << "*** Moderate air quality ***\n";
        cout <<
            "Sensitive individuals should avoid outdoor activity as they may experience respiratory symptoms.\n";
    }
    else if (aqi >= 101 && aqi <= 150 && pm25 > 35.4 && pm25 <= 55.4)
    {
        cout << "*** Unhealthy for sensitive groups air quality ***\n";
        cout << "General public and sensitive individuals are at risk of irritation and respiratory problems.\n";
    }
    else if (aqi >= 151 && aqi <= 200 && pm25 > 55.4 && pm25 <= 150.4)
    {
        cout << "*** Unhealthy air quality ***\n";;
        cout << "Increased likelihood of adverse effects to heart and lungs.\n";
    }
    else if (aqi >= 201 && aqi <= 300 && pm25 > 150.4 && pm25 <= 250.4)
    {
        cout << "*** Very unhealthy air quality ***\n";
        cout << "General public will be noticeably affected. Sensitive groups should restrict outdoor activity.\n";
    }
    else if (aqi >= 301 && pm25 > 250.4)
    {
        cout << "*** Hazardous air quality ***\n";
        cout << "General public at high risk of experiencing strong irritations and adverse health effects. Should avoid outdoor activities.\n";
    }
    else
    {
        cout << "Valores fuera de los rangos establecidos.\n";
    }
}


void problema11()
{
    int opcion, aqi;
    double pm25;

    // Inicializamos la semilla para generar numeros aleatorios
    srand(static_cast<unsigned int>(time(0)));

    cout << "Deseas ingresar los valores manualmente o generarlos aleatoriamente?" << endl;
    cout << "1. Manual" << endl;
    cout << "2. Aleatorio" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    if (opcion == 1)
    {
        cout << "Ingrese el valor de AQI: ";
        cin >> aqi;
        cout << "Ingrese el valor de PM2.5: ";
        cin >> pm25;
    }
    else if (opcion == 2)
    {
        aqi = rand() % (350 + 1); // Genera un numero aleatorio entre 0 y 350
        pm25 = (rand() % static_cast<int>(300.5 * 10 + 1)) / 10.0; // Genera un numero aleatorio entre 0 y 300.5
        cout << "Valores generados: AQI = " << aqi << ", PM2.5 = " << pm25 << endl;
    }
    else
    {
        cout << "Opcion invalida.\n";
        return;
    }

    mostrarRecomendacion(aqi, pm25);
}
