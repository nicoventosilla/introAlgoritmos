//
// Created by c0d3r on 30/09/2024.
//

#include "encuesta2.h"
#include <iostream>
using namespace std;

void encuesta2()
{
    int edad;
    char sexo, tipo_prueba, resultado_prueba;
    int cantidad_total_pacientes = 0, cantidad_pacientes_18_40 = 0;
    int suma_edades_antigenos = 0, contador_pacientes_antigenos = 0;
    int contador_pcr = 0, contador_serologica = 0, contador_antigenos = 0;
    int edad_hombre_mas_joven = 100;
    bool existe_hombre_mas_joven = false;

    while (true)
    {
        // Ingresar edad
        do
        {
            cout << "Ingrese su edad: ";
            cin >> edad;

            if (edad == -100) break;
            else if (edad < 15 || edad > 90)
            {
                cout << "Edad no valida. Intente de nuevo." << endl;
            }
            else if (edad >= 18 && edad <= 40)
            {
                cantidad_pacientes_18_40++;
            }
        }
        while (edad < 15 || edad > 90);

        if (edad == -100) break;

        cantidad_total_pacientes++;

        // Ingresar sexo
        do
        {
            cout << "Sexo (F: femenino; M: masculino): ";
            cin >> sexo;
            sexo = toupper(sexo);

            if (sexo != 'F' && sexo != 'M')
            {
                cout << "Sexo no valido. Intente de nuevo." << endl;
            }
        }
        while (sexo != 'F' && sexo != 'M');

        // Ingresar tipo de prueba
        do
        {
            cout << "Tipo de Prueba (P: PCR; A: Antigenos; S: Serologica): ";
            cin >> tipo_prueba;
            tipo_prueba = toupper(tipo_prueba);

            if (tipo_prueba != 'P' && tipo_prueba != 'A' && tipo_prueba != 'S')
            {
                cout << "Tipo de prueba no valido. Intente de nuevo." << endl;
            }
            else if (tipo_prueba == 'A') // Antigenos
            {
                suma_edades_antigenos += edad;
                contador_pacientes_antigenos++;
            }
            else if (tipo_prueba == 'P') contador_pcr++;
            else if (tipo_prueba == 'S') contador_serologica++;
            else if (tipo_prueba == 'A') contador_antigenos++;
        }
        while (tipo_prueba != 'P' && tipo_prueba != 'A' && tipo_prueba != 'S');

        // Ingresar resultado de la prueba
        do
        {
            cout << "Resultado de la prueba (P: positivo; N: negativo): ";
            cin >> resultado_prueba;
            resultado_prueba = toupper(resultado_prueba);

            if (resultado_prueba != 'P' && resultado_prueba != 'N')
            {
                cout << "Resultado de la prueba no valido. Intente de nuevo." << endl;
            }
            else if (sexo == 'M' && tipo_prueba == 'P' && resultado_prueba == 'N')
            {
                if (edad < edad_hombre_mas_joven) edad_hombre_mas_joven = edad;
                existe_hombre_mas_joven = true;
            }
        }
        while (resultado_prueba != 'P' && resultado_prueba != 'N');
    } // end while

    cout << "RESULTADOS" << endl;
    cout << "Porcentaje de pacientes entre 18 y 40 anios que se han realizado una prueba: " << endl;
    cout << (cantidad_pacientes_18_40 * 100) / cantidad_total_pacientes << "%" << endl;
    cout << "Promedio de edad de los pacientes que se han realizado la prueba de Antigenos: " << endl;
    cout << static_cast<double>(suma_edades_antigenos) / contador_pacientes_antigenos << endl;
    cout << "Tipos de prueba que tienen la mayor frecuencia: " << endl;
    int prueba_mayor_frecuencia = max(contador_pcr, max(contador_serologica, contador_antigenos));
    if (prueba_mayor_frecuencia == contador_pcr) cout << "PCR" << endl;
    if (prueba_mayor_frecuencia == contador_serologica) cout << "Serologica" << endl;
    if (prueba_mayor_frecuencia == contador_antigenos) cout << "Antigenos" << endl;
    cout << "Edad del hombre mas joven con resultado negativo en la prueba PCR: " << endl;
    if (existe_hombre_mas_joven) cout << edad_hombre_mas_joven << endl;
    else cout << "No hubo." << endl;
}
