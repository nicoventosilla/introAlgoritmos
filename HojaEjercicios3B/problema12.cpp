//
// Created by c0d3r on 03/09/2024.
//

#include "problema12.h"
#include <iostream>
#include <string>
#include <cctype> // islower, isupper
using namespace std;

char encriptarPrimerResultante(int primer_resultante)
{
    if (primer_resultante >= 1000 && primer_resultante <= 3000) return 'H';
    else if (primer_resultante >= 4000 && primer_resultante <= 6000) return 'X';
    else if (primer_resultante >= 7000 && primer_resultante <= 9000) return 'L';
    else return '#';
}

char encriptarSegundoResultante(int segundo_resultante)
{
    if (segundo_resultante >= 1000 && segundo_resultante <= 3000) return 'T';
    else if (segundo_resultante >= 4000 && segundo_resultante <= 6000) return 'W';
    else if (segundo_resultante >= 7000 && segundo_resultante <= 9000) return 'A';
    else return '&';
}

int encriptarArea(char area)
{
    // Verificar si es vocal mayuscula
    if (area == 'A' || area == 'E' || area == 'I' || area == 'O' || area == 'U') return 1001;
    // Verificar si es vocal minuscula
    else if (area == 'a' || area == 'e' || area == 'i' || area == 'o' || area == 'u') return 9009;
    // Verificar si es consonante minuscula
    else if (islower(area)) return 6009;
    // Verificar si es consonante mayuscula
    else if (isupper(area)) return 7007;
}

void problema12()
{
    string codigo_empleado;
    char area;

    cout << "Ingrese numero de 8 digitos: ";
    cin >> codigo_empleado;

    cout << "Ingrese area donde labora: ";
    cin >> area;

    string primer_resultante = codigo_empleado.substr(0, 4);
    string segundo_resultante = codigo_empleado.substr(4, 4);

    int primer_resultante_int = stoi(primer_resultante); // stoi: string to int
    int segundo_resultante_int = stoi(segundo_resultante);

    char primer_resultante_encriptado = encriptarPrimerResultante(primer_resultante_int);
    char segundo_resultante_encriptado = encriptarSegundoResultante(segundo_resultante_int);
    int area_encriptada = encriptarArea(area);

    cout << "Codigo encriptado: " << primer_resultante_encriptado;
    cout << segundo_resultante_encriptado;
    cout << area_encriptada << endl;
}
