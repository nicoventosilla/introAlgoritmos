#include "problema13.h"
#include <iostream>
#include <string>
using namespace std;

char elegirDispositivo()
{
    char dispositivo;
    do
    {
        cout << "Ingrese dispositivo (C: Celular, T: Tablet, O: Otros): ";
        cin >> dispositivo;

        if (dispositivo != 'C' && dispositivo != 'c' && dispositivo != 'T' && dispositivo != 't' && dispositivo != 'O'
            && dispositivo != 'o')
        {
            cout << "Dispositivo incorrecto, intente de nuevo" << endl;
        }
    }
    while (dispositivo != 'C' && dispositivo != 'c' && dispositivo != 'T' && dispositivo != 't' && dispositivo != 'O' &&
        dispositivo != 'o');

    return dispositivo;
}

void problema13()
{
    char fabricante, tipo_programa, dispositivo;
    double precio = 0;

    do
    {
        cout << "Ingrese fabricante de software (M: Microsoft, A: Apple, L: Linux): ";
        cin >> fabricante;

        if (fabricante != 'M' && fabricante != 'm' && fabricante != 'A' && fabricante != 'a' && fabricante != 'L' &&
            fabricante != 'l')
        {
            cout << "Fabricante incorrecto, intente de nuevo" << endl;
        }
    }
    while (fabricante != 'M' && fabricante != 'm' && fabricante != 'A' && fabricante != 'a' && fabricante != 'L' &&
        fabricante != 'l');

    do
    {
        cout << "Ingrese tipo de programa (S: Sistema Operativo, L: Lenguaje de programacion): ";
        cin >> tipo_programa;

        if (tipo_programa != 'S' && tipo_programa != 's' && tipo_programa != 'L' && tipo_programa != 'l')
        {
            cout << "Tipo de programa incorrecto, intente de nuevo" << endl;
        }
    }
    while (tipo_programa != 'S' && tipo_programa != 's' && tipo_programa != 'L' && tipo_programa != 'l');

    // Microsoft
    if (fabricante == 'M' || fabricante == 'm')
    {
        if (tipo_programa == 'S' || tipo_programa == 's')
        {
            precio = 1500;
        }
        else if (tipo_programa == 'L' || tipo_programa == 'l')
        {
            dispositivo = elegirDispositivo();
            if (dispositivo == 'C' || dispositivo == 'c')
            {
                precio = 1800;
            }
            else if (dispositivo == 'T' || dispositivo == 't')
            {
                precio = 1200;
            }
            else if (dispositivo == 'O' || dispositivo == 'o')
            {
                precio = 900;
            }
        }
    }
    // Apple
    else if (fabricante == 'A' || fabricante == 'a')
    {
        if (tipo_programa == 'S' || tipo_programa == 's')
        {
            precio = 2500;
        }
        else if (tipo_programa == 'L' || tipo_programa == 'l')
        {
            dispositivo = elegirDispositivo();
            if (dispositivo == 'C' || dispositivo == 'c')
            {
                precio = 1900;
            }
            else if (dispositivo == 'T' || dispositivo == 't')
            {
                precio = 1800;
            }
            else if (dispositivo == 'O' || dispositivo == 'o')
            {
                precio = 1600;
            }
        }
    }
    // Linux
    else if (fabricante == 'L' || fabricante == 'l')
    {
        if (tipo_programa == 'S' || tipo_programa == 's')
        {
            precio = 1000;
        }
        else if (tipo_programa == 'L' || tipo_programa == 'l')
        {
            dispositivo = elegirDispositivo();
            if (dispositivo == 'C' || dispositivo == 'c')
            {
                precio = 100;
            }
            else if (dispositivo == 'T' || dispositivo == 't')
            {
                precio = 150;
            }
            else if (dispositivo == 'O' || dispositivo == 'o')
            {
                precio = 50;
            }
        }
    }

    cout << "El precio del programa es: " << precio << endl;
}
