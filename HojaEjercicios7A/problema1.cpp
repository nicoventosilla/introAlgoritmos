//
// Created by c0d3r on 30/09/2024.
//

#include "problema1.h"
#include <iostream>
#include <limits>
using namespace std;

void problema1()
{
    int edad, adultos_mayores = 0;
    char sexo, plataforma, satisfaccion;
    int suma_edades_canvas = 0, contador_canvas = 0;
    int contador_bueno = 0, contador_regular = 0, contador_malo = 0;
    int edad_mujer_mas_joven = 0;
    bool existe_mujer_mas_joven = false;

    while (true)
    {
        // Ingresar edad
        do
        {
            cout << "Ingrese su edad: ";
            cin >> edad;

            if (edad == 0) break;
            if (edad >= 60) adultos_mayores++;
        }
        while (edad < 17 || edad > 65);

        // Salir del bucle si la edad es 0
        if (edad == 0) break;

        // Ingresar sexo
        do
        {
            cout << "Sexo (F: femenino; M: masculino): ";
            cin >> sexo;
            sexo = toupper(sexo);

            if (sexo != 'F' && sexo != 'M')
            {
                cout << "Sexo no válido. Intente de nuevo." << endl;
            }
        }
        while (sexo != 'F' && sexo != 'M');

        // Ingresar plataforma
        do
        {
            cout << "Plataforma LMS (B: Blackboard; C: Canvas; M: Moodle): ";
            cin >> plataforma;
            plataforma = toupper(plataforma);

            if (plataforma != 'B' && plataforma != 'C' && plataforma != 'M')
            {
                cout << "Plataforma no valida. Intente de nuevo." << endl;
            }
            else if (plataforma == 'C')
            {
                contador_canvas++;
                suma_edades_canvas += edad;
            }
            else if (plataforma != 'M' && sexo == 'F')
            {
                if (edad < edad_mujer_mas_joven) edad_mujer_mas_joven = edad;
                existe_mujer_mas_joven = true;
            }
        }
        while (plataforma != 'B' && plataforma != 'C' && plataforma != 'M');

        // Ingresar satisfacción
        do
        {
            cout << "Nivel de satisfaccion (B: bueno; R: regular; M: malo): ";
            cin >> satisfaccion;
            satisfaccion = toupper(satisfaccion);

            if (satisfaccion != 'B' && satisfaccion != 'R' && satisfaccion != 'M')
            {
                cout << "Nivel de satisfacción no válido. Intente de nuevo." << endl;
            }
            else if (satisfaccion == 'B') contador_bueno++;
            else if (satisfaccion == 'R') contador_regular++;
            else if (satisfaccion == 'M') contador_malo++;
        }
        while (satisfaccion != 'B' && satisfaccion != 'R' && satisfaccion != 'M');
    } // end while

    cout << endl << "RESULTADOS" << endl;
    cout << "Cuantos estudiantes son adultos mayores: " << adultos_mayores << endl;

    // Promedio de edad de los estudiantes que usan Canvas
    cout << "Promedio de edad de los estudiantes que usan Canvas: ";
    if (contador_canvas > 0) cout << static_cast<double>(suma_edades_canvas) / contador_canvas << endl;
    else cout << "No hay estudiantes que usen Canvas." << endl;

    // Nivel de satisfacción menos frecuente
    int menor_frecuencia = min(contador_bueno, min(contador_regular, contador_malo));
    cout << "Nivel de satisfaccion menos frecuente: " << endl;

    if (menor_frecuencia == contador_bueno) cout << "Bueno" << endl;
    if (menor_frecuencia == contador_regular) cout << "Regular" << endl;
    if (menor_frecuencia == contador_malo) cout << "Malo" << endl;

    if (existe_mujer_mas_joven)
    {
        cout << "Edad de la mujer más joven que no usa Moodle: " << edad_mujer_mas_joven << endl;
    }
    else cout << "No hay mujeres que no usen Moodle." << endl;
} // end problema1
