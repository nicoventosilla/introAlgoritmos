//
// Created by c0d3r on 29/09/2024.
//

#include "problema13.h"
#include <iostream>
#include <cmath>
using namespace std;


string convertirBase2(int numero)
{
    if (numero == 0) return "0";

    string resultado;
    while (numero > 0)
    {
        resultado = to_string(numero % 2) + resultado;
        numero /= 2;
    }
    return resultado;
}

string convertirBase3(int numero)
{
    if (numero == 0) return "0";

    string resultado;
    while (numero > 0)
    {
        resultado = to_string(numero % 3) + resultado;
        numero /= 3;
    }
    return resultado;
}

string convertirBase4(int numero)
{
    if (numero == 0) return "0";

    string resultado;
    while (numero > 0)
    {
        resultado = to_string(numero % 4) + resultado;
        numero /= 4;
    }
    return resultado;
}

string convertirBase5(int numero)
{
    if (numero == 0) return "0";

    string resultado;

    while (numero > 0)
    {
        resultado = to_string(numero % 5) + resultado;
        numero /= 5;
    }
    return resultado;
}

string convertirBase6(int numero)
{
    if (numero == 0) return "0";

    string resultado;
    while (numero > 0)
    {
        resultado = to_string(numero % 6) + resultado;
        numero /= 6;
    }
    return resultado;
}

void problema13()
{
    char letra_nombre, letra_apellido;
    int edad, anio_nacimiento;
    double peso, estatura;
    int peso_decimales = 0, estatura_decimales = 0;

    cout << "Ingrese primera letra del nombre: ";
    cin >> letra_nombre;

    cout << "Ingrese primera letra del apellido: ";
    cin >> letra_apellido;

    do
    {
        cout << "Ingrese la edad: ";
        cin >> edad;

        if (edad < 16 || edad > 31)
        {
            cout << "La edad debe estar entre 16 y 31" << endl;
        }
    }
    while (edad < 16 || edad > 31);

    do
    {
        cout << "Ingrese el anio de nacimiento: ";
        cin >> anio_nacimiento;

        if (anio_nacimiento < 2000 || anio_nacimiento > 2010)
        {
            cout << "El anio de nacimiento debe estar entre 2000 y 2010" << endl;
        }
    }
    while (anio_nacimiento < 2000 || anio_nacimiento > 2010);

    do
    {
        cout << "Ingrese el peso en kg: ";
        cin >> peso;

        if (peso >= 40 && peso <= 100)
        {
            if (peso != floor(peso))
            {
                double parte_decimal = peso - floor(peso);
                peso_decimales = static_cast<int>(parte_decimal * 100);
            }
            else
            {
                cout << "El peso debe tener 2 decimales" << endl;
            }
        }
        else
        {
            cout << "El peso debe estar entre 40 y 100" << endl;
        }
    }
    while (peso < 40 || peso > 100);

    do
    {
        cout << "Ingrese la estatura en m: ";
        cin >> estatura;

        if (estatura >= 1.50 && estatura <= 1.90)
        {
            if (estatura != floor(estatura))
            {
                double parte_decimal = estatura - floor(estatura);
                estatura_decimales = static_cast<int>(parte_decimal * 100);
            }
        }
        else
        {
            cout << "La estatura debe estar entre 1.50 y 1.90" << endl;
        }
    }
    while (estatura < 1.50 || estatura > 1.90);

    string letra_nombre_base2 = convertirBase2(static_cast<int>(letra_nombre));
    string letra_apellido_base3 = convertirBase3(static_cast<int>(letra_apellido));
    string edad_base2 = convertirBase2(edad);
    string anio_nacimiento_base4 = convertirBase4(anio_nacimiento);
    string peso_base5 = convertirBase5(peso_decimales);
    string estatura_base6 = convertirBase6(estatura_decimales);

    cout << "Datos encriptados: " << endl;
    cout << letra_nombre_base2 << " ";
    cout << letra_apellido_base3 << " ";
    cout << edad_base2 << " ";
    cout << anio_nacimiento_base4 << " ";
    cout << peso_base5 << " ";
    cout << estatura_base6 << endl;
}
