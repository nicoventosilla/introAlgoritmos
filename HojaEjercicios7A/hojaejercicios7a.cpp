//
// Created by c0d3r on 28/09/2024.
//

#include "hojaejercicios7a.h"
#include "encuesta1.h"
// #include "encuesta2.h"
// #include "encuesta3.h"
// #include "encuesta4.h"
// #include "encuesta5.h"
// #include "encuesta6.h"
#include "figuras1.h"
#include "figuras2.h"
#include "figuras3.h"
// #include "figuras4.h"
// #include "figuras5.h"
// #include "figuras6.h"
#include <iostream>
using namespace std;

void mostrarMenu()
{
    cout << "1. encuesta1" << endl;
    // cout << "2. encuesta2" << endl;
    // cout << "3. encuesta3" << endl;
    // cout << "4. encuesta4" << endl;
    // cout << "5. encuesta5" << endl;
    // cout << "6. encuesta6" << endl;
    cout << "7. figuras1" << endl;
    cout << "8. figuras2" << endl;
    cout << "9. figuras3" << endl;
    // cout << "10. figuras4" << endl;
    // cout << "11. figuras5" << endl;
    // cout << "12. figuras6" << endl;
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
        encuesta1();
        break;
    // case 2:
    //     encuesta2();
    //     break;
    // case 3:
    //     encuesta3();
    //     break;
    // case 4:
    //     encuesta4();
    //     break;
    // case 5:
    //     encuesta5();
    //     break;
    // case 6:
    //     encuesta6();
    //     break;
    case 7:
        figuras1();
        break;
    case 8:
        figuras2();
        break;
    case 9:
        figuras3();
        break;
    // case 10:
    //     figuras4();
    //     break;
    // case 11:
    //     figuras5();
    //     break;
    // case 12:
    //     figuras6();
    //     break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
}
