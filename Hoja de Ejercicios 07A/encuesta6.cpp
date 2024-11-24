//
// Created by c0d3r on 02/10/2024.
//

#include <iostream>
using namespace std;

void encuesta6()
{
    int edad;
    double peso = 0.0, altura = 0.0;
    char enfermedad_cronica;
    int cantidad_personas_encuestadas = 0;
    double IMC = 0.0;
    int caracteristicas;
    int riesgo_alto = 0, riesgo_medio = 0, riesgo_bajo = 0, sin_riesgo = 0;

    cout << "Ingrese la cantidad de personas a ser encuestadas: ";
    cin >> cantidad_personas_encuestadas;

    for (int i = 1; i <= cantidad_personas_encuestadas; i++)
    {
        cout << endl << "Encuestado #" << i << endl;

        // Ingresar edad
        do
        {
            cout << "Cual es su edad?: ";
            cin >> edad;

            if (edad < 0 || edad > 120)
            {
                cout << "Edad no valida. Intente de nuevo." << endl;
            }
        }
        while (edad < 0 || edad > 120);

        do
        {
            cout << "Sufre de alguna enfermedad cronica? (S/N): ";
            cin >> enfermedad_cronica;
            enfermedad_cronica = toupper(enfermedad_cronica);

            if (enfermedad_cronica != 'S' && enfermedad_cronica != 'N')
            {
                cout << "Respuesta no valida. Intente de nuevo." << endl;
            }
        }
        while (enfermedad_cronica != 'S' && enfermedad_cronica != 'N');

        do
        {
            cout << "Cual es su altura (m)?: ";
            cin >> altura;

            if (altura <= 0)
            {
                cout << "Altura no valida. Intente de nuevo." << endl;
            }
        }
        while (altura <= 0);

        do
        {
            cout << "Cual es su peso (kg)?: ";
            cin >> peso;

            if (peso <= 0)
            {
                cout << "Peso no valido. Intente de nuevo." << endl;
            }
        }
        while (peso <= 0);

        IMC = peso / (altura * altura);

        caracteristicas = 0;

        if (edad > 65) caracteristicas++;
        if (enfermedad_cronica == 'S') caracteristicas++;
        if (IMC >= 30) caracteristicas++;

        if (caracteristicas == 3) riesgo_alto++;
        else if (caracteristicas == 2) riesgo_medio++;
        else if (caracteristicas == 1) riesgo_bajo++;
        else sin_riesgo++;

        cout << "Su IMC es: " << IMC;
        if (caracteristicas == 3) cout << " (Riesgo alto)";
        else if (caracteristicas == 2) cout << " (Riesgo medio)";
        else if (caracteristicas == 1) cout << " (Riesgo bajo)";
        else cout << " (Sin riesgo)";
    } // for

    cout << endl << "ESTADISTICAS" << endl;
    cout << "Riesgo bajo: " << riesgo_bajo << " personas" << endl;
    cout << "Riesgo medio: " << riesgo_medio << " personas" << endl;
    cout << "Riesgo alto: " << riesgo_alto << " personas" << endl;
    cout << "No estan en riesgo: " << sin_riesgo << " personas" << endl;
    cout << "La mayor incidencia de riesgo en la salud es: " << endl;
    int mayor_incidencia = max(riesgo_alto, max(riesgo_medio, max(riesgo_bajo, sin_riesgo)));
    if (mayor_incidencia == riesgo_alto) cout << "Riesgo alto" << endl;
    if (mayor_incidencia == riesgo_medio) cout << "Riesgo medio" << endl;
    if (mayor_incidencia == riesgo_bajo) cout << "Riesgo bajo" << endl;
    if (mayor_incidencia == sin_riesgo) cout << "Sin riesgo" << endl;
}
