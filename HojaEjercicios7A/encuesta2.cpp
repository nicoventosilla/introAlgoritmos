//
// Created by c0d3r on 30/09/2024.
//

#include "encuesta2.h"
#include <iostream>
using namespace std;

void encuesta2()
{
    int edad;
    char sexo;

    while (true)
    {
        // Ingresar edad
        do
        {
            cout << "Ingrese su edad: ";
            cin >> edad;

            if (edad == -100) break;
        }
        while (edad < 15 || edad > 90);

        if (edad == -100) break;

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
    }
}
