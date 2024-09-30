//
// Created by c0d3r on 29/08/2024.
//

#include "problema2.h"
#include <iostream>
#include <string>
using namespace std;

void problema2()
{
    string numero, P, R, C;

    cout << "Ingrese numero de 12 digitos: ";
    cin >> numero;

    P = numero.substr(0, 4);
    R = numero.substr(4, 4);
    C = numero.substr(8, 4);

    int num1 = stoi(P); // stoi convierte un string a un entero
    int num2 = stoi(R);
    int num3 = stoi(C);

    int mayor = (num1 > num2 && num1 > num3) ? num1 : (num2 > num3 ? num2 : num3);
    int menor = (num1 < num2 && num1 < num3) ? num1 : (num2 < num3 ? num2 : num3);
    int intermedio = (num1 != mayor && num1 != menor) ? num1 : (num2 != mayor && num2 != menor ? num2 : num3);

    cout << "El mayor es: " << mayor << endl;
    cout << "El menor es: " << menor << endl;
    cout << "El intermedio es: " << intermedio << endl;
}
