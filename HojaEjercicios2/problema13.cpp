//
// Created by c0d3r on 11/09/2024.
//

#include "problema13.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;


void problema13()
{
    string codigo, NN, PP, AA, HH, MM, SS;
    char llego_tarde = 'F';

    cout << "Ingrese codigo del empleado: ";
    cin >> codigo;

    NN = codigo.substr(0, 2);
    PP = codigo.substr(2, 2);
    AA = codigo.substr(4, 2);
    HH = codigo.substr(6, 2);
    MM = codigo.substr(8, 2);
    SS = codigo.substr(10, 2);

    int n = stoi(NN);
    int p = stoi(PP);
    int a = stoi(AA);
    int h = stoi(HH);
    int m = stoi(MM);
    int s = stoi(SS);

    char letra_nombre = static_cast<char>(n);
    char letra_apellido_paterno = static_cast<char>(p);
    char letra_apellido_materno = static_cast<char>(a);

    if (h >= 9)
    {
        llego_tarde = 'V';
    }

    cout << "Hora de llegada: " << h << endl;
    cout << "Minuto de llegada: " << m << endl;
    cout << "Segundo de llegada: " << s << endl;
    cout << "Su nombre empieza con la letra: " << letra_nombre << endl;
    cout << "Su apellido paterno empieza con la letra: " << letra_apellido_paterno << endl;
    cout << "Su apellido materno empieza con la letra: " << letra_apellido_materno << endl;
    cout << "Llego tarde: " << llego_tarde << endl;
}
