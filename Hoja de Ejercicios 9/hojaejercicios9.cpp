//
// Created by c0d3r on 12/10/2024.
//

#include "hojaejercicios9.h"
#include "problema1.h"
#include "problema2.h"
// #include "problema3.h"
// #include "problema4.h"
// #include "problema5.h"
#include <iostream>
using namespace std;

void mostrarMenu()
{
    cout << "1. Problema 1" << endl;
    cout << "2. Problema 2" << endl;
    // cout << "3. Problema 3" << endl;
    // cout << "4. Problema 4" << endl;
    // cout << "5. Problema 5" << endl;
    cout << "0. Salir" << endl;
}

int main()
{
    int opcion;

    mostrarMenu();

    cout << "Ingrese su opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        problema1();
        break;
    case 2:
        problema2();
        break;
    // case 3:
    //     problema3();
    //     break;
    // case 4:
    //     problema4();
    //     break;
    // case 5:
    //     problema5();
    //     break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
}
