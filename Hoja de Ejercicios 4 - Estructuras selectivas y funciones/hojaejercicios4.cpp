//
// Created by c0d3r on 17/09/2024.
//

#include <locale>
#include "hojaejercicios4.h"
#include "problema2.h"
#include "problema3.h"
#include "problema4.h"
#include "problema5.h"
#include "problema7.h"
#include "problema8.h"
#include "problema12.h"
#include "problema13.h"
#include "problema14.h"
#include "problema15.h"
#include "problema16.h"
#include <iostream>
using namespace std;

void mostrarMenu()
{
    // cout << "1. Problema 1" << endl;
    cout << "2. Problema 2" << endl;
    cout << "3. Problema 3" << endl;
    cout << "4. Problema 4" << endl;
    cout << "5. Problema 5" << endl;
    cout << "7. Problema 7" << endl;
    cout << "8. Problema 8" << endl;
    cout << "12. Problema 12" << endl;
    cout << "13. Problema 13" << endl;
    cout << "14. Problema 14" << endl;
    cout << "15. Problema 15" << endl;
    cout << "16. Problema 16" << endl;
    cout << "0. Salir" << endl;
}

int main()
{
    // Configurar la localización para usar UTF-8
    setlocale(LC_ALL, "en_US.UTF-8");

    int opcion;

    mostrarMenu();

    cout << "Ingrese su opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 2:
        problema2();
        break;
    case 3:
        problema3();
        break;
    case 4:
        problema4();
        break;
    case 5:
        problema5();
        break;
    case 7:
        problema7();
        break;
    case 8:
        problema8();
        break;
    case 12:
        problema12();
        break;
    case 13:
        problema13();
        break;
    case 14:
        problema14();
        break;
    case 15:
        problema15();
        break;
    case 16:
        problema16();
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
}