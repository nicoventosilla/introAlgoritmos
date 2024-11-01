//
// Created by c0d3r on 19/10/2024.
//

#include "problema2.h"
#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

void mostrar_menu() // Función que muestra el menú principal
{
    cout << "MENU PRINCIPAL" << endl;
    cout << "1) Determinar el factorial de un numero" << endl;
    cout << "2) Calcular el valor de ea" << endl;
    cout << "3) Imprime rombo" << endl;
    cout << "4) Salir" << endl;
}

long double Factorial(int numero) // Función que calcula el factorial de un número
{
    long double factorial = 1;

    for (int i = 1; i <= numero; i++)
    {
        factorial *= i;
    }

    return factorial;
}

void funcion_factorial() // Función que solicita un número al usuario y muestra su factorial
{
    int numero;

    do
    {
        cout << "Ingrese un numero: ";
        cin >> numero;
    }
    while (numero < 0);

    long double factorial = Factorial(numero);

    cout << "El factorial de " << numero << " es " << factorial << endl;
    system("pause");
}

void calcular_ea() // Función que calcula el valor de ea
{
    int k;
    double a;

    do
    {
        cout << "Ingrese el valor de k (debe ser menor o igual a 20): ";
        cin >> k;

        if (k < 0 || k > 20)
        {
            cout << "El valor de k debe ser menor o igual a 20." << endl;
        }
    }
    while (k < 0 || k > 20);

    do
    {
        cout << "Ingrese el valor de a (debe ser mayor a 0): ";
        cin >> a;

        if (a <= 0)
        {
            cout << "El valor de a debe ser mayor a 0." << endl;
        }
    }
    while (a <= 0);

    long double resultado = 1.0;

    for (int n = 1; n <= k; n++)
    {
        resultado += (pow(a, n) / Factorial(n));
    }

    cout << "El valor de ea es " << resultado << endl;
    system("pause");
}

void imprimir_rombo() // Función que imprime un rombo
{
    int n;

    do
    {
        cout << "Introduce un numero entre 1 y 5: ";
        cin >> n;

        if (n < 1 || n > 5)
        {
            cout << "Numero no valido. Intentalo de nuevo." << endl;
        }
    }
    while (n < 1 || n > 5);

    int largo = n * 2;
    int limite = -1;
    int espacios = n;

    for (int j = 1; j < largo; j++)
    {
        if (j <= n) espacios -= 1;
        else espacios += 1;

        for (int i = 0; i < espacios; i++)
        {
            cout << " ";
        }

        if (j <= n) limite += 2;
        else limite -= 2;

        for (int i = 1; i <= limite; i++)
        {
            cout << i;
        }
        cout << endl;
    }
    system("pause");
}

void problema2()
{
    char opcion;

    while (true)
    {
        system("cls");
        mostrar_menu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case '1':
            funcion_factorial();
            break;
        case '2':
            calcular_ea();
            break;
        case '3':
            imprimir_rombo();
            break;
        default:
            cout << "Opción no valida. Intente de nuevo." << endl;
            break;
        }
    }
}
