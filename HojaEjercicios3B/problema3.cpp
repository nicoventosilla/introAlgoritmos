//
// Created by c0d3r on 29/08/2024.
//

#include "problema3.h"
#include <iostream>
using namespace std;

void problema3()
{
    string codigo, anio_ingreso, mes_ingreso, modalidad_admision, facultad, es_becado;

    cout << "*** BIEVENIDO LA A INSTITUCION EDUCATIVA 'SUENOS CUMPLIDOS' ***" << endl;
    cout << "Ingrese codigo de alumno: ";
    cin >> codigo;

    anio_ingreso = codigo.substr(0, 4);
    mes_ingreso = codigo.substr(4, 2);
    modalidad_admision = codigo.substr(6, 2);
    facultad = codigo.substr(8, 2);
    es_becado = codigo.substr(10, 1);

    modalidad_admision = modalidad_admision == "66" ? "E" : modalidad_admision == "77" ? "I" : "Modalidad no valida";

    facultad = facultad == "70" ? "C" : facultad == "72" ? "H" : "Facultad no valida";

    es_becado = es_becado == "1" ? "Si" : es_becado == "0" ? "No" : "Valor no valido";

    cout << "Anio de ingreso: " << anio_ingreso << endl;
    cout << "Mes de ingreso: " << mes_ingreso << endl;
    cout << "Modalidad de admision: " << modalidad_admision << endl;
    cout << "Facultad: " << facultad << endl;
    cout << "Es becado?: " << es_becado << endl;
}
